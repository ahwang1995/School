#pragma once

// GL Includes
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Geode.h"
#include "Node.h"
#include "MatrixTransform.h"

#include "../Window.h"
#include "MatrixTransform.h"
#include "City.h"
#include <SOIL.h>

class Car : public Node
{
public:
	GLuint shaderProgram, diffuse, specular;

	glm::vec3 Position;				//Location of the car
	float Angle;					//Angle that the car is facing in the XZ plane
	float Velocity;					//Current car speed
	Node* object;					//Object to draw

	float angularVelocity;

	//Const
	const float Drag = 0.2f;		//Deacceleration when key not pressed
	const float Break = 0.7f;			//Decceleration when back pressed
	const float Power = 0.5f;			//Acceleration when key pressed
	const float MaxSpeed = 0.4f;		//Max speed
	const float TurnSpeed = 3.0f;		//Speed of rotation

	Car(glm::vec3 Position, Node* object, GLuint shaderProgram, GLuint diffuse, GLuint specular, Node* boxobject,Node* particleobj);
	virtual void draw(glm::mat4 C);
	virtual void update(float dt);
	void processKeys(bool forward, bool back, bool left, bool right);

	bool left, right, forward, back;

	int Collision(std::vector<glm::vec3> itemPos, std::vector<glm::vec3> itemSize);
	Node* boxobject;
	Node* particleobj;
	glm::vec3 prevPosition;
	int prevbuild;

	//For the camera
	glm::vec3 getCamPos();
	glm::mat4 getView();
};