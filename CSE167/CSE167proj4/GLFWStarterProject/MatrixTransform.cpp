#include "MatrixTransform.h"
glm::mat4 M = glm::mat4(1.0f);
MatrixTransform::MatrixTransform(glm::mat4 T)
{
	M = T;
}
void MatrixTransform::draw(glm::mat4 C)
{
	Group::draw(C*M);
}