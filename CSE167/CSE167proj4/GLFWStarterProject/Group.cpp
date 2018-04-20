#include "Group.h"
vector<Node*> children;
Group::Group()
{

}
void Group::addChild(Node* node)
{
	children.push_back(node);
}
void Group::draw(glm::mat4 C)
{
	for (Node* node : children)
	{
		node->draw(C);
	}
}
void Group::update(glm::mat4 R)
{
	for (Node* node : children)
	{
		node->update(R);
	}
}