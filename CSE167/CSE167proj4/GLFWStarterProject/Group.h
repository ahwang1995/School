#ifndef Group_H
#define Group_H
#include "Node.h"
#include <vector>
using namespace std;
class Group :public Node
{
public:
	Group();
	void addChild(Node* node);
	virtual void draw(glm::mat4 C);
	vector<Node*> children;
	virtual void update(glm::mat4 R);
};
#endif