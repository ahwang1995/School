#pragma once

#include "misc.h"
#include "gameObject.h"
#include "physicsObject.h"
#include "Shader.h"
#include "Cube.h"
#include "material.h"

class Initialiser {

private:
	Model *gun_model, *head_model, *bullet_model, *ball_model, *house_model, *fence_model, *goal_model, *trophy_model, *play_model, *tree_model;
	Shader *material_shader, *model_shader;
	int ball_mat_num = 0;

public:
	Initialiser() {	
		gun_model = new Model("../../Assets/NERF_DartTagGun/NerfGun.obj");
		head_model = new Model("../../Assets/Bieber/BieberHead.obj");
		bullet_model = new Model("../../Assets/bullet.obj");
		ball_model = new Model("../../Assets/beachball.obj");
		house_model = new Model("../../Assets/HousF/houseF.obj");
		fence_model = new Model("../../Assets/Fence/Fence_White.obj");
		goal_model = new Model("../../Assets/Goal/Hockey Gates model.obj");
		trophy_model = new Model("../../Assets/trophy.obj");
		play_model = new Model("../../Assets/s-play.obj");
		tree_model = new Model("../../Assets/2D Trees.obj");
	}

	GameObject* init_gun_obj(Shader* shader) {
		GameObject* gun = new GameObject(shader, gun_model, glm::vec3());
		gun->scale = glm::vec3(0.0015, 0.0015, 0.0015);
		//gun->scale = glm::vec3(0.023, 0.023, 0.023);
		gun->rot_offset = glm::vec3(glm::radians(-90.0), glm::radians(180.0), 0);
		gun->pos_offset = glm::vec3(0.0f, -50.0f, -85.0f);
		gun->material = MatLib::ORANGE_PLASTIC;
		return gun;
	}

	GameObject* init_head_obj(Shader* shader) {
		GameObject* head = new GameObject(shader, head_model, glm::vec3());
		head->scale = glm::vec3(0.002, 0.002, 0.002);
		head->position = glm::vec3(0, -9999, 0);
		head->rot_offset = glm::vec3(glm::radians(10.0), glm::radians(180.0), 0);
		head->setRadius(1.0f); // Change bounding sphere here
		return head;
	}

	PhysicsObject* init_player1_bullet(Shader* shader) {
		PhysicsObject* bullet = new PhysicsObject(shader, bullet_model, glm::vec3(0, -9999, 0), 0.01f); // Change bounding sphere here
		bullet->scale = glm::vec3(0.025, 0.025, 0.025);
		bullet->rot_offset = glm::vec3(glm::radians(-90.0), 0, 0);
		bullet->material = MatLib::ORANGE_PLASTIC;
		return bullet;
	}

	PhysicsObject* init_player2_ball(Shader* shader) {
		PhysicsObject* ball = new PhysicsObject(shader, ball_model, glm::vec3(0, 9999, 0), 0.25f); // Change bounding sphere here
		ball->scale = glm::vec3(0.0025, 0.0025, 0.0025);
		switch (ball_mat_num) {
		case 0:
			ball->material = MatLib::CYAN_PLASTIC;
			break;
		case 1:
			ball->material = MatLib::RED_RUBBER;
			break;
		case 2:
			ball->material = MatLib::EMERALD;
			break;
		case 3:
			ball->material = MatLib::GOLD;
			break;
		case 4:
			ball->material = MatLib::CERAMIC;
			break;
		}
		ball_mat_num = (ball_mat_num + 1) % 5;
		return ball;
	}
	GameObject* init_env_obj(Shader* shader, Shader* matshader) {

		GameObject* env = new GameObject(NULL, NULL, glm::vec3());

		//initialise park
		//Add the park cube
		const int SIZEX = 100;	//Width and height of ground
		const int SIZEZ = 100;
		const int repeat = 50.0f;
		float parktexts[6] = { repeat,repeat,repeat,repeat,repeat,repeat };
		// Load texture and cube
		GLuint cube_texture = Misc::TextureFromFile("../../Assets/grass.ppm");
		Cube* park = new Cube(shader, cube_texture, glm::vec3(0, -2.3f, 10.0f), glm::vec3(SIZEX, 1.0f, SIZEZ), parktexts);
		env->setChild(park);

		//initialise house
		GameObject* house = new GameObject(shader, house_model, glm::vec3());
		house->scale = glm::vec3(4.0f, 4.0f, 4.0f);
		house->position = glm::vec3(0.0f, -2.0f, -24.0f);
		house->rotation = glm::vec3(0.0f, 0.0f, 0.0f);
		env->setChild(house);

		//initialise goal
		GameObject* goal = new GameObject(matshader, goal_model, glm::vec3());
		goal->scale = glm::vec3(0.0058, 0.003, 0.004);
		goal->position = glm::vec3(-2.1f, -2.0f, 2.0f);
		goal->rotation = glm::vec3(0.0f, glm::radians(180.0f), 0.0f);
		goal->material = MatLib::WHITE;
		env->setChild(goal);

		//initialise fences
		//Left
		GameObject* fence1 = create_fence(matshader);
		GameObject* fence2 = create_fence(matshader);
		fence2->position = glm::vec3(0, 0, -9.6f);
		GameObject* leftfence = new GameObject(NULL, NULL, glm::vec3());
		leftfence->position = glm::vec3(-4.0f, 0, 3.0f);
		leftfence->setChild(fence1);
		leftfence->setChild(fence2);
		//Right
		GameObject* fence3 = create_fence(matshader);
		GameObject* fence4 = create_fence(matshader);
		fence4->position = glm::vec3(0, 0, -9.6f);
		GameObject* rightfence = new GameObject(NULL, NULL, glm::vec3());
		rightfence->position = glm::vec3(8.0f, 0, 3.0f);
		rightfence->setChild(fence3);
		rightfence->setChild(fence4);

		env->setChild(leftfence);
		env->setChild(rightfence);

		env->position = glm::vec3(1.7f, -0.1f, 0.0f);

		//Add trees
		env->setChild(init_trees(shader, glm::vec3(12.0f, 0, -6.0f))); // Right
		env->setChild(init_trees(shader, glm::vec3(12.0f, 0, -12.0f)));
		env->setChild(init_trees(shader, glm::vec3(12.0f, 0, 6.0f)));
		env->setChild(init_trees(shader, glm::vec3(-12.0f, 0, -6.0f))); // Left
		env->setChild(init_trees(shader, glm::vec3(-12.0f, 0, -12.0f)));
		env->setChild(init_trees(shader, glm::vec3(-12.0f, 0, 6.0f)));
		env->setChild(init_trees(shader, glm::vec3(0.0f, 0, 12.0f))); // Back
		env->setChild(init_trees(shader, glm::vec3(7.0f, 0, 12.0f)));
		env->setChild(init_trees(shader, glm::vec3(-7.0f, 0, 12.0f)));
		return env;

	}

