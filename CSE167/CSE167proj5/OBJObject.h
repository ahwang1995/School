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
#include "Window.h"

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

class OBJObject : public Geode
{
private:
std::vector<unsigned int> indices;

float scale_factor = 1;

public:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;

	// These variables are needed for the shader program
	GLuint VBO, VAO, EBO;
	GLuint uProjection, uModel, uView, uColor;

	OBJObject(const char* filepath, GLuint shaderProgram);

	void parse(const char* filepath);
	virtual void render(GLuint shaderProgram);

	float mean(int ind, std::vector<glm::vec3> vertices);
	float maxAxis(int ind, std::vector<glm::vec3> vertices);

	virtual void update(float dt);
};

#endif