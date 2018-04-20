#include "BezierCurve.h"
#include <math.h>
#include "../Window.h"
#include <vector>
glm::vec3 curve;
glm::vec3 cp0, cp1, cp2, cp3;

BezierCurve::BezierCurve(glm::vec3 p0, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3,GLuint s)
{
	shaderP = s;
	cp0 = p0;
	cp1 = p1;
	cp2 = p2;
	cp3 = p3;
	//ID = id;
	unsigned int i = 0;
	for (float j = 0;j <= 1; j += 0.005)
	{
		calcVertices(j,i);
		//cout << Bezvertices[i].x << "x  " << Bezvertices[i].y << "y  " << Bezvertices[i].z << "z  " << "\n";
		i++;
	}
	
	// Create array object and buffers. Remember to delete your buffers when the object is destroyed!
	glGenVertexArrays(1, &BezVAO);
	glGenBuffers(1, &BezVBO);
	glGenBuffers(1, &BezEBO);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(BezVAO);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, BezVBO);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, Bezvertices.size() * sizeof(glm::vec3), &Bezvertices.front(), GL_STATIC_DRAW);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BezEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Bezindices.size() * sizeof(unsigned int), &Bezindices.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);

	Controlvertices.push_back(cp0);
	Controlindices.push_back(0);
	Controlvertices2.push_back(cp1);
	Controlindices2.push_back(0);
	Controlvertices.push_back(cp3);
	Controlindices.push_back(1);
	Controlvertices2.push_back(cp2);
	Controlindices2.push_back(1);

	Handlevertices.push_back(cp0);
	Handleindices.push_back(0);
	Handlevertices.push_back(cp1);
	Handleindices.push_back(1);
	Handlevertices.push_back(cp3);
	Handleindices.push_back(2);
	Handlevertices.push_back(cp2);
	Handleindices.push_back(3);

	glGenVertexArrays(1, &HandleVAO);
	glGenBuffers(1, &HandleVBO);
	glGenBuffers(1, &HandleEBO);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(HandleVAO);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, HandleVBO);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, Handlevertices.size() * sizeof(glm::vec3), &Handlevertices.front(), GL_STATIC_DRAW);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, HandleEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Handleindices.size() * sizeof(unsigned int), &Handleindices.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);

	glGenVertexArrays(1, &ControlVAO);
	glGenBuffers(1, &ControlVBO);
	glGenBuffers(1, &ControlEBO);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(ControlVAO);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, ControlVBO);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, Controlvertices.size() * sizeof(glm::vec3), &Controlvertices.front(), GL_STATIC_DRAW);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ControlEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Controlindices.size() * sizeof(unsigned int), &Controlindices.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);


	glGenVertexArrays(1, &ControlVAO2);
	glGenBuffers(1, &ControlVBO2);
	glGenBuffers(1, &ControlEBO2);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(ControlVAO2);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, ControlVBO2);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, Controlvertices2.size() * sizeof(glm::vec3), &Controlvertices2.front(), GL_STATIC_DRAW);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ControlEBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Controlindices2.size() * sizeof(unsigned int), &Controlindices2.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);
}
void BezierCurve::calcVertices(float t,int index)
{
	glm::vec3 tempvec;
	tempvec.x = pow(1 - t, 3) * cp0.x + pow(1 - t, 2) * 3 *
		t * cp1.x + (1 - t) * 3 * t * t * cp2.x + t * t * t * cp3.x;
	tempvec.y = pow(1 - t, 3) * cp0.y + pow(1 - t, 2) * 3 *
		t * cp1.y + (1 - t) * 3 * t * t * cp2.y + t * t * t * cp3.y;
	tempvec.z = pow(1 - t, 3) * cp0.z + pow(1 - t, 2) * 3 *
		t * cp1.z + (1 - t) * 3 * t * t * cp2.z + t * t * t * cp3.z;
	Bezvertices.push_back(tempvec);
	Bezindices.push_back(index);
}
void BezierCurve::editPoint(glm::vec3 point,int a)
{
	if (a == 0)
	{
		cp0 = cp0 + point;
	}
	else if (a == 1)
	{
		cp1 = cp1 + point;
	}
	else if (a == 2)
	{
		cp2 = cp2 + point;
	}
	else if (a == 3)
	{
		cp3 = cp3 + point;
	}
	Bezvertices.clear();
	Bezindices.clear();
	Controlvertices.clear();
	Controlindices.clear();
	Controlvertices2.clear();
	Controlindices2.clear();
	Handlevertices.clear();
	Handleindices.clear();
	unsigned int i = 0;
	for (float j = 0; j <= 1; j += 0.005)
	{
		calcVertices(j, i);
		//cout << Bezvertices[i].x << "x  " << Bezvertices[i].y << "y  " << Bezvertices[i].z << "z  " << "\n";
		i++;
	}

	// Create array object and buffers. Remember to delete your buffers when the object is destroyed!
	glGenVertexArrays(1, &BezVAO);
	glGenBuffers(1, &BezVBO);
	glGenBuffers(1, &BezEBO);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(BezVAO);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, BezVBO);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, Bezvertices.size() * sizeof(glm::vec3), &Bezvertices.front(), GL_STATIC_DRAW);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BezEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Bezindices.size() * sizeof(unsigned int), &Bezindices.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);

	Controlvertices.push_back(cp0);
	Controlindices.push_back(0);
	Controlvertices2.push_back(cp1);
	Controlindices2.push_back(0);
	Controlvertices.push_back(cp3);
	Controlindices.push_back(1);
	Controlvertices2.push_back(cp2);
	Controlindices2.push_back(1);

	Handlevertices.push_back(cp0);
	Handleindices.push_back(0);
	Handlevertices.push_back(cp1);
	Handleindices.push_back(1);
	Handlevertices.push_back(cp3);
	Handleindices.push_back(2);
	Handlevertices.push_back(cp2);
	Handleindices.push_back(3);

	glGenVertexArrays(1, &HandleVAO);
	glGenBuffers(1, &HandleVBO);
	glGenBuffers(1, &HandleEBO);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(HandleVAO);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, HandleVBO);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, Handlevertices.size() * sizeof(glm::vec3), &Handlevertices.front(), GL_STATIC_DRAW);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, HandleEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Handleindices.size() * sizeof(unsigned int), &Handleindices.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);

	glGenVertexArrays(1, &ControlVAO);
	glGenBuffers(1, &ControlVBO);
	glGenBuffers(1, &ControlEBO);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(ControlVAO);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, ControlVBO);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, Controlvertices.size() * sizeof(glm::vec3), &Controlvertices.front(), GL_STATIC_DRAW);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ControlEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Controlindices.size() * sizeof(unsigned int), &Controlindices.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);


	glGenVertexArrays(1, &ControlVAO2);
	glGenBuffers(1, &ControlVBO2);
	glGenBuffers(1, &ControlEBO2);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(ControlVAO2);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, ControlVBO2);
	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, Controlvertices2.size() * sizeof(glm::vec3), &Controlvertices2.front(), GL_STATIC_DRAW);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ControlEBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Controlindices2.size() * sizeof(unsigned int), &Controlindices2.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);
}
void BezierCurve::update(glm::mat4 R)
{

}
void BezierCurve::render(GLuint shaderProgram)
{
	// Calculate the combination of the model and view (camera inverse) matrices
	//glm::mat4 modelview = Window::V * toWorld;
	// We need to calcullate this because modern OpenGL does not keep track of any matrix other than the viewport (D)
	// Consequently, we need to forward the projection, view, and model matrices to the shader programs
	// Get the location of the uniform variables "projection" and "modelview"
	BezuProjection = glGetUniformLocation(shaderProgram, "projection");
	BezuModelview = glGetUniformLocation(shaderProgram, "modelview");
	GLint currcolor = glGetUniformLocation(shaderProgram, "col");
	float blue[4] = { 0.0f,0.0f,255.0f,0.0f };
	// Now send these values to the shader +program
	glUniformMatrix4fv(BezuProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(BezuModelview, 1, GL_FALSE, &modelview[0][0]);
	glUniform4fv(currcolor, 1, blue);
	// Now draw the cube. We simply need to bind the VAO associated with it.
	glBindVertexArray(BezVAO);
	glLineWidth(2.0f);
	glDrawElements(GL_LINE_STRIP, Bezindices.size(),GL_UNSIGNED_INT, 0);

	// Tell OpenGL to draw with triangles, using 36 indices, the type of the indices, and the offset to start from
	// Unbind the VAO when we're done so we don't accidentally draw extra stuff or tamper with its bound buffers
	glBindVertexArray(0);
	ControluProjection = glGetUniformLocation(shaderProgram, "projection");
	ControluModelview = glGetUniformLocation(shaderProgram, "modelview");
	currcolor = glGetUniformLocation(shaderProgram, "col");
	float red[4] = { 255.0f,0.0f,0.0f,0.0f };
	// Now send these values to the shader program
	glUniformMatrix4fv(ControluProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(ControluModelview, 1, GL_FALSE, &modelview[0][0]);
	glUniform4fv(currcolor, 1, red);
	// Now draw the cube. We simply need to bind the VAO associated with it.
	glBindVertexArray(ControlVAO);
	glPointSize(10.0f);
	//GLuint idlocation = glGetUniformLocation(pointshader, "code");
	//glUniform1ui(idlocation, ID);
	glDrawElements(GL_POINTS, Controlindices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	ControluProjection2 = glGetUniformLocation(shaderProgram, "projection");
	ControluModelview2 = glGetUniformLocation(shaderProgram, "modelview");
	currcolor = glGetUniformLocation(shaderProgram, "col");
	float green[4] = { 0.0f,255.0f,0.0f,0.0f };
	// Now send these values to the shader program
	glUniformMatrix4fv(ControluProjection2, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(ControluModelview2, 1, GL_FALSE, &modelview[0][0]);
	glUniform4fv(currcolor, 1, green);
	// Now draw the cube. We simply need to bind the VAO associated with it.
	glBindVertexArray(ControlVAO2);
	glPointSize(10.0f);
	//GLuint idlocation = glGetUniformLocation(pointshader, "code");
	//glUniform1ui(idlocation, ID);
	glDrawElements(GL_POINTS, Controlindices2.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	HandleuProjection = glGetUniformLocation(shaderProgram, "projection");
	HandleuModelview = glGetUniformLocation(shaderProgram, "modelview");
	currcolor = glGetUniformLocation(shaderProgram, "col");
	float teal[4] = { 255.0f,255.0f,0.0f,0.0f };
	// Now send these values to the shader program
	glUniformMatrix4fv(HandleuProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(HandleuModelview, 1, GL_FALSE, &modelview[0][0]);
	glUniform4fv(currcolor, 1, teal);
	// Now draw the cube. We simply need to bind the VAO associated with it.
	glBindVertexArray(HandleVAO);
	glLineWidth(2.0f);
	//GLuint idlocation = glGetUniformLocation(pointshader, "code");
	//glUniform1ui(idlocation, ID);
	glDrawElements(GL_LINES, Handleindices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}