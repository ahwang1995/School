#ifndef ControlPoints_H
#define ControlPoints_H

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
#include "Geode.h"
using namespace std;
class ControlPoints : public Geode
{
public:
	ControlPoints(GLuint s, glm::vec3 c,float id);
	float ID;
	glm::vec3 cp;
	virtual void render(GLuint shaderProgram);
	virtual void update(glm::mat4 R);
	void editPoint(glm::vec3 point);
	// These variables are needed for the shader program
	GLuint CPVBO, CPVAO, CPEBO;
	GLuint CPuProjection, CPuModelview;
	std::vector<glm::vec3> CPvertices;
	std::vector<unsigned int> CPindices;
};
#endif