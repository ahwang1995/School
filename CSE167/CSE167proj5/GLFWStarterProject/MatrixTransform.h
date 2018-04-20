#pragma once

#include "Group.h"

class MatrixTransform : public Group {
public:
	glm::mat4 M;
	virtual void draw(glm::mat4 C);
	MatrixTransform(glm::mat4 m);
	void changeMat(glm::mat4 m);
};