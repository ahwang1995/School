#include "Group.h"

std::list<Node*> children;

void Group::addChild(Node* n)
{
	children.push_back(n);
}

void Group::removeChild(Node* n)
{
	children.remove(n);
}

void Group::draw(glm::mat4 C)
{
	for (Node* n : children)
	{
		n->draw(C);
	}
}

void Group::update(float dt)
{
	for (Node* n : children)
	{
		n->update(dt);
	}
}