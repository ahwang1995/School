#ifndef Skybox_H
#define Skybox_H
#define GLFW_INCLUDE_GLEXT
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#else
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "loadppm.h"
#include "Window.h"
#include "shader.h"
#include "skyboxshader.h"
using namespace std;
class Skybox
{
public:
	Skybox();
	static GLuint loadCubemap(vector<const GLchar*> faces);
	vector<const GLchar*> textures_faces;
	GLuint cubemapTexture;
	GLuint SkyboxVBO, SkyboxVAO;
	GLuint uProjection, uModelview;
	static void drawCube(GLuint shaderProgram, GLuint skyvao, GLuint cubetext);
};
#endif