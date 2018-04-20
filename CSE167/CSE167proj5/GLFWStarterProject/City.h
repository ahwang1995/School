#pragma once

#include "Node.h"
#include "Group.h"
#include "../Cube.h"
#include "../shader.h"
#include "MatrixTransform.h"
#include "../Window.h"
#include "BoundingBox.h"

class City : public Node {
public:
	City(GLuint sp, GLuint roadsp, GLuint groundsp, GLuint storesp, GLuint housesp, GLuint parksp,GLuint carsp,GLuint cratesp,GLuint speeditemsp);
	GLuint shaderProgram;
	virtual void draw(glm::mat4 C);
	virtual void update(float dt);
	void generate();
	void placeRoad(int x, int z);
	void placeSkyscraper(int x, int z);
	void placespeedItem(int x, int z, int xOff, int zOff);
	void clear();
	void placeStore(int x, int z);
	void placeHouse(int x, int z);
	void placeItem(int x, int z,int xOff, int zOff);
	bool overlap(glm::vec2 amin, glm::vec2 amax, glm::vec2 bmin, glm::vec2 bmax);
};