#pragma once

#include "physicsObject.h"

#include "misc.h"

static const float bounds_size = 50.f;

class CO2 : public PhysicsObject {

private:
	glm::vec3 spin_axis;
	glm::mat4 spin_mat;
	float spin_speed;

	Model* CO2_model;
	Model* O2_model;

public:
	bool hit = false;

	CO2(Shader* s, Model* co2, Model* o2, float r) : PhysicsObject(s, co2, glm::vec3(), r) {
		// Store models
		CO2_model = co2;
		O2_model = o2;

		// Scale down
		// scale = glm::vec3(0.5, 0.5, 0.5);

		// Set initial random velocity and spin
		velocity = glm::vec3(Misc::random(-1, 1), Misc::random(0, 1), Misc::random(-1, 1));
		velocity *= 2;
		spin_axis = glm::vec3(Misc::random(-1, 1), Misc::random(-1, 1), Misc::random(-1, 1));
		spin_axis = glm::normalize(spin_axis);
		spin_speed = Misc::random(0.5, 1.5);
	}

	// Functionality, check collisions with beams etc
	void update(float deltaTime) {
		spin_mat = glm::rotate(spin_mat, spin_speed * deltaTime, spin_axis);
		toWorld = toWorld * spin_mat;

		// Check if out of bounds
		if (position.x > bounds_size || position.x < -bounds_size) {
			velocity.x = -velocity.x;
		}
		if (position.y > bounds_size || position.y < -bounds_size) {
			velocity.y = -velocity.y;
		}
		if (position.z > bounds_size || position.z < -bounds_size) {
			velocity.z = -velocity.z;
		}

		// Check intersections with beams
		if (hit) {
			model = O2_model;
		}
		else {
			model = CO2_model;
		}

	}

};