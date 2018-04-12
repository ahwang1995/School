#pragma once

#include "gameObject.h"
#include "controller.h"
#include "CO2.h"
#include <time.h>       // for random seed

class Factory : public GameObject {

public:

	int game_state = PLAY;
	bool co2_hit = false;

	enum game_states {
		PLAY,
		WIN,
		LOSE
	};

	Factory(Shader* s, Model* m, Model* co2, Model* o2, Controller* lh, Controller* rh) : GameObject(s, m, glm::vec3()) {
		co2_model = co2;
		o2_model = o2;
		shader = s;

		leftHand = lh;
		rightHand = rh;

		// initialize random seed
		srand(time(NULL));

		start_game();
	}

	// Functionality
	void update(float deltaTime) {

		if (game_state == PLAY) {
			//Generate particles
			counter_value -= deltaTime;
			if (counter_value <= 0) {
				counter_value = counter_length;
				spawn_co2(glm::vec3(0, 0, 0));
			}

			//Check how many carbon atoms exist
			int co2_count = 0;
			for each(GameObject* c in children) {
				if (!((CO2*)c)->hit) co2_count++;
			}
			if (co2_count > 10) {
				game_state = LOSE;
				// Generate 100 particles
				for (int i = 0; i < 1000; i++) {
					spawn_co2(glm::vec3(Misc::random(-bounds_size, bounds_size),
						Misc::random(-bounds_size, bounds_size),
						Misc::random(-bounds_size, bounds_size)));;
				}
			}
			if (co2_count == 0) {
				game_state = WIN;
			}

			if (leftHand->trigger_pressed && rightHand->trigger_pressed) {
				for each(GameObject* c in children) {
					if (c->intersect(leftHand->lazerStart(), leftHand->lazerEnd())
						&& c->intersect(rightHand->lazerStart(), rightHand->lazerEnd())){
						((CO2*)c)->hit = true;
						co2_hit = true;
					}
				}
			}

		}

		else {
			if (leftHand->button_pressed || rightHand->button_pressed) start_game();
		}

	}

private:
	Model* co2_model;
	Model* o2_model;
	Shader* shader;
	Controller* leftHand, *rightHand;
	//Emit every 1 second
	float counter_length = 1.0f;
	float counter_value = counter_length;

	void spawn_co2(glm::vec3 pos) {
		CO2* co2_obj = new CO2(shader, co2_model, o2_model, 0.02f); //May need to change this radius
		co2_obj->position = pos;
		co2_obj->scale = glm::vec3(2.0f, 2.0f, 2.0f);
		setChild(co2_obj);
	}

	void start_game() {
		// Remove previous particles and generate 5
		children.clear();
		for (int i = 0; i < 5; i++) {
			spawn_co2(glm::vec3(Misc::random(-bounds_size, bounds_size),
				Misc::random(-bounds_size, bounds_size),
				Misc::random(-bounds_size, bounds_size)));
		}
		game_state = PLAY;
	}
};