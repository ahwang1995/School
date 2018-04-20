#include "MatrixTransform.h"

glm::mat4 M;

MatrixTransform::MatrixTransform(glm::mat4 m) {
	M = m;
}

void MatrixTransform::changeMat(glm::mat4 m) {
	M = m;
}

void MatrixTransform::draw(glm::mat4 C) {
	Group::draw(C * M);
}