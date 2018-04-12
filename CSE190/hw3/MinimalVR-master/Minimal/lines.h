#include "misc.h"

#include <iostream>
class lines {
public:


	GLuint lineVAO, lineVBO, lineEBO;
	std::vector<glm::vec3> lineVerts;
	std::vector<unsigned int> lineInds = { 0, 1, 2, 3,4,6,7,8,9,10,11,12,13,14,15,16 };
	Shader* lineshader;
	bool eye;
	//glm::mat4 model;

	lines() {
		lineshader = new Shader("./wire_shader.vert", "./wire_shader.frag");
	}



	void draw(glm::mat4 P, glm::mat4 V,bool eye, std::vector<glm::vec3> lineV) {
		lineVerts = lineV;
		// Create array object and buffers. Remember to delete your buffers when the object is destroyed!
		glGenVertexArrays(1, &lineVAO);
		glGenBuffers(1, &lineVBO);
		glGenBuffers(1, &lineEBO);
		// Bind the Vertex Array Object (VAO) first, then bind the associated buffers to it.
		// Consider the VAO as a container for all your buffers.
		glBindVertexArray(lineVAO);
		// Now bind a VBO to it as a GL_ARRAY_BUFFER. The GL_ARRAY_BUFFER is an array containing relevant data to what
		// you want to draw, such as vertices, normals, colors, etc.
		glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
		// glBufferData populates the most recently bound buffer with data starting at the 3rd argument and ending after
		// the 2nd argument number of indices. How does OpenGL know how long an index spans? Go to glVertexAttribPointer.
		glBufferData(GL_ARRAY_BUFFER, lineVerts.size() * sizeof(glm::vec3), &lineVerts.front(), GL_STATIC_DRAW);
		// Enable the usage of layout location 0 (check the vertex shader to see what this is)
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0,// This first parameter x should be the same as the number passed into the line "layout (location = x)" in the vertex shader. In this case, it's 0. Valid values are 0 to GL_MAX_UNIFORM_LOCATIONS.
			3, // This second line tells us how any components there are per vertex. In this case, it's 3 (we have an x, y, and z component)
			GL_FLOAT, // What type these components are
			GL_FALSE, // GL_TRUE means the values should be normalized. GL_FALSE means they shouldn't
			3 * sizeof(GLfloat), // Offset between consecutive indices. Since each of our vertices have 3 floats, they should have the size of 3 floats in between
			(GLvoid*)0); // Offset of the first vertex's component. In our case it's 0 since we don't pad the vertices array with anything.
						 // Unbind the currently bound buffer so that we don't accidentally make unwanted changes to it.
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lineEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, lineInds.size() * sizeof(unsigned int), &lineInds.front(), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// Unbind the VAO now so we don't accidentally tamper with it.
		// NOTE: You must NEVER unbind the element array buffer associated with a VAO!
		glBindVertexArray(0);
		lineshader->Use();
		if (eye) glUniform1f(glGetUniformLocation(lineshader->Program, "flag"), 1.0f);
		else glUniform1f(glGetUniformLocation(lineshader->Program, "flag"), 0.0f);
		glm::mat4 model(1.0f);
		glUniformMatrix4fv(glGetUniformLocation(lineshader->Program, "projection"), 1, GL_FALSE, &P[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(lineshader->Program, "view"), 1, GL_FALSE, &V[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(lineshader->Program, "model"), 1, GL_FALSE, &model[0][0]);
		glBindVertexArray(lineVAO);
		glLineWidth(3.0f);
		glDrawElements(GL_LINES, lineInds.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

private:

};
