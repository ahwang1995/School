#ifndef BezierCurve_H
#define BezierCurve_H

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
class BezierCurve: public Geode
{
public:
	glm::vec3 curve;
	glm::vec3 cp0, cp1, cp2, cp3;
	int ID;
	BezierCurve(glm::vec3 p0, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3,GLuint s);
	void editPoint(glm::vec3 point,int a);
	virtual void render(GLuint shaderProgram);
	void calcVertices(float t,int index);
	virtual void update(glm::mat4 R);
	// These variables are needed for the shader program
	GLuint BezVBO, BezVAO, BezEBO;
	GLuint ControlVBO, ControlVAO, ControlEBO;
	GLuint ControlVBO2, ControlVAO2, ControlEBO2;
	GLuint HandleVBO, HandleVAO, HandleEBO;
	GLuint BezuProjection, BezuModelview;
	GLuint ControluProjection, ControluModelview;
	GLuint ControluProjection2, ControluModelview2;
	GLuint HandleuProjection, HandleuModelview;
	std::vector<glm::vec3> Bezvertices;
	std::vector<unsigned int> Bezindices;
	std::vector<glm::vec3> Controlvertices;
	std::vector<unsigned int> Controlindices;
	std::vector<glm::vec3> Controlvertices2;
	std::vector<unsigned int> Controlindices2;
	std::vector<glm::vec3> Handlevertices;
	std::vector<unsigned int> Handleindices;
};
#endif