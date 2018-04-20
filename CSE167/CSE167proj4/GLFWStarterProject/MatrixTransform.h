#ifndef MatrixTransform_H
#define MatrixTransform_H
#include "Group.h"

class MatrixTransform :public Group
{
public:
	MatrixTransform(glm::mat4 T);
	glm::mat4 M;
	virtual void draw(glm::mat4 C);
};
#endif