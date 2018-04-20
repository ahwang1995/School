#pragma once

#include "Node.h"
#include <vector>

// Represents a single particle and its state
struct Particle {
	glm::vec3 Position, Velocity;
	glm::vec4 Color;
	GLfloat Life, AngleY, AngleZ, cameraDistance;

	Particle() : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(0.0f), AngleY(0.0f), AngleZ(0.0f) { }

	bool operator<(Particle& that) {
		// Sort in reverse order : far particles drawn first.
		return this->cameraDistance > that.cameraDistance;
	}
};

class ParticleEmitter : public Node {
public:
	ParticleEmitter(GLuint shader, GLuint texture, GLuint amount);

	virtual void draw(glm::mat4 C);
	virtual void update(float dt);

private:
	// State
	std::vector<Particle> particles;
	GLuint amount;
	// Render state
	GLuint shader;
	GLuint texture;
	GLuint VAO;
	// Initializes buffer and vertex attributes
	void init();
	// Returns the first Particle index that's currently unused e.g. Life <= 0.0f or 0 if no particle is currently inactive
	GLuint firstUnusedParticle();
	// Respawns particle
	void ParticleEmitter::respawnParticle(Particle &particle, glm::vec3 offset = glm::vec3(0.0f, 0.0f, 0.0f));
};