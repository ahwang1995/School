#pragma once

#include "RiftApp.h"
#include "gameObject.h"
#include "Cube.h"

// On some systems you need to change this to the absolute path
#define VERTEX_SHADER_PATH "./model_shader.vert"
#define FRAGMENT_SHADER_PATH "./model_shader.frag"


class CubeApp : public RiftApp {

public:
	CubeApp() { }

	enum tracking_states {
		OFF,
		ORIENTATION_ONLY,
		POSITION_ONLY,
		ON
	};

	int tracking_state = ON;

protected:
	Shader* shader;
	// List of gameObjects to update, render etc
	vector<GameObject*> gameObjects;
	// Time of last frame
	float lastFrame = 0.0f;

	Cube* cube_obj;

	unsigned int prev_button_state;
	glm::mat4 last_P;
	glm::mat4 last_V;

	void initGl() override {
		RiftApp::initGl();
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glEnable(GL_DEPTH_TEST);
		ovr_RecenterTrackingOrigin(_session);

		// Default shader
		shader = new Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

		// Load texture and cube
		GLuint cube_texture = Misc::TextureFromFile("../Assets/vr_test_pattern.ppm");
		cube_obj = new Cube(shader, cube_texture, glm::vec3(0.0, 0.0,-0.3), glm::vec3(0.2, 0.2, 0.2));

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
			if (inputState.HandTrigger[ovrHand_Right] > 0.5f)   cerr << "right middle trigger pressed" << endl;
			if (inputState.IndexTrigger[ovrHand_Right] > 0.5f)	cerr << "right index trigger pressed" << endl;
			if (inputState.HandTrigger[ovrHand_Left] > 0.5f)    cerr << "left middle trigger pressed" << endl;
			if (inputState.IndexTrigger[ovrHand_Left] > 0.5f)	cerr << "left index trigger pressed" << endl;
			
			// TEST THIS SHIT
			// Right stick
			float vary_speed = 2.0f;
			if ((inputState.Thumbstick[ovrHand_Right].x) > 0.5f && eye_offset < 100) eye_offset += deltaTime * vary_speed;
			if ((inputState.Thumbstick[ovrHand_Right].x) < -0.5f && eye_offset > 0) eye_offset -= deltaTime * vary_speed;
			if (eye_offset > 100) eye_offset = 100;
			if (eye_offset < 0) eye_offset = 0;
			
			// Left stick
			float resize_speed = 2.0f;
			if ((inputState.Thumbstick[ovrHand_Left].x) > 0.5 && cube_obj->scale.x < 1.0f) cube_obj->scale += glm::vec3(1.0f,1.0f,1.0f) * deltaTime * resize_speed;
			if ((inputState.Thumbstick[ovrHand_Left].x) < -0.5f && cube_obj->scale.x > 0.01f) cube_obj->scale -= glm::vec3(1.0f, 1.0f, 1.0f) * deltaTime * resize_speed;
			if (cube_obj->scale.x > 1.0f) cube_obj->scale = glm::vec3(1.0f, 1.0f, 1.0f);
			if (cube_obj->scale.x < 0.01f) cube_obj->scale = glm::vec3(0.01f, 0.01f, 0.01f);

			if (inputState.Buttons > 0) {
				// Change render state when A is pressed
				if (inputState.Buttons == 1 && prev_button_state != 1) {
					render_state = (render_state + 1) % 4;
				}

				// Change render state when A is pressed
				if (inputState.Buttons == 2 && prev_button_state != 2) {
					tracking_state = (render_state + 1) % 4;
				}

				// TEST THIS -- CHANGE THIS NUMBERS
				if (inputState.Buttons == 69 && prev_button_state != 69) {
					eye_offset = eye_offset_default;
				}			
				if (inputState.Buttons == 666 && prev_button_state != 666) {
					cube_obj->scale = glm::vec3(0.3f, 0.3f, 0.3f);
				}
			}
			prev_button_state = inputState.Buttons;
			// cse190: no need to print the above messages
		}

		ovr::for_each_eye([&](ovrEyeType eye) {
			_viewScaleDesc.HmdToEyeOffset[eye].x = eye_offset;
		}
	}

	void renderScene(const glm::mat4 & projection, const glm::mat4 & headPose) override {
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

		for each (GameObject* obj in gameObjects) {
			switch (tracking_state) {
			case ORIENTATION_ONLY:
				last_V = glm::inverse(headPose);
				break;
			case POSITION_ONLY:
				last_P = projection;
				break;
			case ON:
				last_P = projection;
				last_V = glm::inverse(headPose);
				break;
			}
			obj->draw(last_P, last_V);
		}

	}

};