#ifndef _CUBE_H_
#define _CUBE_H_

// Use of degrees is deprecated. Use radians instead.
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "GLFWStarterProject/Geode.h"

class Cube : public Geode
{
public:
	Cube(GLuint shaderProgram);
	void destroy();
	Cube(GLuint shaderProgram,float showside[6]);

	virtual void render(GLuint);
	virtual void update(float dt);

	// These variables are needed for the shader program
	GLuint VBO, VAO, EBO;
	GLuint uProjection, uModel, uView;
};


#endif

