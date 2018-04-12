#pragma once

#include "misc.h"
#include <iostream>
class Screen {
public:

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	glm::vec3 pA;
	glm::vec3 pB;
	glm::vec3 pC;
	glm::vec3 pD;
	glm::mat4 model;
	std::vector<glm::vec3> lineVerts;

	GLuint quadVAO, quadVBO;

	Shader* screenshader;

	Screen(glm::vec3 p, glm::vec3 r, glm::vec3 s) {
		position = p; 
		rotation = r;
		scale = s;

		model = glm::mat4(1.0f);
		model = glm::translate(model, position);
		model = glm::rotate(model, rotation.z, glm::vec3(0, 0, 1));
		model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
		model = glm::rotate(model, rotation.x, glm::vec3(1, 0, 0));
		model = glm::scale(model, scale);
		pA = model*glm::vec4(-0.5, -0.5, 0.0f, 1.0f);
		pB = model*glm::vec4(0.5, -0.5, 0.0f, 1.0f);
		pC = model*glm::vec4(-0.5, 0.5, 0.0f, 1.0f);
		pD = model*glm::vec4(0.5f, 0.5f, 0.0f, 1.0f);

		GLfloat quadVertices[] = {   // Vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
									 // Positions   // TexCoords
			-0.5f, -0.5f, 0.0f, 0.0f,  -1.0f,
			0.5f, -0.5f, 0.0f, 1.0f,  -1.0f,
			0.5f,  0.5f, 0.0f, 1.0f,  0.0f,

			0.5f,  0.5f, 0.0f, 1.0f,  0.0f,
			-0.5f,  0.5f, 0.0f, 0.0f,  0.0f,
			-0.5f, -0.5f, 0.0f, 0.0f,  -1.0f,

		};
		// Setup screen VAO
		glGenVertexArrays(1, &quadVAO);
		glGenBuffers(1, &quadVBO);
		glBindVertexArray(quadVAO);
		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);

		screenshader = new Shader("./screen_shader.vert", "./screen_shader.frag");
	}

	glm::mat4 getP(glm::vec3 eyePos) {
		//for debug wires
		lineVerts.clear();
		lineVerts.push_back(eyePos);
		lineVerts.push_back(pA);
		lineVerts.push_back(eyePos);;

		lineVerts.push_back(pB);
		lineVerts.push_back(eyePos);

		lineVerts.push_back(pC);
		lineVerts.push_back(eyePos);

		lineVerts.push_back(pD);
		lineVerts.push_back(eyePos);
		lineVerts.push_back(pA);
		lineVerts.push_back(eyePos);;

		lineVerts.push_back(pB);
		lineVerts.push_back(eyePos);

		lineVerts.push_back(pC);
		lineVerts.push_back(eyePos);

		lineVerts.push_back(pD);

		glm::vec3 vR = (pB - pA) / glm::length(pB - pA);
		glm::vec3 vU = (pC - pA) / glm::length(pC - pA);
		glm::vec3 vN = (glm::cross(vR,vU)) / glm::length((glm::cross(vR, vU)));

		glm::vec3 vA = pA - eyePos;
		glm::vec3 vB = pB - eyePos;
		glm::vec3 vC = pC - eyePos;

		float d = -glm::dot(vN, vA);
		float n = 0.01f, f = 1000.0f;

		float l = (glm::dot(vR, vA)*n / d);
		float r = (glm::dot(vR, vB)*n / d);
		float b = (glm::dot(vU, vA)*n / d);
		float t = (glm::dot(vU, vC)*n / d);
		glm::mat4 P = glm::frustum(l, r, b, t, n, f);

		glm::mat4 M = glm::mat4(glm::mat3(vR, vU, vN));
		M[3][3] = 1;
		

		glm::mat4 T = glm::mat4(1.0f);

		T[3][0] = -eyePos.x;
		T[3][1] = -eyePos.y;
		T[3][2] = -eyePos.z;
		
		glm::mat4 P_ = P * glm::transpose(M) * T;

		return P_;
	}

	void draw(glm::mat4 P, glm::mat4 V, GLuint textureColorbuffer) {
		screenshader->Use();

		glUniformMatrix4fv(glGetUniformLocation(screenshader->Program, "projection"), 1, GL_FALSE, &P[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(screenshader->Program, "view"), 1, GL_FALSE, &V[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(screenshader->Program, "model"), 1, GL_FALSE, &model[0][0]);
		glBindVertexArray(quadVAO);
		glBindTexture(GL_TEXTURE_2D, textureColorbuffer);	// Use the color attachment texture as the texture of the quad plane
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}

private:

};
