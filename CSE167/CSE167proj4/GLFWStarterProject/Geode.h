#ifndef Geode_H
#define Geode_H
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
#include "Node.h"
using namespace std;
class Geode :public Node
{
public:
	Geode();
	virtual void draw(glm::mat4 C);
	virtual void render(GLuint shaderProgram) = 0;
	glm::mat4 modelview;
	GLint shaderP;
};
#endif