#include "BoundingBox.h"
BoundingBox::BoundingBox(GLuint sp) {
	shaderProgram = sp;
	boxcolor = 0;
	GLfloat vertices[] = {
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,0.5f,-0.5f,
		-0.5f,0.5f,-0.5f,
		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,0.5f,
		0.5f,0.5f,0.5f,
		0.5f,0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,
		0.5f,0.5f,0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		-0.5f,0.5f,-0.5f
	};
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
}
void BoundingBox::destroy()
{
	// Delete previously generated buffers. Note that forgetting to do this can waste GPU memory in a 
	// large project! This could crash the graphics driver due to memory leaks, or slow down application performance!
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
void BoundingBox::render(GLuint shaderProgram) {
	//If in view...
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
	uColor = glGetUniformLocation(shaderProgram, "color");
	GLfloat red[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat green[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
	// Now send these values to the shader program
	glUniformMatrix4fv(uProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(uModel, 1, GL_FALSE, &model[0][0]);
	glUniformMatrix4fv(uView, 1, GL_FALSE, &Window::V[0][0]);
	if(boxcolor)
		glUniform4fv(uColor, 1, &red[0]);
	else
		glUniform4fv(uColor, 1, &green[0]);
	glUseProgram(shaderProgram);
	// Draw the container (using container's vertex attributes)

	glBindVertexArray(VAO);
	glDrawArrays(GL_LINES, 0, 30);
	glBindVertexArray(0);
	
}


void BoundingBox::update(float dt) {
}
