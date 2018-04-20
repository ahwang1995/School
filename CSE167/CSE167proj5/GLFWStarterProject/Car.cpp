#include "Car.h"

int car_state = 0; //STATE OF CAR: 0 IS NOT MOVING, 1 IS FORWARD, 2 IS REVERSE
float speedupvel = 2.0f;
float powerupLife;
Car::Car(glm::vec3 Position, Node* object, GLuint shaderProgram, GLuint diffuse, GLuint specular, Node* boxobject,Node* particleobj) {
	this->Position = Position;
	this->object = object;
	this->Angle = 0;
	this->Velocity = 0;
	this->shaderProgram = shaderProgram;
	this->diffuse = diffuse;
	this->specular = specular;
	this->boxobject = boxobject;
	this->particleobj = particleobj;
	prevbuild = 0;
	powerupLife = 0;
}

void Car::draw(glm::mat4 C) {
	//Position and rotate car
	float pi = 3.1415926535;
	MatrixTransform * rotate = new MatrixTransform(glm::rotate(glm::mat4(1.0f), -Angle, glm::vec3(0, 1, 0)));
	rotate->addChild(object);
	MatrixTransform * position = new MatrixTransform(glm::translate(glm::mat4(1.0f), this->Position));
	position->addChild(rotate);

	Window::setShaders(shaderProgram);
	glActiveTexture(GL_TEXTURE14);
	glBindTexture(GL_TEXTURE_2D, diffuse);
	glActiveTexture(GL_TEXTURE15);
	glBindTexture(GL_TEXTURE_2D, specular);

	position->draw(C);

	MatrixTransform * positionbox = new MatrixTransform(glm::translate(glm::mat4(1.0f), this->Position));
	position->addChild(rotate);
	positionbox->addChild(boxobject);
	if (Window::showboxes) positionbox->draw(C);
}

void Car::update(float dt) {
	object->update(dt);

	if (car_state == 0) {
		if (forward) car_state = 1;
		else if (back) car_state = 2;
		if (Velocity < 0) {
			Velocity = 0;
		}
	}
	else if (car_state == 1) {
		Velocity -= Drag * dt;
		if (forward) Velocity += Power * dt;
		if (back) Velocity -= Break * dt;
		if (Velocity > MaxSpeed) Velocity = MaxSpeed;
		if (Velocity < 0) {
			Velocity = 0;
			car_state = 0;
		}
	}
	else if (car_state == 2) {
		Velocity += Drag * dt;
		if (forward) car_state = 1;
		if (back) Velocity -= Power / 2 * dt;
		if (Velocity < -MaxSpeed / 3) Velocity = -MaxSpeed / 3;
		if (Velocity > 0) {
			Velocity = 0;
			car_state = 0;
		}
	}

	prevPosition = Position;
	int buildingcol = Collision(Window::boxPositions, Window::boxSizes);
	if (buildingcol == -1) {
		//Update position and angle
		if (powerupLife > 0)
		{
			Position += glm::vec3(speedupvel*Velocity * cos(Angle), 0.0f, speedupvel*Velocity * sin(Angle));
			powerupLife -= dt;
			if (powerupLife < 0)
				powerupLife = 0;
		}
		else
			Position += glm::vec3(Velocity * cos(Angle), 0.0f, Velocity * sin(Angle));
		//Update angle
		if (left) Angle -= TurnSpeed * dt;
		if (right) Angle += TurnSpeed * dt;
		Window::carBox->boxcolor = 0;
		Window::boxlist[prevbuild]->boxcolor = 0;
	}
	else
	{
		Position = prevPosition - 2.0f * glm::vec3(Velocity * cos(Angle), 0.0f, Velocity * sin(Angle));
		Velocity = 0;
		prevbuild = buildingcol;
		Window::boxlist[prevbuild]->boxcolor = 1;
		Window::carBox->boxcolor = 1;
	}
	int collisionLoc = Collision(Window::itemPositions, Window::itemSizes);
	if (collisionLoc != -1)
	{
		Window::itemPosition = Window::itemPositions[collisionLoc];
		Window::itemboundingboxes->removeChild(Window::itemboxes[collisionLoc]);
		Window::itemgroup->removeChild(Window::items[collisionLoc]);
		Window::items[collisionLoc]->destroy();
		Window::itemboxes[collisionLoc]->destroy();
		Window::itemPositions[collisionLoc] = glm::vec3(9999, 9999, 9999);
		Window::itemSizes[collisionLoc] = glm::vec3(0, 0, 0);
		Window::showparticles = true;
		Window::carBox->boxcolor = 1;

	}
	int speedcollisionloc = Collision(Window::speeditemPositions, Window::speeditemSizes);
	if (speedcollisionloc != -1)
	{
		Window::speeditemboundingboxes->removeChild(Window::speeditemboxes[speedcollisionloc]);
		Window::speeditemgroup->removeChild(Window::speeditems[speedcollisionloc]);
		Window::speeditems[speedcollisionloc]->destroy();
		Window::speeditemboxes[speedcollisionloc]->destroy();
		Window::speeditemPositions[speedcollisionloc] = glm::vec3(9999, 9999, 9999);
		Window::speeditemSizes[speedcollisionloc] = glm::vec3(0, 0, 0);
		Window::carBox->boxcolor = 1;
		powerupLife = 5.0;
	}
}

void Car::processKeys(bool forward, bool back, bool left, bool right) {
	this->forward = forward;
	this->back = back;
	this->left = left;
	this->right = right;
}

//check if the car Collides with other bounding boxes
int Car::Collision(std::vector<glm::vec3> itemPos, std::vector<glm::vec3> itemSize)
{
	bool collisionx = 0;
	//bool collisiony = 0;
	bool collisionz = 0;
	for (int i = 0; i < itemPos.size(); i++)
	{
		collisionx = (this->Position.x + Window::carSize.x >= itemPos[i].x) &&
			(itemPos[i].x + itemSize[i].x >= this->Position.x);
		//collisiony = (this->Position.y + Window::carSize.y >= Window::boxPositions[i].y) &&
			//(Window::boxPositions[i].y + Window::boxSizes[i].y >= this->Position.y);
		collisionz = (this->Position.z + Window::carSize.z >= itemPos[i].z) &&
			(itemPos[i].z + itemSize[i].z >= this->Position.z);
		if (collisionx && collisionz)
			return i;
	}
	return -1;
}


glm::vec3 Car::getCamPos() {
	return Position + glm::vec3(0, 50, 0);
}

glm::mat4 Car::getView() {
	return glm::lookAt(getCamPos(), Position, glm::vec3(0, 0, 1));
}