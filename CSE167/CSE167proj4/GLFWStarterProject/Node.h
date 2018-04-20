#ifndef Node_H
#define Node_H
#define GLFW_INCLUDE_GLEXT
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>
// Use of degrees is deprecated. Use radians instead.
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Node
{
public:
	Node();
	virtual void draw(glm::mat4 C) = 0;
	virtual void update(glm::mat4 R) = 0;
	GLint pointshader;
};

#endif