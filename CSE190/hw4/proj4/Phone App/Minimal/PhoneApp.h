#include "stdafx.h"
#include "ClientGame.h"
#include "RiftApp.h"
#include "gameObject.h"
#include "Cube.h"
#include "initialiser.h"
#include "physicsObject.h"
#include "SkyBox.h"

// On some systems you need to change this to the absolute path
#define VERTEX_SHADER_PATH "../../Shaders/material_shader.vert"
#define FRAGMENT_SHADER_PATH "../../Shaders/material_shader.frag"
// List of gameObjects to update, render etc
vector<GameObject*> gameObjects;
// Time of last frame
float lastFrame = 0.0f;
bool game_over = true;
int cur_ball = 0;
float throw_delay = 1.3f;
float throw_timer = 0.0f;

class PhoneApp : public RiftApp {

public:
	PhoneApp() { }

protected:
	Shader *shader, *skyshader, *model_shader;
	Skybox* skybox;
	GameObject *left_gun, *right_gun, *player1_head, *environment,*trophy, *play_button;
	ClientGame *client = new ClientGame();
	PhysicsObject *bullets[MAX_NUM_BULLETS];
	PhysicsObject *balls[MAX_NUM_BALLS];
	Initialiser* initialiser;
	
	int lives = NUM_LIVES;
	glm::vec3 initial_position = glm::vec3(0.0f, 0.0f, -9.0f);
	float initial_rotation = 180.0;
	GLfloat gameTimer = GAME_TIME;

	void initGl() override {
		RiftApp::initGl();
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glEnable(GL_DEPTH_TEST);
		ovr_RecenterTrackingOrigin(_session);

		// Default shader
		shader = new Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

		// Model shader
		model_shader = new Shader("../../Shaders/model_shader.vert", "../../Shaders/model_shader.frag");

		// sky shader
		skyshader = new Shader("../../Shaders/skyshader.vert", "../../Shaders/skyshader.frag");
		// Skybox
		skybox = new Skybox(skyshader);
		

		// Init game objects
		initialiser = new Initialiser();

		// Player 1
		left_gun = initialiser->init_gun_obj(shader);
		gameObjects.push_back(left_gun);

		right_gun = initialiser->init_gun_obj(shader);
		gameObjects.push_back(right_gun);

		// Player 2
		player1_head = initialiser->init_head_obj(model_shader);
		gameObjects.push_back(player1_head);

		//environment
		environment = initialiser->init_env_obj(model_shader, shader);
		gameObjects.push_back(environment);

		// Bullets
		for (int i = 0; i < MAX_NUM_BULLETS; i++) {
			bullets[i] = initialiser->init_player1_bullet(shader);
			gameObjects.push_back(bullets[i]);
		}

		// Balls
		for (int i = 0; i < MAX_NUM_BALLS; i++) {
			balls[i] = initialiser->init_player2_ball(shader);
			gameObjects.push_back(balls[i]);
		}

		// Trophy
		trophy = initialiser->init_trophy(shader);
		gameObjects.push_back(trophy);

		// Play button
		play_button = initialiser->init_play_button(shader);
		gameObjects.push_back(play_button);

		glfwSetCursorPos(window, _mirrorSize.x / 2, _mirrorSize.y / 2);
	}

	void touchControllers() override {

	}

	void shutdownGl() override {
	}

