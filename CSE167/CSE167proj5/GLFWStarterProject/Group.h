#pragma once

#include "Node.h"
#include <list>

class Group : public Node {
public:
	std::list<Node*> children;
	void addChild(Node*);
	void removeChild(Node*);
	virtual void draw(glm::mat4 C);
	virtual void update(float dt);
};