#include "RiftApp.h"
#include "gameObject.h"
#include "factory.h"

// On some systems you need to change this to the absolute path
#define VERTEX_SHADER_PATH "./material_shader.vert"
#define FRAGMENT_SHADER_PATH "./material_shader.frag"
// List of gameObjects to update, render etc
vector<GameObject*> gameObjects;
Factory* obj_factory;
// Time of last frame
float lastFrame = 0.0f;


class Co2App : public RiftApp {

public:
	Co2App() { }

protected:
	Shader* shader;
	Model* factory;
	Controller* leftHand, *rightHand;

	void initGl() override {
		RiftApp::initGl();
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glEnable(GL_DEPTH_TEST);
		ovr_RecenterTrackingOrigin(_session);

		// Default shader
		shader = new Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
		Shader* lazer_shader = new Shader(VERTEX_SHADER_PATH, "./lazer_shader.frag");

		// Controller objects
		Model* lazer = new Model("../Assets/lazer/lazer.obj");
		leftHand = new Controller(lazer_shader, lazer, Controller::LEFT);
		gameObjects.push_back(leftHand);
		rightHand = new Controller(lazer_shader, lazer, Controller::RIGHT);
		gameObjects.push_back(rightHand);

		Model* co2 = new Model("../Assets/co2/co2.obj");
		Model* o2 = new Model("../Assets/o2/o2.obj");

		// Initialize all gameObjects and add them to the list
		factory = new Model("../Assets/factory3/factory3.obj");
		obj_factory = new Factory(shader, factory, co2, o2,leftHand,rightHand);

		obj_factory->scale = glm::vec3(0.01, 0.01, 0.01);
		obj_factory->position = glm::vec3(0.0f, -0.5f, -0.5f);
		gameObjects.push_back(obj_factory);

	}

	void touchControllers() override {

		double displayMidpointSeconds = ovr_GetPredictedDisplayTime(_session, frame);
		ovrTrackingState trackState = ovr_GetTrackingState(_session, displayMidpointSeconds, ovrTrue);

		// Left controller
		glm::quat LHorientation = ovr::toGlm(trackState.HandPoses[ovrHand_Left].ThePose.Orientation);
		glm::vec3 LHAngles = glm::vec3(glm::eulerAngles(LHorientation));
		leftHand->position = ovr::toGlm(trackState.HandPoses[ovrHand_Left].ThePose.Position);
		leftHand->rotation = LHAngles;

		// Right controller
		glm::quat RHorientation = ovr::toGlm(trackState.HandPoses[ovrHand_Right].ThePose.Orientation);
		glm::vec3 RHAngles = glm::vec3(glm::eulerAngles(RHorientation));
		rightHand->position = ovr::toGlm(trackState.HandPoses[ovrHand_Right].ThePose.Position);
		rightHand->rotation = RHAngles;
		
		// Buttons and triggers
		ovrInputState inputState;
		if (OVR_SUCCESS(ovr_GetInputState(_session, ovrControllerType_Touch, &inputState))) {

			if (inputState.IndexTrigger[ovrHand_Left] > 0.5f) {
				leftHand->trigger_pressed = true;
			}
			else {
				leftHand->trigger_pressed = false;
			}

			if (inputState.IndexTrigger[ovrHand_Right] > 0.5f) {
				rightHand->trigger_pressed = true;
			}
			else {
				rightHand->trigger_pressed = false;
			}
			if (inputState.Buttons & (ovrButton_A || ovrButton_B)){
				rightHand->button_pressed = true;
			}
			else {
				rightHand->button_pressed = false;
			}
			if (inputState.Buttons & (ovrButton_X || ovrButton_Y)) {
				leftHand->button_pressed = true;
			}
			else {
				leftHand->button_pressed = false;
			}
		}
		//set haptic feedback vibrations
		if (obj_factory->co2_hit) {
			ovr_SetControllerVibration(_session, ovrControllerType_LTouch, 0.0f, 1.0f);
			ovr_SetControllerVibration(_session, ovrControllerType_RTouch, 0.0f, 1.0f);
			obj_factory->co2_hit = false;
		}
		else {
			ovr_SetControllerVibration(_session, ovrControllerType_LTouch, 0.0f, 0.0f);
			ovr_SetControllerVibration(_session, ovrControllerType_RTouch, 0.0f, 0.0f);
		}

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

		//Check if won and set the screen color
		if (obj_factory->game_state == obj_factory->WIN) {
			glClearColor(0.0f / 255.0f, 191 / 255.0f, 1.0f, 0.0f);
		}
		else {
			glClearColor(25.0f/255.0f, 25.0f / 255.0f, 112.0f / 255.0f, 0.0f);
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

		for each (GameObject* obj in gameObjects) obj->draw(projection, glm::inverse(headPose));

	}
};