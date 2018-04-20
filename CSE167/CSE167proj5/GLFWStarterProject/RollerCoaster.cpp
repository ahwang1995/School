#include "RollerCoaster.h"
#include "ControlPoint.h"
#include "Sphere.h"
#include "MatrixTransform.h"
#include <iostream>
# define PI           3.14159265358979323846  /* pi */

float radius = 10;
float height = 8;

//Colours
GLfloat interpPointColor[4] = { 1, 0, 0, 1 };
GLfloat approxPointColor[4] = { 0, 1, 0, 1 };

MatrixTransform* podPosition;
MatrixTransform* podRotation;
int currCurve = 0;
float currT = 0;
float currH = 0;
float step = 0.01;
glm::vec3 currPos(0, 0, 0);

RollerCoaster::RollerCoaster(GLuint shaderProgram, GLuint reflectShader, GLuint cubemapTexture) {
	//Define default 10 curves
	//Start with all control points and then make the end points the mid points!
	//Need 10 * 2 control points
	glm::vec3 ctrlPoints[10][2];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			ctrlPoints[i][j] = generatePoint(i, j);
		}
	}
	//Now create all the curves, with the end points as the mid points
	for (int i = 0; i < 10; i++) {
		glm::vec3 start = (ctrlPoints[(i + 9) % 10][1] + ctrlPoints[i][0]) / 2.0f;
		glm::vec3 end = (ctrlPoints[(i + 1) % 10][0] + ctrlPoints[i][1]) / 2.0f;

		ControlPoint* p0 = new ControlPoint(shaderProgram, i * 10 + 1, start, interpPointColor);
		ControlPoint* p1 = new ControlPoint(shaderProgram, i * 10 + 2, ctrlPoints[i][0], approxPointColor);
		ControlPoint* p2 = new ControlPoint(shaderProgram, i * 10 + 3, ctrlPoints[i][1], approxPointColor);
		ControlPoint* p3 = new ControlPoint(shaderProgram, i * 10 + 4, end, interpPointColor);

		curves[i] = new BezierCurve(shaderProgram, p0, p1, p2, p3);
		
		controlPoints[i][0] = p0;
		controlPoints[i][1] = p1;
		controlPoints[i][2] = p2;
		controlPoints[i][3] = p3;
	}

	Sphere* pod = new Sphere(reflectShader, cubemapTexture);
	MatrixTransform* podScale = new MatrixTransform(glm::	scale(glm::mat4(1.0f), glm::vec3(0.5, 0.5, 0.5)));
	podScale->addChild(pod);

	//Position at highest point
	//Find highest point
	reset();

	podRotation = new MatrixTransform(glm::mat4(1.0f));
	podRotation->addChild(podScale);
	podPosition = new MatrixTransform(glm::translate(glm::mat4(1.0f), currPos));
	podPosition->addChild(podRotation);
}

glm::vec3 RollerCoaster::generatePoint(int i, int j) {
	float angle = i * (360 / 10); //Angle
	if (j) angle += 360 / 20;
	return glm::vec3(radius * cos(angle * PI / 180), //X
		(rand() % (int)height) - (height / 2), //Y - random height
		radius * sin(angle * PI / 180)); //Z
}

void RollerCoaster::draw(glm::mat4 C) {
	//Draw each curve
	for (BezierCurve* c : curves) {
		c->draw(C);
	}
	//Control points
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			controlPoints[i][j]->draw(C);
		}
	}
	//Pod
	podPosition->draw(C);
}

float RollerCoaster::maxHeight() {
	glm::vec3 hpos(0, -1000, 0);
	for (int i = 0; i < 10; i++) {
		for (float t = 0; t < 1; t += step) {
			glm::vec3 pos = (curves[i]->cubicBezier(t));
			if (pos.y > hpos.y) {
				hpos = pos;
			}
		}
	}
	return hpos.y;
}

void RollerCoaster::update(float dt) {
	//Update each curve
	for (BezierCurve* c : curves) {
		c->update(dt);
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			controlPoints[i][j]->update(dt);
		}
	}

	//Move the pod
	//Calc velocity
	float acc = -0.000001;
	float c = 0.0001;
	float velocity = sqrtf(-2.0f * acc * abs(maxHeight() - currH)) + c;
	//Find next position
	currT += velocity;
	if (currT >= 1.0f) {
		currT = 0.0f;
		currCurve = (currCurve + 1) % 10;
	}
	else if (currT <= 0.0f) {
		currT = 1.0f;
		currCurve = (currCurve + 9) % 10;
	}
	glm::vec3 newPos = curves[currCurve]->cubicBezier(currT);
	currH = newPos.y;
	podPosition->changeMat(glm::translate(glm::mat4(1.0f),newPos));

	//Work out the pod's rotation
	glm::vec3 dir = newPos - currPos; //Not sure how to do this?

	//Update position
	currPos = newPos;
}

void RollerCoaster::selectionDraw(GLuint shaderProgram) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			controlPoints[i][j]->selectionDraw(shaderProgram);
		}
	}
}

void RollerCoaster::adjustPoint(GLuint id, glm::vec3 direction) {
	//Get point with given id
	int i = (id / 10);
	int j = ((id-1) % 10);
	if (j < 0 || j > 3 || i < 0 || i > 9) return;
	//Adjust point
	controlPoints[i][j]->adjust(direction);
	//Adjust surrounding points
	if (j == 0) {
		//Equiv mid point
		controlPoints[(i + 9) % 10][3]->adjust(direction);
		//Approx points
		controlPoints[(i + 9) % 10][2]->adjust(direction);
		controlPoints[i][1]->adjust(direction);
	}
	else if (j == 3) {
		//Equiv mid point
		controlPoints[(i + 1) % 10][0]->adjust(direction);
		//Approx points
		controlPoints[(i + 1) % 10][1]->adjust(direction);
		controlPoints[i][2]->adjust(direction);
	}
	else if (j == 1) {
		//Calc new mid point for the mid control points
		glm::vec3 newMid = (controlPoints[i][1]->location + controlPoints[(i + 9) % 10][2]->location) / 2.0f;
		glm::vec3 diff = newMid - controlPoints[i][0]->location;
		controlPoints[i][0]->adjust(diff);
		controlPoints[(i + 9) % 10][3]->adjust(diff);
	}
	else if (j == 2) {
		//Calc new mid point for the mid control points
		glm::vec3 newMid = (controlPoints[i][2]->location + controlPoints[(i + 1) % 10][1]->location) / 2.0f;
		glm::vec3 diff = newMid - controlPoints[i][3]->location;
		controlPoints[i][3]->adjust(diff);
		controlPoints[(i + 1) % 10][0]->adjust(diff);
	}
	//Update curves
	curves[i]->calcPoints();
	curves[(i + 1) % 10]->calcPoints();
	curves[(i + 9) % 10]->calcPoints();
}

void RollerCoaster::reset() {
	glm::vec3 hpos(0, -1000, 0);
	int hi = -1;
	float ht = -1;
	for (int i = 0; i < 10; i++) {
		for (float t = 0; t < 1; t += step) {
			glm::vec3 pos = (curves[i]->cubicBezier(t));
			if (pos.y > hpos.y) {
				hpos = pos;
				ht = t;
				hi = i;
			}
		}
	}
	currCurve = hi;
	currT = ht;
	currH = hpos.y;
	currPos = hpos;
}