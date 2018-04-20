#pragma once

// Use of degrees is deprecated. Use radians instead.
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "Geode.h"

class Sphere : public Geode
{
public:
	Sphere(GLuint shaderProgram, GLuint texture);
	~Sphere();

	virtual void render(GLuint);
	virtual void update(float dt);

	// These variables are needed for the shader program
	GLuint VBO, VAO, NBO;
	GLuint uProjection, uModelview;

	std::vector<glm::vec3> sphereVertices;
	std::vector<glm::vec3> sphereNormals;
};

