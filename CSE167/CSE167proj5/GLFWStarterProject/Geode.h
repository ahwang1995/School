#pragma once

#include "Node.h"

class Geode : public Node {
	public:
		virtual void render(GLuint) = 0;
		glm::mat4 modelview;
		void draw(glm::mat4 C);
		GLuint shaderProgram;
};