#pragma once

#include "Geode.h"
#include "ControlPoint.h"

#include <vector>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

class BezierCurve: public Geode {
public:
	int id; //For selecting

	ControlPoint *p0, *p1, *p2, *p3;
	BezierCurve(GLuint sp, ControlPoint* p0, ControlPoint* p1, ControlPoint* p2, ControlPoint* p3);
	glm::vec3 cubicBezier(float t);
	float BezierCurve::bezier(float t, int ind);

	virtual void render(GLuint);
	virtual void update(float dt);

	std::vector<glm::vec3> vertices;
	void calcPoints();

	// These variables are needed for the shader program
	GLuint VBO, VAO, EBO;
	GLuint uProjection, uModelview, uColor;
	GLfloat trackColor[4] = { 0, 0, 0, 1 };

	//Bars
	GLuint barVAO, barVBO, barEBO;
	std::vector<glm::vec3> barVerts;
	std::vector<unsigned int> barInds = { 0, 1, 2, 3 };
	GLfloat barColor[4] = { 1, 1, 0, 1 };
};