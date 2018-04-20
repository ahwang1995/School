#ifndef _Sphere_H_
#define _Sphere_H_
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
class Sphere: public Geode
{
public:
	Sphere(GLint s);

	GLuint shaderP;
	virtual void render(GLuint shaderProgram);
	virtual void update(glm::mat4 R);
	void solidSphere(float radius, int stacks, int slices);
	//void spin(float);
	std::vector<glm::vec3> sphereVertices;
	std::vector<glm::vec3> sphereNormals;
	// These variables are needed for the shader program
	GLuint SVBO, SVAO, SNBO;
	GLuint SuProjection, SuModelview;
};
#endif