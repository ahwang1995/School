#define _CRT_SECURE_NO_DEPRECATE
#include "OBJObject.h"
#include "Window.h"
#include <iostream>
#include <stdio.h>
OBJObject::OBJObject(const char *filepath) 
{
	toWorld = glm::mat4(1.0f);
	parse(filepath);
	//float x, y, z;
	// Create array object and buffers. Remember to delete your buffers when the object is destroyed!
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
	// Consider the VAO as a container for all your buffers.
	glBindVertexArray(VAO);

	// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
	// you want to draw, such as vertices, normals, colors, etc.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
	// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec3), &vertices.front(), GL_STATIC_DRAW);
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(unsigned int), &indices.front(), GL_STATIC_DRAW);

	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);
}

void OBJObject::parse(const char *filepath) 
{
	using namespace std;
	//TODO parse the OBJ file
	// Populate the face indices, vertices, and normals vectors with the OBJ Object data
	FILE* fp;     // file pointer
	float x, y, z;  // vertex coordinates
	float r, g, o;  // vertex color
	int a, b, c,j,k,l;
	int c1, c2;    // characters read from file

	fp = fopen(filepath, "rb");  // make the file name configurable so you can load other files
	if (fp == NULL) { cerr << "error loading file" << endl; exit(-1); }  // just in case the file can't be found or is corrupt
	while (!feof(fp)) {
		c1 = fgetc(fp);
		c2 = fgetc(fp);
		if ((c1 == 'v') && (c2 == ' '))
		{
			fscanf(fp, "%f %f %f %f %f %f", &x, &y, &z, &r, &g, &o);
			vertices.push_back(glm::vec3(x, y, z));
		}
		// read normal data accordingly
		else if ((c1 == 'v') && (c2 == 'n'))
		{
			fgetc(fp);
			fscanf(fp, "%f %f %f", &x, &y, &z);
			normals.push_back(glm::vec3(x,y,z));
		}
		else if ((c1 == ' '))
		{
			c1 = c2;
			c2 = fgetc(fp);
		}
		else if ((c1 == 'f') && (c2 == ' '))
		{
			fscanf(fp, "%i//%i %i//%i %i//%i", &a, &j, &b, &k, &c, &l);
			indices.push_back(a-1);
			indices.push_back(b-1);
			indices.push_back(c-1);

		}
		
	}


	fclose(fp);   // make sure you don't forget to close the file when done
	//cout << indices.size() << "\n";

	float avgx = center(0);
	float avgy = center(1);
	float avgz = center(2);
	glm::vec3 cent = glm::vec3(avgx, avgy, avgz);
	changecenter(0, avgx);
	changecenter(1, avgy);
	changecenter(2, avgz);
	//toWorld = glm::translate(glm::mat4(1.0f), -cent)*toWorld;
	float lenx = scale(0);
	float leny = scale(1);
	float lenz = scale(2);
	float longest = 0;
	if (lenx > leny)
	{
		longest = lenx;
	}
	else
	{
		longest = leny;
	}
	if (lenz > longest)
	{
		longest = lenz;
	}
	changescale(0, longest);
	changescale(1, longest);
	changescale(2, longest);
	//glm::vec3 scalecen = glm::vec3(longest, longest, longest);
	//toWorld = toWorld * glm::scale(glm::mat4(1.0f),scalecen);
}
float OBJObject::scale(int xyz)
{
	float min = vertices[0][xyz], max = vertices[0][xyz];
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i][xyz] < min) min = vertices[i][xyz];
		if (vertices[i][xyz] > max) max = vertices[i][xyz];
	}
	return (max - min);
}
void OBJObject::changescale(int xyz, float longest)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][xyz] = vertices[i][xyz] / longest;
	}
}
void OBJObject::changecenter(int xyz,float avg)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i][xyz] -= avg;
	}
}
float OBJObject::center(int xyz) {
	float min = vertices[0][xyz], max = vertices[0][xyz];
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i][xyz] < min) min = vertices[i][xyz];
		if (vertices[i][xyz] > max) max = vertices[i][xyz];
	}
	return (min + max) / 2;
}
void OBJObject::draw(GLuint shaderProgram)
{
	// Calculate the combination of the model and view (camera inverse) matrices
	glm::mat4 modelview = Window::V * toWorld;
	// We need to calcullate this because modern OpenGL does not keep track of any matrix other than the viewport (D)
	// Consequently, we need to forward the projection, view, and model matrices to the shader programs
	// Get the location of the uniform variables "projection" and "modelview"
	uProjection = glGetUniformLocation(shaderProgram, "projection");
	uModelview = glGetUniformLocation(shaderProgram, "modelview");
	// Now send these values to the shader program
	glUniformMatrix4fv(uProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(uModelview, 1, GL_FALSE, &modelview[0][0]);
	// Now draw the cube. We simply need to bind the VAO associated with it.
	glBindVertexArray(VAO);
	// Tell OpenGL to draw with triangles, using 36 indices, the type of the indices, and the offset to start from
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	// Unbind the VAO when we're done so we don't accidentally draw extra stuff or tamper with its bound buffers
	glBindVertexArray(0);


}
void OBJObject::update()
{
}
void OBJObject::moveObject(string letter)
{
	if (letter == "X")
	{
		//toMove[0].x += 1;
		toWorld = glm::translate(glm::mat4(1.0f), glm::vec3(1, 0, 0)) * toWorld;
		//toWorld = matrix * toWorld;
	}
	if (letter == "x")
	{
		//toMove[0].x -= 1;
		toWorld = glm::translate(glm::mat4(1.0f), glm::vec3(-1, 0, 0)) * toWorld;
		//toWorld = matrix * toWorld;
	}
	if (letter == "Y")
	{
		//toMove[0].y += 1;
		toWorld = glm::translate(glm::mat4(1.0f), glm::vec3(0, 1, 0)) * toWorld;
		//toWorld = matrix * toWorld;
	}
	if (letter == "y")
	{
		//toMove[0].y -= 1;
		toWorld = glm::translate(glm::mat4(1.0f), glm::vec3(0, -1, 0)) * toWorld;
		//toWorld = matrix * toWorld;
	}
	if (letter == "Z")
	{
		//toMove[0].z += 1;
		toWorld = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 1)) * toWorld;
		//toWorld = matrix * toWorld;
	}
	if (letter == "z")
	{
		//toMove[0].z -= 1;
		toWorld = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -1)) * toWorld;
		//toWorld = matrix * toWorld;
	}

	if (letter == "S")
	{
		toWorld = toWorld * glm::scale(glm::mat4(1.0f), glm::vec3(1.6f, 1.6f, 1.6f));
		//toWorld = toWorld * matrix;
	}
	if (letter == "s")
	{
		toWorld = toWorld * glm::scale(glm::mat4(1.0f), glm::vec3(0.625f, 0.625f, 0.625f));
	}
	if (letter == "O")
	{
		toWorld = glm::rotate(glm::mat4(1.0f), -15.0f / 180.0f * glm::pi<float>(), glm::vec3(0, 0, 1.0f))*toWorld;
	}
	if (letter == "o")
	{
		toWorld = glm::rotate(glm::mat4(1.0f), -15.0f / 180.0f * glm::pi<float>(), glm::vec3(0, 0, 1.0f))*toWorld;
	}
	if (letter == "r")
	{
		toWorld = glm::mat4(1.0f);
		glPointSize(1.0f);
	}
}