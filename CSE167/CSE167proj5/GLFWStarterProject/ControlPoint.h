#pragma once

#include "Geode.h"

#include <vector>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

class ControlPoint : public Geode {
public:
	int id; //For selecting#pragma once

	ControlPoint(GLuint shaderProgram, int id, glm::vec3 location, GLfloat color[4]);

	virtual void render(GLuint);
	virtual void update(float dt);
	void selectionDraw(GLuint shaderProgram);

	void adjust(glm::vec3 direction);

	glm::vec3 location;

	std::vector<glm::vec3> vertices;

	// These variables are needed for the shader program
	GLuint VBO, VAO, EBO;
	GLuint uProjection, uModelview, uColor, uID;
	GLfloat color[4];
};
