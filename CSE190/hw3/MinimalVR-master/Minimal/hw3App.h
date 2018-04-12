#pragma once

#include "RiftApp.h"
#include "gameObject.h"
#include "Cube.h"
#include "Skybox.h"

// On some systems you need to change this to the absolute path
#define VERTEX_SHADER_PATH "./model_shader.vert"
#define FRAGMENT_SHADER_PATH "./model_shader.frag"


class Hw3App : public RiftApp {

public:
	Hw3App() { }

	enum tracking_states {
		OFF,
		ORIENTATION_ONLY,
		POSITION_ONLY,
		ON
	};

	enum object_states {
		CUBE,
		SKYBOX,
		BOTH
	};

	int tracking_state = ON;
	int object_state = BOTH;

protected:
	Shader* shader, *skyshader;
	Skybox* skybox;
	// List of gameObjects to update, render etc
	vector<GameObject*> gameObjects;
	// Time of last frame
	float lastFrame = 0.0f;

	Cube* cube_obj;

	unsigned int prev_button_state;
	//glm::mat4 last_P;
	glm::mat4 last_pose[2];

	void initGl() override {
		RiftApp::initGl();
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glEnable(GL_DEPTH_TEST);
		ovr_RecenterTrackingOrigin(_session);

		// Default shader
		shader = new Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
		skyshader = new Shader("./skyshader.vert", "./skyshader.frag");

		// Load texture and cube
		GLuint cube_texture = Misc::TextureFromFile("../Assets/vr_test_pattern.ppm");
		cube_obj = new Cube(shader, cube_texture, glm::vec3(0.0, 0.0, -0.3), glm::vec3(0.2, 0.2, 0.2));

		// Skybox
		skybox = new Skybox(skyshader);

		gameObjects.push_back(cube_obj);
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
		//Touch controller stuff
		ovrInputState inputState;
		if (OVR_SUCCESS(ovr_GetInputState(_session, ovrControllerType_Touch, &inputState)))
		{
			// Right stick
			float vary_speed = 0.3f;
			if ((inputState.Thumbstick[ovrHand_Right].x) > 0.5f) {

			}
			if ((inputState.Thumbstick[ovrHand_Right].x) < -0.5f) {

			}
			//change view's when trigger is squeezed
			if (inputState.IndexTrigger[ovrHand_Right] > 0.5f) {

			}
			// right stick
			float resize_speed = 2.0f;
			if ((inputState.Thumbstick[ovrHand_Right].x) > 0.5 && cube_obj->scale.x < 1.0f) cube_obj->scale += glm::vec3(1.0f, 1.0f, 1.0f) * deltaTime * resize_speed;
			if ((inputState.Thumbstick[ovrHand_Right].x) < -0.5f && cube_obj->scale.x > 0.01f) cube_obj->scale -= glm::vec3(1.0f, 1.0f, 1.0f) * deltaTime * resize_speed;

			if (cube_obj->scale.x > 1.0f) cube_obj->scale = glm::vec3(1.0f, 1.0f, 1.0f);
			if (cube_obj->scale.x < 0.01f) cube_obj->scale = glm::vec3(0.01f, 0.01f, 0.01f);

			if ((inputState.Thumbstick[ovrHand_Right].y) > 0.5 && cube_obj->position.y < 10.0f) cube_obj->position += glm::vec3(0.0f, 1.0f, 0.0f) * deltaTime * resize_speed;
			if ((inputState.Thumbstick[ovrHand_Right].y) < -0.5f && cube_obj->position.y > -1.0f) cube_obj->position -= glm::vec3(0.0f, 1.0f, 0.0f) * deltaTime * resize_speed;



			//left stick
			if ((inputState.Thumbstick[ovrHand_Left].x) > 0.5 && cube_obj->position.x < 10.0f) cube_obj->position += glm::vec3(1.0f, 0.0f, 0.0f) * deltaTime * resize_speed;
			if ((inputState.Thumbstick[ovrHand_Left].x) < -0.5f && cube_obj->position.x > -1.0f) cube_obj->position -= glm::vec3(1.0f, 0.0f, 0.0f) * deltaTime * resize_speed;

			if ((inputState.Thumbstick[ovrHand_Left].y) > 0.5 && cube_obj->position.y < 10.0f) cube_obj->position += glm::vec3(0.0f, 0.0f, 1.0f) * deltaTime * resize_speed;
			if ((inputState.Thumbstick[ovrHand_Left].y) < -0.5f && cube_obj->position.y > -1.0f) cube_obj->position -= glm::vec3(0.0f, 0.0f, 1.0f) * deltaTime * resize_speed;
			if (inputState.IndexTrigger[ovrHand_Left] > 0.5f) {
			}
			if (inputState.Buttons > 0) {
				
				// Enable wireframe debugging
				if (inputState.Buttons == 1 && prev_button_state != 1) {
					wire_frame = (wire_frame + 1) % 2;
				}
				
				// Change render state when B is pressed
				if (inputState.Buttons == 2 && prev_button_state != 2) {
					freeze_state = (freeze_state + 1) % 2;
				}

				
				if (inputState.Buttons == 4 && prev_button_state != 4) {
				}

				if (inputState.Buttons == 1024 && prev_button_state != 1024) {
					cube_obj->scale = glm::vec3(0.2f, 0.2f, 0.2f);
				}

				// Change what is rendered
				if (inputState.Buttons == 256 && prev_button_state != 256) {
					view_state = (view_state + 1) % 3;
				}

				//cerr << "Botton state:" << inputState.Buttons << endl;
			}
			prev_button_state = inputState.Buttons;
			// cse190: no need to print the above messages
		}

		if (render_state == STEREO) {
			ovr::for_each_eye([&](ovrEyeType eye) {
				_viewScaleDesc.HmdToEyeOffset[eye].x = eye_offset[eye];
			});
		}
	}

	void renderScene(const glm::mat4 & projection, const glm::mat4 & headPose, ovrEyeType eye) override {		
		//Set up the light
		glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
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

		skybox->draw(projection, glm::inverse(headPose), eye, render_state == MONO, eye_offset[eye]);
		for each (GameObject* obj in gameObjects) obj->draw(projection, glm::inverse(headPose));
		//Misc::printMat(ovr::toGlm(trackState.HandPoses[ovrHand_Left].ThePose));
		/*glm::mat4 curr_pose[2];

		// Tracking modes
		switch (tracking_state) {
		case OFF:
			//Do nothing
			curr_pose[eye] = last_pose[eye];
			break;
		case ORIENTATION_ONLY:
			curr_pose[eye] = glm::mat4(headPose[0], headPose[1], headPose[2], last_pose[eye][3]);
			break;
		case POSITION_ONLY:
			curr_pose[eye] = glm::mat4(last_pose[eye][0], last_pose[eye][1], last_pose[eye][2], headPose[3]);
			break;
		case ON:
			last_pose[eye] = headPose;
			curr_pose[eye] = last_pose[eye];
			break;
		}

		switch (object_state) {
		case CUBE:
			for each (GameObject* obj in gameObjects) obj->draw(projection, glm::inverse(curr_pose[eye]));
			break;
		case SKYBOX:
			skybox->draw(projection, glm::inverse(curr_pose[eye]), eye, render_state == MONO, eye_offset[eye]);
			break;
		case BOTH:
			// First draw skybox
			skybox->draw(projection, glm::inverse(curr_pose[eye]), eye, render_state == MONO, eye_offset[eye]);
			for each (GameObject* obj in gameObjects) obj->draw(projection, glm::inverse(curr_pose[eye]));
			break;
		}*/

	}

};