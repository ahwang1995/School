#ifndef OBJOBJECT_H
#define OBJOBJECT_H

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h> // Remove this line in future projects
#else
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
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

	OBJObject(const char* filepath);
	glm::mat4 toWorld;
	float angle;
	float zangle;
	bool boolO, boolo;
	void parse(const char* filepath);
	void draw();
	void update();
	void spin(float);
	void moveObject(string letter);
};

#endif