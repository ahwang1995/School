#include "OBJObject.h"
#include <iostream>
#include <stdio.h>
glm::mat4 matrix;
glm::mat4 omatrix;
glm::mat4 smatrix;
OBJObject::OBJObject(const char *filepath) 
{
	toWorld = glm::mat4(1.0f);
	parse(filepath);
	angle = 0.0f;
	bool boolO, boolo;
	zangle = 0.0f;
	float x, y, z;
	toMove.push_back(glm::vec3(x, y, z));
	toScale.push_back(glm::vec3(x, y, z));
	toMove[0].x = 0;
	toMove[0].y = 0;
	toMove[0].z = 0;
	toScale[0].x = 1.0f;
	toScale[0].y = 1.0f;
	toScale[0].z = 1.0f;
}

void OBJObject::parse(const char *filepath) 
{
	using namespace std;
	//TODO parse the OBJ file
	// Populate the face indices, vertices, and normals vectors with the OBJ Object data
	FILE* fp;     // file pointer
	float x, y, z;  // vertex coordinates
	float r, g, b;  // vertex color
	int c1, c2;    // characters read from file

	fp = fopen(filepath, "rb");  // make the file name configurable so you can load other files
	if (fp == NULL) { cerr << "error loading file" << endl; exit(-1); }  // just in case the file can't be found or is corrupt
	while (!feof(fp)) {
		c1 = fgetc(fp);
		c2 = fgetc(fp);
		if ((c1 == 'v') && (c2 == ' '))
		{
			fscanf(fp, "%f %f %f %f %f %f", &x, &y, &z, &r, &g, &b);
			vertices.push_back(glm::vec3(x,y,z));
		}
		// read normal data accordingly
		else if ((c1 == 'v') && (c2 == 'n'))
		{
			fgetc(fp);
			fscanf(fp, "%f %f %f", &x, &y, &z);
			normals.push_back(glm::vec3(x,y,z));
		}
	}


	fclose(fp);   // make sure you don't forget to close the file when done
}

void OBJObject::draw() 
{
	glMatrixMode(GL_MODELVIEW);

	// Push a save state onto the matrix stack, and multiply in the toWorld matrix
	glPushMatrix();
	glMultMatrixf(&(toWorld[0][0]));

	glBegin(GL_POINTS);
	// Loop through all the vertices of this OBJ Object and render them
	for (unsigned int i = 0; i < vertices.size(); ++i) 
	{
		//glm::normalize(normals[i]);
		glColor3f((normals[i].x + 1.0f)/2.0f, (normals[i].y + 1.0f)/2.0f, (normals[i].z + 1.0f)/2.0f);
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
	}
	glEnd();

	// Pop the save state off the matrix stack
	// This will undo the multiply we did earlier
	glPopMatrix();
}
void OBJObject::update()
{
	spin(1.0f);
	toWorld = glm::rotate(glm::mat4(1.0f), this->angle / 180.0f * glm::pi<float>(), glm::vec3(0.0f, 1.0f, 0.0f));
	toWorld = matrix * toWorld;
	toWorld = toWorld * smatrix;
	toWorld = toWorld * omatrix;
}
void OBJObject::moveObject(string letter)
{
	if (letter == "X")
	{
		toMove[0].x += 1;
		matrix = glm::translate(glm::mat4(1.0f),toMove[0]);
		//toWorld = matrix * toWorld;
	}
	if (letter == "x")
	{
		toMove[0].x -= 1;
		matrix = glm::translate(glm::mat4(1.0f), toMove[0]);
		//toWorld = matrix * toWorld;
	}
	if (letter == "Y")
	{
		toMove[0].y += 1;
		matrix = glm::translate(glm::mat4(1.0f), toMove[0]);
		//toWorld = matrix * toWorld;
	}
	if (letter == "y")
	{
		toMove[0].y -= 1;
		matrix = glm::translate(glm::mat4(1.0f), toMove[0]);
		//toWorld = matrix * toWorld;
	}
	if (letter == "Z")
	{
		toMove[0].z += 1;
		matrix = glm::translate(glm::mat4(1.0f), toMove[0]);
		//toWorld = matrix * toWorld;
	}
	if (letter == "z")
	{
		toMove[0].z -= 1;
		matrix = glm::translate(glm::mat4(1.0f), toMove[0]);
		//toWorld = matrix * toWorld;
	}
	if (letter == "S")
	{
		toScale[0].x = toScale[0].x * 1.6f;
		toScale[0].y = toScale[0].y * 1.6f;
		toScale[0].z = toScale[0].z * 1.6f;
		smatrix = glm::scale(glm::mat4(1.0f), toScale[0]);
		//toWorld = toWorld * matrix;
	}
	if (letter == "s")
	{
		toScale[0].x = toScale[0].x * 0.625f;
		toScale[0].y = toScale[0].y * 0.625f;
		toScale[0].z = toScale[0].z * 0.625f;
		smatrix = glm::scale(glm::mat4(1.0f), toScale[0]);
		//toWorld = toWorld * matrix;
	}
	if (letter == "O")
	{
		omatrix = glm::rotate(glm::mat4(1.0f), zangle / 180.0f * glm::pi<float>(), glm::vec3(0,0,1.0f));
		//toWorld = matrix * toWorld;
		this->zangle -= 15.0f;
		if (this->zangle > 360.0f || this->zangle < -360.0f) this->zangle = 0.0f;
	}
	if (letter == "o")
	{
		omatrix = glm::rotate(glm::mat4(1.0f), zangle / 180.0f * glm::pi<float>(), glm::vec3(0, 0, 1.0f));
		//toWorld = matrix * toWorld;
		this->zangle += 15.0f;
		if (this->zangle > 360.0f || this->zangle < -360.0f) this->zangle = 0.0f;
	}
	if (letter == "r")
	{
		matrix = glm::mat4(1.0f);
		smatrix = glm::mat4(1.0f);
		omatrix = glm::mat4(1.0f);
		toWorld = matrix;
		glPointSize(1.0f);
		toMove[0].x = 0;
		toMove[0].y = 0;
		toMove[0].z = 0;
		toScale[0].x = 1.0f;
		toScale[0].y = 1.0f;
		toScale[0].z = 1.0f;
		zangle = 0;
		matrix = glm::rotate(glm::mat4(1.0f), zangle / 180.0f * glm::pi<float>(), glm::vec3(0, 0, 1.0f));
	}
}
void OBJObject::spin(float deg)
{
	this->angle += deg;
	if (this->angle > 360.0f || this->angle < -360.0f) this->angle = 0.0f;
	// This creates the matrix to rotate the object
}