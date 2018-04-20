#ifndef Robot_H
#define Robot_H

#define GLFW_INCLUDE_GLEXT
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "Window.h"
using namespace std;

class Robot
{
private:

public:
	std::vector<unsigned int> indices;
	std::vector<glm::vec3> toScale;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> toMove;
	glm::mat4 matrix;

	Robot(const char* filepath);
	glm::mat4 toWorld;
	GLuint VBO, VAO, EBO, lightVAO;
	GLuint uProjection, uModelview;
};

#endif