	void update() override {
		// Calculate deltatime of current frame
		GLfloat currentFrame = glfwGetTime();
		float deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		// Update each gameObject
		glm::mat4 toWorld;

		for each (GameObject* obj in gameObjects) obj->update(toWorld, deltaTime);

		//Networking!!
		// Create the data struct that will be sent to the client game
		Player2_Data player2_data;
		// Player 1 head
		double displayMidpointSeconds = ovr_GetPredictedDisplayTime(_session, frame);
		ovrTrackingState trackState = ovr_GetTrackingState(_session, displayMidpointSeconds, ovrTrue);
		glm::quat Horientation = ovr::toGlm(trackState.HeadPose.ThePose.Orientation);
		glm::vec3 HAngles = glm::vec3(glm::eulerAngles(Horientation));
		glm::vec3 HPosition = ovr::toGlm(trackState.HeadPose.ThePose.Position);
		// Player 2 head transform
		player2_data.player2_head_pos = initial_position;
		player2_data.player2_head_rot = glm::vec3(glm::radians(Pitch), -glm::radians(Yaw + 90), 0);
		// Balls
		for (int i = 0; i < MAX_NUM_BALLS; i++) {
			player2_data.ball_positions[i] = balls[i]->position;
		}
		// Send the data
		client->update(player2_data);

		// Update all objects player2
		// Player 1 head
		player1_head->position = client->player1_data.player1_head_pos;
		player1_head->rotation = client->player1_data.player1_head_rot;
		left_gun->position = client->player1_data.player1_left_pos;
		left_gun->rotation = client->player1_data.player1_left_rot;
		right_gun->position = client->player1_data.player1_right_pos;
		right_gun->rotation = client->player1_data.player1_right_rot;
		// Bullets
		for (int i = 0; i < MAX_NUM_BULLETS; i++) {
			bullets[i]->position = client->player1_data.bullet_positions[i];
			bullets[i]->rotation = client->player1_data.bullet_rotations[i];
		}

		// Check collisions
		for each(PhysicsObject* ball in balls) {
			for each(PhysicsObject* bullet in bullets) {
				if (ball->intersect(bullet)) {
					//Put the ball off screen!!
					resetBall(ball);
				}
			}

			//bouncing
			float X_LIMIT = 6;
			float Y_LIMIT = -1.8f;
			float Z_LIMIT = 2.0f;
			float HOUSE_LIMIT = -16.5f;
			if (ball->position.y < Y_LIMIT) {
				ball->velocity.y = -ball->velocity.y*0.8f;
				ball->position.y = Y_LIMIT;
			}
			if (ball->position.x < -X_LIMIT) {
				ball->velocity.x = -ball->velocity.x*0.8f;
				ball->position.x = -X_LIMIT;
			}
			if (ball->position.x > X_LIMIT - 0.5) {
				ball->velocity.x = -ball->velocity.x*0.8f;
				ball->position.x = X_LIMIT - 0.5;
			}
			if (ball->position.z > Z_LIMIT) {
				lives--;
				resetBall(ball);
				if (lives <= 0 && !game_over) {
					client->sendGameOver(0);
					trophy->position = glm::vec3(0, 0, TROPHY_PLAYER2_Z);
					game_over = true;
					play_button->position.y = 0;
				}
			}
			if (ball->position.z < HOUSE_LIMIT) {
				ball->velocity.z = -ball->velocity.z*0.8f;
				ball->position.z = HOUSE_LIMIT;
			}
		}

		if (gameTimer <= 0 && !game_over) {
			client->sendGameOver(1);
			trophy->position = glm::vec3(0, 0, TROPHY_PLAYER1_Z);
			game_over = true;
			play_button->position.y = 0;
		}

		gameTimer -= deltaTime;
		throw_timer += deltaTime;

		cursor_position_callback();
		check_keys(player2_data);

		if (client->start) {
			client->start = false;
			game_over = false;
			trophy->position = glm::vec3(0, -9999, 0);
			play_button->position.y = -9999;
			lives = NUM_LIVES;
			gameTimer = GAME_TIME;
		}
	}

	void resetBall(PhysicsObject* ball) {
		ball->position = glm::vec3(0, 9999, 0);
		ball->velocity = glm::vec3(0, 0, 0);
	}

