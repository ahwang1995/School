#include "ParticleEmitter.h"
#include "../Window.h"

const GLuint newParticles = 100;
const int particleduration = 15;
const float partSize = 0.5;
ParticleEmitter::ParticleEmitter(GLuint shader, GLuint texture, GLuint amount) {
	this->shader = shader;
	this->texture = texture;
	this->amount = amount;
	init();
}

void ParticleEmitter::draw(glm::mat4 C) {
	// Use additive blending to give it a 'glow' effect
	//std::sort(&(this->particles)[0], &(this->particles)[this->amount]);
	glEnable(GL_BLEND); 
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glUseProgram(shader);
	for (Particle particle : this->particles)
	{
		if (particle.Life > 0.0f)
		{
			glActiveTexture(GL_TEXTURE13);
			glBindTexture(GL_TEXTURE_2D, texture);
			GLuint uProjection = glGetUniformLocation(shader, "projection");
			GLuint uModelview = glGetUniformLocation(shader, "modelview");
			GLuint uColor = glGetUniformLocation(shader, "color");
			GLuint uOffset = glGetUniformLocation(shader, "offset");
			GLuint uSprite = glGetUniformLocation(shader, "sprite");
			glUniform1i(uSprite, 13);
			glUniformMatrix4fv(uProjection, 1, GL_FALSE, &Window::P[0][0]);
			glUniformMatrix4fv(uModelview, 1, GL_FALSE, &C[0][0]);			
			glUniform4fv(uColor, 1, &(particle.Color[0]));
			glUniform3fv(uOffset, 1, &(particle.Position[0]));
			glBindTexture(GL_TEXTURE_2D, texture);
			glBindVertexArray(this->VAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
		}
	}
	// Don't forget to reset to default blending mode
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void ParticleEmitter::update(float dt) {
	// Test
	glm::vec3 offset(0.0f, 0.0f, 0.0f);
	// Add new particles 
	if (Window::showparticles)
	{
		for (GLuint i = 0; i < newParticles; ++i)
		{
			int unusedParticle = this->firstUnusedParticle();
			this->respawnParticle(this->particles[unusedParticle], offset);
		}
		if (Window::particletimer == particleduration)
		{
			Window::showparticles = false;
			Window::particletimer = 0;
		}
	}
	// Update all particles
	for (GLuint i = 0; i < this->amount; ++i)
	{
		Particle &p = this->particles[i];
		p.Life -= dt; // reduce life
		if (p.Life > 0.0f)
		{	// particle is alive, thus update
			p.Position -= p.Velocity * dt;
			p.Color.a -= dt * 1.5;
			p.cameraDistance = distance(p.Position, Window::getCamPos());
		}
		else {
			p.cameraDistance = -1.0;
		}
	}
}

void ParticleEmitter::init() {
	// Set up mesh and attribute properties
	GLuint VBO;
	GLfloat particle_quad[] = {
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};
	for (int i = 0; i < 24; i++)
	{
		particle_quad[i] = particle_quad[i] * partSize;
	}
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(this->VAO);
	// Fill mesh buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(particle_quad), particle_quad, GL_STATIC_DRAW);
	// Set mesh attributes
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glBindVertexArray(0);

	// Create this->amount default particle instances
	for (GLuint i = 0; i < this->amount; ++i) this->particles.push_back(Particle());
}

// Stores the index of the last particle used (for quick access to next dead particle)
GLuint lastUsedParticle = 0;
GLuint ParticleEmitter::firstUnusedParticle()
{
	// First search from last used particle, this will usually return almost instantly
	for (GLuint i = lastUsedParticle; i < this->amount; ++i) {
		if (this->particles[i].Life <= 0.0f) {
			lastUsedParticle = i;
			return i;
		}
	}
	// Otherwise, do a linear search
	for (GLuint i = 0; i < lastUsedParticle; ++i) {
		if (this->particles[i].Life <= 0.0f) {
			lastUsedParticle = i;
			return i;
		}
	}
	// All particles are taken, override the first one (note that if it repeatedly hits this case, more particles should be reserved)
	lastUsedParticle = 0;
	return 0;
}

void ParticleEmitter::respawnParticle(Particle &particle, glm::vec3 offset) {
	GLfloat randRange = 2.0f;
	GLfloat rColor = 0.5 + ((rand() % 100) / 100.0f);
	particle.Position =  offset;
	particle.Color = glm::vec4(rColor, rColor, rColor, 1.0f);
	particle.Life = 0.25f;
	float pi = 3.1415926535;
	float speed = 50;
	particle.AngleY = ((rand() % 360)/180.0f) * pi;
	particle.AngleZ = ((rand() % 360)/180.0f) * pi;
	float vx = speed * cos(particle.AngleY) * sin(particle.AngleZ);
	float vy = speed * cos(particle.AngleY) * cos(particle.AngleZ);
	float vz = speed * sin(particle.AngleY);
	particle.Velocity = glm::vec3(vx, vy, vz);	//Const velocity for now?
}
