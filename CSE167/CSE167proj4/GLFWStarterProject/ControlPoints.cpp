#include "ControlPoints.h"
#include <math.h>
#include "../Window.h"
ControlPoints::ControlPoints(GLuint s,glm::vec3 c,float id)
{
	shaderP = s;
	cp = c;
	ID = id;
	CPvertices.push_back(cp);
	CPindices.push_back(0);
	// Create array object and buffers. Remember to delete your buffers when the object is destroyed!
	glGenVertexArrays(1, &CPVAO);
	glGenBuffers(1, &CPVBO);
	glGenBuffers(1, &CPEBO);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(CPVAO);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, CPVBO);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, CPvertices.size() * sizeof(glm::vec3), &CPvertices.front(), GL_STATIC_DRAW);
	// Enable the usage of layout location 0 (check the vertex shader to see what this is)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,// This first parameter x should be the same as the number passed into the line "layout (location = x)" in the vertex shader. In this case, it's 0. Valid values are 0 to GL_MAX_UNIFORM_LOCATIONS.
		3, // This second line tells us how any components there are per vertex. In this case, it's 3 (we have an x, y, and z component)
		GL_FLOAT, // What type these components are
		GL_FALSE, // GL_TRUE means the values should be normalized. GL_FALSE means they shouldn't
		3 * sizeof(GLfloat), // Offset between consecutive indices. Since each of our vertices have 3 floats, they should have the size of 3 floats in between
		(GLvoid*)0); // Offset of the first vertex's component. In our case it's 0 since we don't pad the vertices array with anything.

					 // We've sent the vertex data over to OpenGL, but there's still something missing.
					 // In what order should it draw those vertices? That's why we'll need a GL_ELEMENT_ARRAY_BUFFER for this.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, CPEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, CPindices.size() * sizeof(unsigned int), &CPindices.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);
}
void ControlPoints::editPoint(glm::vec3 point)
{
	cp = cp + point;
	CPvertices.clear();
	CPindices.clear();
	CPvertices.push_back(cp);
	CPindices.push_back(0);
	// Create array object and buffers. Remember to delete your buffers when the object is destroyed!
	glGenVertexArrays(1, &CPVAO);
	glGenBuffers(1, &CPVBO);
	glGenBuffers(1, &CPEBO);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(CPVAO);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, CPVBO);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, CPvertices.size() * sizeof(glm::vec3), &CPvertices.front(), GL_STATIC_DRAW);
	// Enable the usage of layout location 0 (check the vertex shader to see what this is)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,// This first parameter x should be the same as the number passed into the line "layout (location = x)" in the vertex shader. In this case, it's 0. Valid values are 0 to GL_MAX_UNIFORM_LOCATIONS.
		3, // This second line tells us how any components there are per vertex. In this case, it's 3 (we have an x, y, and z component)
		GL_FLOAT, // What type these components are
		GL_FALSE, // GL_TRUE means the values should be normalized. GL_FALSE means they shouldn't
		3 * sizeof(GLfloat), // Offset between consecutive indices. Since each of our vertices have 3 floats, they should have the size of 3 floats in between
		(GLvoid*)0); // Offset of the first vertex's component. In our case it's 0 since we don't pad the vertices array with anything.

					 // We've sent the vertex data over to OpenGL, but there's still something missing.
					 // In what order should it draw those vertices? That's why we'll need a GL_ELEMENT_ARRAY_BUFFER for this.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, CPEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, CPindices.size() * sizeof(unsigned int), &CPindices.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);
}
void ControlPoints::update(glm::mat4 R)
{

}
void ControlPoints::render(GLuint shaderProgram)
{
	// Calculate the combination of the model and view (camera inverse) matrices
	//glm::mat4 modelview = Window::V * toWorld;
	// We need to calcullate this because modern OpenGL does not keep track of any matrix other than the viewport (D)
	// Consequently, we need to forward the projection, view, and model matrices to the shader programs
	// Get the location of the uniform variables "projection" and "modelview"
	glUseProgram(shaderProgram);
	CPuProjection = glGetUniformLocation(shaderProgram, "projection");
	CPuModelview = glGetUniformLocation(shaderProgram, "modelview");
	GLuint idLocation = glGetUniformLocation(shaderProgram, "code");
	// Now send these values to the shader program
	glUniformMatrix4fv(CPuProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(CPuModelview, 1, GL_FALSE, &modelview[0][0]);
	glUniform1ui(idLocation, ID);
	// Now draw the cube. We simply need to bind the VAO associated with it.
	glBindVertexArray(CPVAO);
	glPointSize(10.0f);
	glDrawElements(GL_POINTS, CPindices.size(), GL_UNSIGNED_INT, 0);
	// Tell OpenGL to draw with triangles, using 36 indices, the type of the indices, and the offset to start from
	// Unbind the VAO when we're done so we don't accidentally draw extra stuff or tamper with its bound buffers
	glBindVertexArray(0);
}