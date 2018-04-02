#include "stdafx.h"
#include "ServerGame.h"
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


class OculusApp : public RiftApp {

public:
	OculusApp() { }

protected:
	Shader *shader, *skyshader, *model_shader;
	Skybox* skybox;
	GameObject *left_gun, *right_gun, *player2_head, *environment,*trophy, *play_button;
	ServerGame *server = new ServerGame();
	PhysicsObject *bullets[MAX_NUM_BULLETS];
	PhysicsObject *balls[MAX_NUM_BALLS];
	Initialiser* initialiser;
	bool game_over = true;

	bool trigger_pressed[2];
	int curr_bullet = 0;
	float shoot_delay = 0.3f;
	float shoot_timer[2];
	float hurt_delay = 1.0f;
	float hurt_timer = 0;

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
		player2_head = initialiser->init_head_obj(model_shader);
		gameObjects.push_back(player2_head);

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

		printf("x size: %d, y size: %d\n", _mirrorSize.x, _mirrorSize.y);
	}

	void touchControllers() override {

		double displayMidpointSeconds = ovr_GetPredictedDisplayTime(_session, frame);
		ovrTrackingState trackState = ovr_GetTrackingState(_session, displayMidpointSeconds, ovrTrue);

		// Left controller
		glm::quat LHorientation = ovr::toGlm(trackState.HandPoses[ovrHand_Left].ThePose.Orientation);
		glm::vec3 LHAngles = glm::vec3(glm::eulerAngles(LHorientation));
		glm::vec3 LHPosition = ovr::toGlm(trackState.HandPoses[ovrHand_Left].ThePose.Position);

		//show gun at left hand
		left_gun->position = LHPosition;
		left_gun->rotation = LHAngles;

		// Right controller
		glm::quat RHorientation = ovr::toGlm(trackState.HandPoses[ovrHand_Right].ThePose.Orientation);
		glm::vec3 RHAngles = glm::vec3(glm::eulerAngles(RHorientation));
		glm::vec3 RHPosition = ovr::toGlm(trackState.HandPoses[ovrHand_Right].ThePose.Position);

		// Buttons and triggers - get from project 2
		right_gun->position = RHPosition;
		right_gun->rotation = RHAngles;

		// Input
		ovrInputState inputState;
		if (OVR_SUCCESS(ovr_GetInputState(_session, ovrControllerType_Touch, &inputState)))
		{
			if (inputState.IndexTrigger[ovrHand_Left] > 0.5f) {
				trigger_pressed[0] = true;
			}
			else {
				trigger_pressed[0] = false;
			}

			if (inputState.IndexTrigger[ovrHand_Right] > 0.5f) {
				trigger_pressed[1] = true;
			}
			else {
				trigger_pressed[1] = false;
			}
		}
	}

	void shutdownGl() override {
	}

	void shootBullet(glm::vec3 pos, glm::vec3 rot, float deltaTime) {
		glm::mat4 rotation_mat = glm::mat4();
		rotation_mat = glm::rotate(rotation_mat, rot.z, glm::vec3(0, 0, 1));
		rotation_mat = glm::rotate(rotation_mat, rot.y, glm::vec3(0, 1, 0));
		rotation_mat = glm::rotate(rotation_mat, rot.x, glm::vec3(1, 0, 0));
		glm::vec3 forward = rotation_mat * glm::vec4(0, 0, -1, 0);

		PhysicsObject* bullet = bullets[curr_bullet];			//Add the offset
		bullet->position = pos + glm::vec3(rotation_mat * glm::vec4(-0.035f, 0.09f, 0.0f, 0.0f));
		bullet->rotation = rot;
		bullet->velocity = forward * 30.0f; // Set bullet speed here
		curr_bullet = (curr_bullet + 1) % MAX_NUM_BULLETS;
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
		Player1_Data player1_data;
		player1_data.player1_left_pos = left_gun->position;
		player1_data.player1_left_rot = left_gun->rotation;
		player1_data.player1_right_pos = right_gun->position;
		player1_data.player1_right_rot = right_gun->rotation;
		// Player 1 head
		double displayMidpointSeconds = ovr_GetPredictedDisplayTime(_session, frame);
		ovrTrackingState trackState = ovr_GetTrackingState(_session, displayMidpointSeconds, ovrTrue);
		glm::quat Horientation = ovr::toGlm(trackState.HeadPose.ThePose.Orientation);
		glm::vec3 HAngles = glm::vec3(glm::eulerAngles(Horientation));
		glm::vec3 HPosition = ovr::toGlm(trackState.HeadPose.ThePose.Position);
		// Buttons and triggers - get from project 2
		player1_data.player1_head_pos = HPosition;
		player1_data.player1_head_rot = HAngles;
		// Bullets
		for (int i = 0; i < MAX_NUM_BULLETS; i++) {
			player1_data.bullet_positions[i] = bullets[i]->position;
			player1_data.bullet_rotations[i] = bullets[i]->rotation;
		}
		// Send the data
		server->update(player1_data);

		if (server->player2_connected) {
			// Update player2
			player2_head->position = server->player2_data.player2_head_pos;
			player2_head->rotation = server->player2_data.player2_head_rot;

			// Balls
			for (int i = 0; i < MAX_NUM_BALLS; i++) {
				balls[i]->position = server->player2_data.ball_positions[i];
			}
		}

		//Shoot bullets!!!
		if (trigger_pressed[0] && shoot_timer[0] <= 0.0f) {
			shootBullet(left_gun->position, left_gun->rotation, deltaTime);
			shoot_timer[0] = shoot_delay;
		}
		if (trigger_pressed[1] && shoot_timer[1] <= 0.0f) {
			shootBullet(right_gun->position, right_gun->rotation, deltaTime);
			shoot_timer[1] = shoot_delay;
		}
		// Timers
		shoot_timer[0] -= deltaTime;
		shoot_timer[1] -= deltaTime;

		// Check if won or lost
		if (server->win && !game_over) {
			server->win = false;
			game_over = true;
			trophy->position = glm::vec3(0, 0, TROPHY_PLAYER1_Z);
			play_button->position.y = 0;
		}
		if (server->lose && !game_over) {
			server->lose = false;
			game_over = true;
			trophy->position = glm::vec3(0, 0, TROPHY_PLAYER2_Z);
			play_button->position.y = 0;
		}

		// Play button
		if (game_over) {
			// Collisions
			for each(PhysicsObject* bullet in bullets) {
				if (play_button->intersect(bullet)) {
					//Put the ball off screen!!
					play_button->position.y = -9999;
					game_over = false;
					server->sendStart();
					trophy->position = glm::vec3(0, -9999, 0);
				}
			}
		}

	}

	void renderScene(const glm::mat4 & projection, const glm::mat4 & headPose) override {
		//Set up the light
		glm::vec3 lightPos(0.0f, 5.0f, 0.0f);
		GLint lightPosLoc = glGetUniformLocation(shader->Program, "light.position");
		GLint viewPosLoc = glGetUniformLocation(shader->Program, "viewPos");
		glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
		glUniform3f(viewPosLoc, headPose[3][0], headPose[3][1], headPose[3][2]);

		GLint lightAmbientLoc = glGetUniformLocation(shader->Program, "light.ambient");
		GLint lightDiffuseLoc = glGetUniformLocation(shader->Program, "light.diffuse");
		GLint lightSpecularLoc = glGetUniformLocation(shader->Program, "light.specular");

		glUniform3f(lightAmbientLoc, 0.2f, 0.2f, 0.2f);
		glUniform3f(lightDiffuseLoc, 0.5f, 0.5f, 0.5f); // Let's darken the light a bit to fit the scene
		glUniform3f(lightSpecularLoc, 1.0f, 1.0f, 1.0f);
		skybox->draw(projection, glm::inverse(headPose));
		for each (GameObject* obj in gameObjects) obj->draw(projection, glm::inverse(headPose));
	}
};