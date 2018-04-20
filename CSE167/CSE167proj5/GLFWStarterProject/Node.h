#pragma once

#include <glm/mat4x4.hpp>

#define GLFW_INCLUDE_GLEXT
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>

class Node {
public:
	virtual void draw(glm::mat4 C) = 0;
	virtual void update(float dt) = 0;
};