#ifndef OBJOBJECT_H
#define OBJOBJECT_H

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
using namespace std;

class OBJObject
{
private:

public:
	std::vector<unsigned int> indices;
	std::vector<glm::vec3> toScale;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> toMove;
	glm::mat4 matrix;
	void OBJObject::changecenter(int xyz, float avg);
	void OBJObject::changescale(int xyz, float longest);

	OBJObject(const char* filepath);
	glm::mat4 toWorld;
	void parse(const char* filepath);
	void draw(GLuint shaderProgram);
	void update();
	void moveObject(string letter);
	float OBJObject::center(int xyz);
	float OBJObject::scale(int xyz);
	GLuint VBO, VAO, EBO,lightVAO;
	GLuint uProjection, uModelview;
};

#endif