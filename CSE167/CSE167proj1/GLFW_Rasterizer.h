#ifndef GLFW_Rasterizer_H
#define GLFW_Rasterizer_H
#include <math.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#else
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Window.h"
#include "OBJObject.h"
using namespace std;
class GLFW_Rasterizer {
public:
	static void resizeCallback(GLFWwindow* window, int width, int height);
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void displayCallback(GLFWwindow* window);
	void errorCallback(int error, const char* description);
};
#endif