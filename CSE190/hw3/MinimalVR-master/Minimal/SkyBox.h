#include <vector>
#include "misc.h"

class Skybox
{
public:
	// These variables are needed for the shader program
	GLuint VBO, VAO, EBO;
	GLuint uProjection, uModel, uView;
	GLuint cubemapTexture[2];
	Shader* shader;

	Skybox(Shader* sp) {
		GLfloat skyboxVertices[] = {
			// Positions          
			-1.0f,  1.0f, -1.0f,
			-1.0f, -1.0f, -1.0f,
			1.0f, -1.0f, -1.0f,
			1.0f, -1.0f, -1.0f,
			1.0f,  1.0f, -1.0f,
			-1.0f,  1.0f, -1.0f,

			-1.0f, -1.0f,  1.0f,
			-1.0f, -1.0f, -1.0f,
			-1.0f,  1.0f, -1.0f,
			-1.0f,  1.0f, -1.0f,
			-1.0f,  1.0f,  1.0f,
			-1.0f, -1.0f,  1.0f,

			1.0f, -1.0f, -1.0f,
			1.0f, -1.0f,  1.0f,
			1.0f,  1.0f,  1.0f,
			1.0f,  1.0f,  1.0f,
			1.0f,  1.0f, -1.0f,
			1.0f, -1.0f, -1.0f,

			-1.0f, -1.0f,  1.0f,
			-1.0f,  1.0f,  1.0f,
			1.0f,  1.0f,  1.0f,
			1.0f,  1.0f,  1.0f,
			1.0f, -1.0f,  1.0f,
			-1.0f, -1.0f,  1.0f,

			-1.0f,  1.0f, -1.0f,
			1.0f,  1.0f, -1.0f,
			1.0f,  1.0f,  1.0f,
			1.0f,  1.0f,  1.0f,
			-1.0f,  1.0f,  1.0f,
			-1.0f,  1.0f, -1.0f,

			-1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f,  1.0f,
			1.0f, -1.0f, -1.0f,
			1.0f, -1.0f, -1.0f,
			-1.0f, -1.0f,  1.0f,
			1.0f, -1.0f,  1.0f
		};

		std::vector<const GLchar*> faces[2];
		faces[0].push_back("./left-ppm/px.ppm");
		faces[0].push_back("./left-ppm/nx.ppm");
		faces[0].push_back("./left-ppm/py.ppm");
		faces[0].push_back("./left-ppm/ny.ppm");
		faces[0].push_back("./left-ppm/pz.ppm");
		faces[0].push_back("./left-ppm/nz.ppm");
		cubemapTexture[0] = loadCubemap(faces[0]);

		faces[1].push_back("./right-ppm/px.ppm");
		faces[1].push_back("./right-ppm/nx.ppm");
		faces[1].push_back("./right-ppm/py.ppm");
		faces[1].push_back("./right-ppm/ny.ppm");
		faces[1].push_back("./right-ppm/pz.ppm");
		faces[1].push_back("./right-ppm/nz.ppm");
		cubemapTexture[1] = loadCubemap(faces[1]);
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glBindVertexArray(0);
		shader = sp;
	}

	GLuint loadCubemap(std::vector<const GLchar*> faces)
	{
		GLuint textureID;
		glGenTextures(1, &textureID);
		glActiveTexture(textureID);

		int width, height;
		unsigned char* image;

		glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
		for (GLuint i = 0; i < faces.size(); i++)
		{
			image = Misc::loadPPM(faces[i], width, height);
			glTexImage2D(
				GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,
				GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image
			);
		}
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

		return textureID;
	}


	void destroy()
	{
		// Delete previously generated buffers. Note that forgetting to do this can waste GPU memory in a 
		// large project! This could crash the graphics driver due to memory leaks, or slow down application performance!
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void draw(glm::mat4 P, glm::mat4 V, ovrEyeType eye, bool mono, float eye_dist)
	{
		glDepthMask(GL_FALSE);// Remember to turn depth writing off
		shader->Use();
		if(!mono) glActiveTexture(cubemapTexture[eye]);
		else glActiveTexture(cubemapTexture[0]);

		glm::mat4 view = glm::mat4(glm::mat3(V));
		if (!mono) view = glm::translate(glm::mat4(), glm::vec3(eye_dist, 0, 0)) * view;
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "projection"), 1, GL_FALSE, &P[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader->Program, "view"), 1, GL_FALSE, &view[0][0]);
		glBindVertexArray(VAO);
		glActiveTexture(cubemapTexture[eye]);
		glUniform1i(glGetUniformLocation(shader->Program, "skybox"), 0);
		// Draw the container (using container's vertex attributes)
		if (!mono) glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture[eye]);
		else glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture[0]);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		glDepthMask(GL_TRUE);

	}

	void Skybox::update()
	{

	}
};