	void renderScene(const glm::mat4 & projection, const glm::mat4 & headPose) override {
		//Set up the light
		glm::vec3 lightPos(0.0f, 5.0f, -9.0f);
		GLint lightPosLoc = glGetUniformLocation(shader->Program, "light.position");
		GLint viewPosLoc = glGetUniformLocation(shader->Program, "viewPos");
		glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
		glUniform3f(viewPosLoc, initial_position.x, initial_position.y, initial_position.z);

		GLint lightAmbientLoc = glGetUniformLocation(shader->Program, "light.ambient");
		GLint lightDiffuseLoc = glGetUniformLocation(shader->Program, "light.diffuse");
		GLint lightSpecularLoc = glGetUniformLocation(shader->Program, "light.specular");

		glUniform3f(lightAmbientLoc, 0.2f, 0.2f, 0.2f);
		glUniform3f(lightDiffuseLoc, 0.5f, 0.5f, 0.5f); // Let's darken the light a bit to fit the scene
		glUniform3f(lightSpecularLoc, 1.0f, 1.0f, 1.0f);
		skybox->draw(projection, GetViewMatrix(headPose[3][0]));
		for each (GameObject* obj in gameObjects) obj->draw(projection, GetViewMatrix(headPose[3][0]));
	}

	// Stuff for mouse movement below----------------------------------------------------------------------------------
	float Pitch = 0.0f;
	float Yaw = 90.0f;
	float MouseSensitivityX = 0.12f;
	float MouseSensitivityY = 0.45f;
	glm::vec3 Front, Right, Up;

	// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true)
	{
		xoffset *= this->MouseSensitivityX;
		yoffset *= this->MouseSensitivityY;

		this->Yaw += xoffset;
		this->Pitch += yoffset;

		// Make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (this->Pitch > 89.0f)
				this->Pitch = 89.0f;
			if (this->Pitch < -89.0f)
				this->Pitch = -89.0f;
		}

		// Update Front, Right and Up Vectors using the updated Eular angles
		// Calculate the new Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
		front.y = sin(glm::radians(this->Pitch));
		front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
		this->Front = glm::normalize(front);
		// Also re-calculate the Right and Up vector
		this->Right = glm::normalize(glm::cross(this->Front, glm::vec3(0, 1, 0)));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		this->Up = glm::normalize(glm::cross(this->Right, this->Front));
	}

	// Returns the view matrix calculated using Eular Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix(float offset)
	{
		return glm::lookAt(this->initial_position + glm::vec3(0, 0, offset), (this->initial_position + glm::vec3(0, 0, offset)) + this->Front, this->Up);
	}

	void cursor_position_callback()
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		GLfloat xoffset = xpos - (_mirrorSize.x / 2);
		GLfloat yoffset = (_mirrorSize.y / 2) - ypos;  // Reversed since y-coordinates go from bottom to left

		glfwSetCursorPos(window, _mirrorSize.x / 2, _mirrorSize.y / 2);

		ProcessMouseMovement(xoffset, yoffset);
	}
	//----------------------------------------------------------------------------------------------------

	void check_keys(Player2_Data player2_data) {
		if (glfwGetKey(window, GLFW_KEY_SPACE)) {
			// Throw balls!!
			if (throw_timer >= throw_delay /*&& !game_over*/) {
				throw_timer = 0;
				PhysicsObject* ball = balls[cur_ball];
				// Position
				ball->position = player2_data.player2_head_pos + glm::vec3(0, -0.5f, 0);
				// Rotation
				glm::mat4 rotation_mat = glm::mat4();
				rotation_mat = glm::rotate(rotation_mat, player2_data.player2_head_rot.z, glm::vec3(0, 0, 1));
				rotation_mat = glm::rotate(rotation_mat, player2_data.player2_head_rot.y, glm::vec3(0, 1, 0));
				rotation_mat = glm::rotate(rotation_mat, player2_data.player2_head_rot.x, glm::vec3(1, 0, 0));
				glm::vec3 forward = rotation_mat * glm::vec4(0, 0.5, -1, 0);
				ball->acceleration = glm::vec3(0, -1, 0); // Set gravity here
				ball->velocity = forward * 2.8f;
				cur_ball = (cur_ball + 1) % MAX_NUM_BALLS;
			}
		}
		if (glfwGetKey(window, GLFW_KEY_R)) {
			// Reset
			Pitch = 0.0f;
			Yaw = 90.0f;
		}
	}
};