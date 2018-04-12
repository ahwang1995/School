#pragma once

#include <vector>

#include <GL/glew.h> // Contains all the necessery OpenGL includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "model.h"
#include "shader.h"
#include "misc.h"

class GameObject {

public:
	// Position, rotation and scale in relation to parent object
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	// Dervided classes can use this constructer
	GameObject(Shader* s, Model* m, glm::vec3 pos);
	// The functionality of the game object, will be different for each derived class
	virtual void update(float deltaTime);
	// Call this on the root object with the identity matrix, and the time since the last update
	virtual void update(glm::mat4 M, float deltaTime);
	virtual void draw(glm::mat4 P, glm::mat4 V);
	void setShader(Shader* s);
	void setModel(Model* m);
	void setChild(GameObject* obj);
	void removeChild(GameObject* obj);
	// Returns if this object interects the 'other' object
	bool intersect(GameObject* other);
	// Returns if intersects the line between two points
	bool intersect(glm::vec3 x1, glm::vec3 x2);

protected:
	Shader* shader;
	Model* model;
	// References to the child objects
	// Should probs also ensure each object has max 1 parent, or weird behaviour might occur
	vector<GameObject*> children;
	// toWorld matrix
	glm::mat4 toWorld;
	// For collisions - can be set in the constructer of objects that need it
	float radius;
};