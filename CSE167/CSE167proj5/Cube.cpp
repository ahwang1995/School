#include "Cube.h"
#include "Window.h"

Cube::Cube(GLuint sp,float showside[6])
{
	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  showside[0],
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  showside[0],  showside[0],
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  showside[0],  0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  showside[0],  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  showside[0],

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, showside[1],
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  showside[1],  showside[1],
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  showside[1],  0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  showside[1],  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  showside[1],

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  showside[2],
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  showside[2],  showside[2],
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  showside[2],  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  showside[2],  0.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  showside[2],

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  showside[3],
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  showside[3],  showside[3],
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  showside[3],  0.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  showside[3],  0.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  showside[3],

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  showside[4],
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  showside[4],  showside[4],
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  showside[4],  0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  showside[4],  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  showside[4],

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  showside[5],
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  showside[5],  showside[5],
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  showside[5],  0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  showside[5],  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  showside[5]
	};
	shaderProgram = sp;

	// First, set the container's VAO (and VBO)
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);

}

void Cube::destroy()
{
	// Delete previously generated buffers. Note that forgetting to do this can waste GPU memory in a 
	// large project! This could crash the graphics driver due to memory leaks, or slow down application performance!
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Cube::render(GLuint shaderProgram)
{ 
	glUseProgram(shaderProgram);
	// Calculate the combination of the model and view (camera inverse) matrices
	//glm::mat4 modelview = Window::V * toWorld;
	// We need to calcullate this because modern OpenGL does not keep track of any matrix other than the viewport (D)
	// Consequently, we need to forward the projection, view, and model matrices to the shader programs
	// Get the location of the uniform variables "projection" and "modelview"
	glm::mat4 model = inverse(Window::V) * modelview;
	uProjection = glGetUniformLocation(shaderProgram, "projection");
	uModel = glGetUniformLocation(shaderProgram, "model");
	uView = glGetUniformLocation(shaderProgram, "view");
	// Now send these values to the shader program
	glUniformMatrix4fv(uProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(uModel, 1, GL_FALSE, &model[0][0]);
	glUniformMatrix4fv(uView, 1, GL_FALSE, &Window::V[0][0]);
	// Draw the container (using container's vertex attributes)
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void Cube::update(float dt)
{

}

