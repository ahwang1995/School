#ifndef _BoundingBox_H_
#define _BoundingBox_H_
// Use of degrees is deprecated. Use radians instead.
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Geode.h"
#include "../Window.h"
class BoundingBox : public Geode 
{
public:
	BoundingBox(GLuint shaderProgram);
	void destroy();
	virtual void render(GLuint);
	virtual void update(float dt);
	GLuint VBO, VAO, EBO;
	GLuint uProjection, uModel, uView, uColor;
	bool boxcolor;
};
#endif