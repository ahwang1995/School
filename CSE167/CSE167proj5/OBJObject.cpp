#include "OBJObject.h"
#include "math.h"
#include <algorithm>

OBJObject::OBJObject(const char *filepath, GLuint sp)
{
	shaderProgram = sp;
	parse(filepath);

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
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices.front(), GL_STATIC_DRAW);
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
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.front(), GL_STATIC_DRAW);
	// Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Unbind the VAO now so we don't accidentally tamper with it.
	// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
	glBindVertexArray(0);
}

// For finding the mean x, y and z, to locate the center of the obj
float OBJObject::mean(int ind, std::vector<glm::vec3> vertices) {
	float min = vertices[0][ind], max = vertices[0][ind];
	for (int i = 1; i < vertices.size(); i++) {
		if (vertices[i][ind] < min) min = vertices[i][ind];
		if (vertices[i][ind] > max) max = vertices[i][ind];
	}
	return (min + max) / 2;
}

float OBJObject::maxAxis(int ind, std::vector<glm::vec3> vertices) {
	float min = vertices[0][ind], max = vertices[0][ind];
	for (int i = 1; i < vertices.size(); i++) {
		if (vertices[i][ind] > max) max = vertices[i][ind];
	}
	return max;
}

void OBJObject::parse(const char *filepath)
{
	//TODO parse the OBJ file
	// Populate the face indices, vertices, and normals vectors with the OBJ Object data

	FILE* fp;     // file pointer
	float x, y, z;  // vertex coordinates
	float r, g, b;  // vertex color
	int c1, c2;    // characters read from file

	//fp = fopen(filepath, "rb");  // make the file name configurable so you can load other files
	fopen_s(&fp, filepath, "rb");

	if (fp == NULL) { /*cerr << "error loading file" << endl;*/ exit(-1); }  // just in case the file can't be found or is corrupt

	c1 = fgetc(fp);
	c2 = fgetc(fp);

	//std::vector<glm::vec3> vertices;
	//std::vector<glm::vec3> normals;
	std::vector<glm::vec2> textcoords;

	while (c1 != -1)
	{
		if ((c1 == 'v') && (c2 == ' '))
		{
			fscanf_s(fp, "%f %f %f %f %f %f", &x, &y, &z, &r, &g, &b);
			vertices.push_back(glm::vec3(x, y, z));
		}
		// read normal data accordingly
		else if ((c1 == 'v') && (c2 == 'n'))
		{
			fscanf_s(fp, "%f %f %f", &x, &y, &z);
			//Convert to unit vector
			float factor = pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5);

			if (factor != 0) {
				x = x / factor;
				y = y / factor;
				z = z / factor;
			}

			normals.push_back(glm::vec3(x, y, z));
		}
		else if ((c1 == 'f') && (c2 == ' '))
		{
			GLuint a, b, c, d, e, f;
			fscanf_s(fp, "%u//%u %u//%u %u//%u", &a, &b, &c, &d, &e, &f);
			indices.push_back(a-1);
			indices.push_back(c-1);
			indices.push_back(e-1);
		}
		//Texture coords
		else if ((c1 == 'v') && (c2 == 't')) {
			fscanf_s(fp, "%f %f", &x, &y);
			textcoords.push_back(glm::vec2(x, y));
		}
		else if (c1 == ' ') {
			c1 = c2;
			c2 = fgetc(fp);
			continue;
		}
		// otherwise skip
		c1 = fgetc(fp);
		c2 = fgetc(fp);
	}

	fclose(fp);   // make sure you don't forget to close the file when done

	printf("v count: %d, vn count: %d, f count: %d\n", vertices.size(), normals.size(), indices.size());

	//Find center
	glm::vec3 center = glm::vec3(mean(0, vertices),mean(1, vertices),mean(2, vertices));
	//Move to center
	for (int i = 0; i < vertices.size(); i++) vertices[i] -= center;
	//Find max
	float maxval = std::max(std::max(maxAxis(0, vertices), maxAxis(1, vertices)), maxAxis(2, vertices));
	//Divide by max
	for (int i = 0; i < vertices.size(); i++) vertices[i] /= maxval;

	/*Put verticles and normals, and texture coords in one thing??
	for (int i = 0; i < vertices.size(); i++) {
		Vertex * vp = new Vertex();
		Vertex v = *vp;
		v.Position = vertices[i];
		v.Normal = normals[i];
		//v.TexCoords = textcoords[i];
		v.TexCoords = glm::vec2(0, 0);
		this->vertices.push_back(v);
	}*/
	
}

void OBJObject::render(GLuint shaderProgram)
{
	glUseProgram(shaderProgram);
	// We need to calcullate this because modern OpenGL does not keep track of any matrix other than the viewport (D)
	// Consequently, we need to forward the projection, view, and model matrices to the shader programs
	// Get the location of the uniform variables "projection" and "modelview"
	glm::mat4 model = inverse(Window::V) * modelview;
	uProjection = glGetUniformLocation(shaderProgram, "projection");
	uModel = glGetUniformLocation(shaderProgram, "model");
	uView = glGetUniformLocation(shaderProgram, "view");
	uColor = glGetUniformLocation(shaderProgram, "color");
	GLfloat color[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	// Now send these values to the shader program
	glUniformMatrix4fv(uProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(uModel, 1, GL_FALSE, &model[0][0]);
	glUniformMatrix4fv(uView, 1, GL_FALSE, &Window::V[0][0]);
	glUniform4fv(uColor, 1, &color[0]);

	// Now draw the cube. We simply need to bind the VAO associated with it.
	glBindVertexArray(VAO);
	// Tell OpenGL to draw with triangles, using 36 indices, the type of the indices, and the offset to start from
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	// Unbind the VAO when we're done so we don't accidentally draw extra stuff or tamper with its bound buffers
	glBindVertexArray(0);
}

void OBJObject::update(float dt)
{

}