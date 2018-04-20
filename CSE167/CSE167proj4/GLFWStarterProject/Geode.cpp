#include "Geode.h"
#include "../shader.h"
Geode::Geode()
{

}
void Geode::draw(glm::mat4 C)
{
	modelview = C;
	render(shaderP);
}