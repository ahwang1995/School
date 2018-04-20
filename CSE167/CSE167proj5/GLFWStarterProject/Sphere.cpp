#include "Sphere.h"
#include "../Window.h"

int prevStacks = 0;
int prevSlices = 0;

GLuint texture = 0;

Sphere::Sphere(GLuint sp, GLuint t)
{
	shaderProgram = sp;
	texture = t;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &NBO);

	glBindVertexArray(VAO);

	// Bind vertices to layout location 0
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 0, 0, GL_STATIC_DRAW); // Don't give it any data
	glEnableVertexAttribArray(0); // This allows usage of layout location 0 in the vertex shader
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	// Bind normals to layout location 1
	glBindBuffer(GL_ARRAY_BUFFER, NBO);
	glBufferData(GL_ARRAY_BUFFER, 0, 0, GL_STATIC_DRAW); // Don't give it any data
	glEnableVertexAttribArray(1); // This allows usage of layout location 1 in the vertex shader
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Sphere::~Sphere()
{

}

void Sphere::render(GLuint shaderProgram)
{
	float radius = 1;
	int stacks = 20;
	int slices = 20;

	double pi = 3.1415926535;

	// No need to generate the sphere again if the previous rendering already
	// used the same number of stacks and slices
	if (prevStacks != stacks || prevSlices != slices) {
		prevStacks = stacks; prevSlices = slices;
		sphereVertices.clear();
		sphereNormals.clear();
		float fstacks = (float)stacks;
		float fslices = (float)slices;
		for (int i = 0; i < slices; i++) {
			for (int j = 0; j < stacks; j++) {
				// Top left
				sphereVertices.push_back(glm::vec3(
					radius * -cos(2.0f * pi * i / fstacks) * sin(pi * (j + 1.0f) / fslices),
					radius * -cos(pi * (j + 1.0f) / fslices),
					radius * sin(2.0f * pi * i / fstacks) * sin(pi * (j + 1.0f) / fslices)));
				sphereNormals.push_back(glm::normalize(glm::vec3(
					-cos(2.0f * pi * i / fstacks) * sin(pi * (j + 1.0f) / fslices),
					-cos(pi * (j + 1.0f) / fslices),
					sin(2.0f * pi * i / fstacks) * sin(pi * (j + 1.0f) / fslices))));
				// Top right
				sphereVertices.push_back(glm::vec3(
					radius * -cos(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * (j + 1.0) / fslices),
					radius * -cos(pi * (j + 1.0) / fslices),
					radius * sin(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * (j + 1.0) / fslices)));
				sphereNormals.push_back(glm::normalize(glm::vec3(
					-cos(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * (j + 1.0) / fslices),
					-cos(pi * (j + 1.0) / fslices),
					sin(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * (j + 1.0) / fslices))));
				// Bottom right
				sphereVertices.push_back(glm::vec3(
					radius * -cos(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * j / fslices),
					radius * -cos(pi * j / fslices),
					radius * sin(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * j / fslices)));
				sphereNormals.push_back(glm::normalize(glm::vec3(
					-cos(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * j / fslices),
					-cos(pi * j / fslices),
					sin(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * j / fslices))));

				// Need to repeat 2 of the vertices since we can only draw triangles. Eliminates the confusion
				// of array indices.
				// Top left
				sphereVertices.push_back(glm::vec3(
					radius * -cos(2.0f * pi * i / fstacks) * sin(pi * (j + 1.0f) / fslices),
					radius * -cos(pi * (j + 1.0f) / fslices),
					radius * sin(2.0f * pi * i / fstacks) * sin(pi * (j + 1.0f) / fslices)));
				sphereNormals.push_back(glm::normalize(glm::vec3(
					-cos(2.0f * pi * i / fstacks) * sin(pi * (j + 1.0f) / fslices),
					-cos(pi * (j + 1.0f) / fslices),
					sin(2.0f * pi * i / fstacks) * sin(pi * (j + 1.0f) / fslices))));
				// Bottom right
				sphereVertices.push_back(glm::vec3(
					radius * -cos(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * j / fslices),
					radius * -cos(pi * j / fslices),
					radius * sin(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * j / fslices)));
				sphereNormals.push_back(glm::normalize(glm::vec3(
					-cos(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * j / fslices),
					-cos(pi * j / fslices),
					sin(2.0f * pi * (i + 1.0) / fstacks) * sin(pi * j / fslices))));
				// Bottom left
				sphereVertices.push_back(glm::vec3(
					radius * -cos(2.0f * pi * i / fstacks) * sin(pi * j / fslices),
					radius * -cos(pi * j / fslices),
					radius * sin(2.0f * pi * i / fstacks) * sin(pi * j / fslices)));
				sphereNormals.push_back(glm::normalize(glm::vec3(
					-cos(2.0f * pi * i / fstacks) * sin(pi * j / fslices),
					-cos(pi * j / fslices),
					sin(2.0f * pi * i / fstacks) * sin(pi * j / fslices))));
			}
		}
		// Now bind this new vertex data
		glBindVertexArray(VAO);

		// Bind vertices
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * sphereVertices.size(), &sphereVertices[0], GL_STATIC_DRAW);

		// Bind normals
		glBindBuffer(GL_ARRAY_BUFFER, NBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * sphereNormals.size(), &sphereNormals[0], GL_STATIC_DRAW);

		// Done updating the buffers
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	glUseProgram(shaderProgram);
	uProjection = glGetUniformLocation(shaderProgram, "projection");
	uModelview = glGetUniformLocation(shaderProgram, "modelview");
	GLuint uCamPos = glGetUniformLocation(shaderProgram, "cameraPos");
	glm::vec3 cam_pos = Window::getCamPos();
	glUniform3f(uCamPos, cam_pos.x, cam_pos.y, cam_pos.z);
	glUniformMatrix4fv(uProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(uModelview, 1, GL_FALSE, &modelview[0][0]);
	// Draw the sphere regardless of whether it was previously updated or not
	glBindVertexArray(VAO);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	glDrawArrays(GL_TRIANGLES, 0, sphereVertices.size());
	glBindVertexArray(0);

	prevStacks = stacks;
	prevSlices = slices;
}

void Sphere::update(float dt)
{

}

