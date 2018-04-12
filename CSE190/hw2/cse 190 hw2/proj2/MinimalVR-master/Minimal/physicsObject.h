#pragma once

#include "gameObject.h"

class PhysicsObject : public GameObject {

public:

	glm::vec3 velocity;
	glm::vec3 acceleration;

	PhysicsObject(Shader* s, Model* m, glm::vec3 pos, float r) : GameObject(s, m, pos) {
		this->radius = r;
	}

	void update(glm::mat4 M, float deltaTime) {
		//First update physics
		velocity += acceleration * deltaTime;
		position += velocity * deltaTime;

		//Then call gameobject update
		GameObject::update(M, deltaTime);
	}
};