	GameObject* init_trees(Shader* shader, glm::vec3 pos) {
		GameObject* trees = new GameObject(shader, tree_model, glm::vec3());
		trees->pos_offset = glm::vec3(-3.0f, -0.66f, 3.0f);
		trees->scale = glm::vec3(3.0f, 3.0f, 3.0f);
		trees->position = pos;
		return trees;
	}

	GameObject* init_trophy(Shader* shader) {
		GameObject* trophy = new GameObject(shader, trophy_model, glm::vec3(0, -9999, 0));
		//if win/lose different poisitions
		trophy->material = MatLib::GOLD;
		trophy->scale = glm::vec3(0.0005, 0.0005, 0.0005);
		trophy->pos_offset = glm::vec3(-500, -1000, 0);
		return trophy;
	}

	GameObject* create_fence(Shader* matshader) {
		//initialise fence
		GameObject* fence = new GameObject(NULL, NULL, glm::vec3());
		//left
		GameObject* fenceA = new GameObject(matshader, fence_model, glm::vec3());
		fenceA->scale = glm::vec3(0.05f, 0.15f, 0.05f);
		fenceA->rotation = glm::vec3(0, 0, 0);
		fenceA->position = glm::vec3(-4.0f, -2.0f, 0.0f);
		fenceA->material = MatLib::RED_PLASTIC;
		fence->setChild(fenceA);
		//middle
		GameObject* fenceB = new GameObject(matshader, fence_model, glm::vec3());
		fenceB->scale = glm::vec3(0.05f, 0.15f, 0.05f);
		fenceB->rotation = glm::vec3(0, 0, 0);
		fenceB->position = glm::vec3(-4.0f, -2.0f, -4.8f);
		fenceB->material = MatLib::RED_PLASTIC;
		fence->setChild(fenceB);
		//right
		GameObject* fenceC = new GameObject(matshader, fence_model, glm::vec3());
		fenceC->scale = glm::vec3(0.05f, 0.15f, 0.05f);
		fenceC->rotation = glm::vec3(0, 0, 0);
		fenceC->position = glm::vec3(-4.0f, -2.0f, -9.6f);
		fenceC->material = MatLib::RED_PLASTIC;
		fence->setChild(fenceC);
		return fence;
	}

	GameObject* init_play_button(Shader* shader) {
		GameObject* play_button = new GameObject(shader, play_model, glm::vec3(2.0f, 0.0f, -3.0f));
		play_button->material = MatLib::EMERALD;
		play_button->pos_offset = glm::vec3(0.7f, -1.0f, 0.0f);
		play_button->rotation = glm::vec3(0.0f, -glm::radians(15.0f), 0.0f);
		play_button->radius = 0.5f;
		return play_button;
	}
};