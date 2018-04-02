#include "gameObject.h"

// Dervided classes can use this constructer
GameObject::GameObject(Shader* s, Model* m, glm::vec3 pos) {
	this->shader = s;
	this->model = m;
	this->position = pos;
	this->scale = glm::vec3(1, 1, 1);
}

// The functionality of the game object, will be different for each derived class
void GameObject::update(float deltaTime) {
	// Do nothing in the gameObject class - allows us to make objects with no functionality
	// e.g. scene objects
}

// Call this on the root object with the identity matrix, and the time since the last update
void GameObject::update(glm::mat4 M, float deltaTime) {
	glm::mat4 offset = glm::translate(glm::mat4(1.0f), pos_offset);
	offset = glm::rotate(offset, rot_offset.z, glm::vec3(0, 0, 1));
	offset = glm::rotate(offset, rot_offset.y, glm::vec3(0, 1, 0));
	offset = glm::rotate(offset, rot_offset.x, glm::vec3(1, 0, 0));

	// Update toWorld
	toWorld = glm::mat4();
	toWorld = glm::translate(M, position);
	toWorld = glm::rotate(toWorld, rotation.z, glm::vec3(0, 0, 1));
	toWorld = glm::rotate(toWorld, rotation.y, glm::vec3(0, 1, 0));
	toWorld = glm::rotate(toWorld, rotation.x, glm::vec3(1, 0, 0));
	toWorld = glm::scale(toWorld, scale);

	toWorld = toWorld * offset;

	// Call function that does functionality of object (must be overwritten by object class)
	this->update(deltaTime);

	// Call update on children
	for each(GameObject* child in children) child->update(toWorld, deltaTime);
}

void GameObject::draw(glm::mat4 P, glm::mat4 V) {
	if (model != NULL) {
		shader->Use();

		// If it has a material set tha up
		glUniform3f(glGetUniformLocation(shader->Program, "material.ambient"), material.ambient.x, material.ambient.y, material.ambient.z);
		glUniform3f(glGetUniformLocation(shader->Program, "material.diffuse"), material.diffuse.x, material.diffuse.y, material.diffuse.z);
		glUniform3f(glGetUniformLocation(shader->Program, "material.specular"), material.specular.x, material.specular.y, material.specular.z);
		glUniform1f(glGetUniformLocation(shader->Program, "material.shininess"), material.shininess);

		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "projection"), 1, GL_FALSE, &P[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "view"), 1, GL_FALSE, &V[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, &toWorld[0][0]);
		model->Draw(*shader);
	}
	// Draw children
	for each(GameObject* child in children) child->draw(P, V);
}

void GameObject::setShader(Shader* s) {
	this->shader = s;
}

void GameObject::setModel(Model* m) {
	this->model = m;
}

void GameObject::setChild(GameObject* obj) {
	if (!(std::find(children.begin(), children.end(), obj) != children.end())) children.push_back(obj);
}

// NEEDS TO BE TESTED
void GameObject::removeChild(GameObject* obj) {
	children.erase(std::remove(children.begin(), children.end(), obj), children.end());
}

// NEEDS TO BE TESTED
// Returns if this object interects the 'other' object
bool GameObject::intersect(GameObject* other) {
	// Check if distance between the two centers are smaller than the two radius's
	float distance = glm::length(position - other->position);
	return (distance < (radius + other->radius));
}

// Returns if intersects the line between two points - IN WORLD COORDS
bool GameObject::intersect(glm::vec3 x1, glm::vec3 x2) {
	glm::vec3 x0 = toWorld * glm::vec4(0, 0, 0, 1);
	return (glm::length(glm::cross(x2 - x1, x1 - x0)) / glm::length(x2 - x1)) < radius;
}

void GameObject::setRadius(float r) {
	this->radius = r;
}