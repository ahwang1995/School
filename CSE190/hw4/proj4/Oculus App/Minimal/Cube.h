#ifndef _CUBE_H_
#define _CUBE_H_

// Use of degrees is deprecated. Use radians instead.
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "misc.h"
#include "gameObject.h"

class Cube : public GameObject
{
public:
	Cube(Shader* sp, GLuint textID, glm::vec3 pos, glm::vec3 sc, float showside[6]) : GameObject(sp, NULL, pos) {
		//float showside[6] = { 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, 1.0f };

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

		shader = sp;
		textureID = textID;
		scale = sc;

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

	void destroy()
	{
		// Delete previously generated buffers. Note that forgetting to do this can waste GPU memory in a 
		// large project! This could crash the graphics driver due to memory leaks, or slow down application performance!
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void draw(glm::mat4 P, glm::mat4 V)
	{
		glActiveTexture(textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		shader->Use();
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "projection"), 1, GL_FALSE, &P[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "view"), 1, GL_FALSE, &V[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, &toWorld[0][0]);
		// Draw the container (using container's vertex attributes)
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
		// Draw children
		for each(GameObject* child in children) child->draw(P, V);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

public:
	// These variables are needed for the shader program
	GLuint VBO, VAO, EBO;
	GLuint uProjection, uModel, uView;

	GLuint textureID;
};


#endif

