#pragma once
#include "gameObject.h"

class Controller : public GameObject {
public:

	enum {
		LEFT,
		RIGHT
	};

	int hand;	
	bool trigger_pressed = false;
	bool button_pressed = false;

	Controller(Shader* s, Model* model, int h) : GameObject(s, model, glm::vec3()) {
		hand = h;
		scale = glm::vec3(0.2, 0.2, 1.0f);
	}

	void update() {

	}

	void draw(glm::mat4 P, glm::mat4 V) {
		// Change lazer color
		shader->Use();
		if (trigger_pressed) glUniform1f(glGetUniformLocation(shader->Program, "flag"), 1.0f);
		else glUniform1f(glGetUniformLocation(shader->Program, "flag"), 0.0f);
		//Draw
		GameObject::draw(P, V);
	}


	glm::vec3 lazerStart() {
		return toWorld * glm::vec4(0, 0, 0, 1);
	}

	glm::vec3 lazerEnd() {
		glm::mat4 rotation_mat = glm::mat4();

		// Convert the rotation to a matrix - keep same as gameobject update
		rotation_mat = glm::rotate(rotation_mat, rotation.z, glm::vec3(0, 0, 1));
		rotation_mat = glm::rotate(rotation_mat, rotation.y, glm::vec3(0, 1, 0));
		rotation_mat = glm::rotate(rotation_mat, rotation.x, glm::vec3(1, 0, 0));

		glm::vec3 forward = rotation_mat * glm::vec4(0, 0, 1, 0); //Not sure if this should be a 1 or 0
		return lazerStart() -= lazer_length * forward;
	}

private:
	float lazer_length = 20.0f;

};