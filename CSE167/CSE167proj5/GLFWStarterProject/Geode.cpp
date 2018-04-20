#include "Geode.h"

glm::mat4 modelview;
GLuint shaderProgram;

void Geode::draw(glm::mat4 C) {
	modelview = C;
	render(shaderProgram);
}