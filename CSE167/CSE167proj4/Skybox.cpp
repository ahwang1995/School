#include "Skybox.h"
#include <SOIL.h>
#include "Window.h"
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

Skybox::Skybox()
{
	vector<const GLchar*> textures_faces;
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/Skybox_Demo1b_back.jpg");
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/Skybox_Demo1b_base.jpg");
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/Skybox_Demo1b_front.jpg");
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/Skybox_Demo1b_left.jpg");
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/Skybox_Demo1b_right.jpg");
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/Skybox_Demo1b_top.jpg");
	cubemapTexture = loadCubemap(textures_faces);
}
GLuint Skybox::loadCubemap(vector<const GLchar*> textures_faces)
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width, height;
	unsigned char* image;

	for (GLuint i = 0; i < textures_faces.size(); i++)
	{
		image = SOIL_load_image(textures_faces[i], &width, &height, 0, SOIL_LOAD_RGB);
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
			0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image
		);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return textureID;
	glDepthFunc(GL_LEQUAL);
	GLuint SkyboxVBO, SkyboxVAO, uProjection, uModelview;
	glGenVertexArrays(1, &SkyboxVAO);
	glGenBuffers(1, &SkyboxVBO);
	glBindVertexArray(SkyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, SkyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glBindVertexArray(0);

	glDepthMask(GL_FALSE);
	//shaderProgram.Use();
	glUseProgram(Window::shaderProgram2);
	glm::mat4 viewmodel = glm::mat4(glm::mat3(Window::P*Window::V));
	uProjection = glGetUniformLocation(Window::shaderProgram2, "projection");
	uModelview = glGetUniformLocation(Window::shaderProgram2, "modelview");
	// Now send these values to the shader program
	glUniformMatrix4fv(uProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(uModelview, 1, GL_FALSE, &Window::V[0][0]);
	// ... Set view and projection matrix
	glBindVertexArray(SkyboxVAO);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	// Make sure no bytes are padded:
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Select GL_MODULATE to mix texture with polygon color for shading:
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Use bilinear interpolation:
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Use clamp to edge to hide skybox edges:
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthMask(GL_TRUE);

}
/*void Skybox::drawCube(GLuint shaderProgram,GLuint skyvao,GLuint cubetext)
{
	GLuint SkyboxVBO, SkyboxVAO,uProjection,uModelview;
	glGenVertexArrays(1, &SkyboxVAO);
	glGenBuffers(1, &SkyboxVBO);
	glBindVertexArray(SkyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, SkyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glBindVertexArray(0);

	glDepthMask(GL_FALSE);
	//shaderProgram.Use();
	glUseProgram(shaderProgram);
	glm::mat4 viewmodel = glm::mat4(glm::mat3(Window::P*Window::V));
	uProjection = glGetUniformLocation(shaderProgram, "projection");
	uModelview = glGetUniformLocation(shaderProgram, "modelview");
	// Now send these values to the shader program
	glUniformMatrix4fv(uProjection, 1, GL_FALSE, &Window::P[0][0]);
	glUniformMatrix4fv(uModelview, 1, GL_FALSE, &Window::V[0][0]);
	// ... Set view and projection matrix
	glBindVertexArray(skyvao);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubetext);
	// Make sure no bytes are padded:
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Select GL_MODULATE to mix texture with polygon color for shading:
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Use bilinear interpolation:
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Use clamp to edge to hide skybox edges:
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthMask(GL_TRUE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

}*/