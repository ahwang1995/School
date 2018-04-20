#pragma once

#include "Node.h"
#include "BezierCurve.h"
#include "ControlPoint.h"
#include <list>

class RollerCoaster : public Node {
public:
	RollerCoaster(GLuint shaderProgram, GLuint reflectShader, GLuint cubemapTexture);
	BezierCurve* curves[10];
	virtual void draw(glm::mat4 C);
	virtual void update(float dt);
	glm::vec3 generatePoint(int i, int j);
	ControlPoint* controlPoints[10][4];
	void selectionDraw(GLuint shaderProgram);
	void adjustPoint(GLuint id, glm::vec3 direction);
	float maxHeight();
	void reset();
};
