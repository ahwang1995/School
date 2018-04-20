#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>

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
#include "Cube.h"
#include "shader.h"
#include "Bound.h"
#include "OBJObject.h"
#include "GLFWStarterProject/Geode.h"
#include "GLFWStarterProject/Group.h"
#include "GLFWStarterProject/MatrixTransform.h"
#include "GLFWStarterProject/BezierCurve.h"
#include "GLFWStarterProject/ControlPoints.h"
#include "GLFWStarterProject/Sphere.h"
//#include "Sphere.h"
using namespace std;
class Window
{
public:
	static GLuint loadCubemap(vector<const GLchar*> faces);
	vector<const GLchar*> textures_faces;
	static glm::mat4 initialheight;
	static OBJObject* curr;
	static bool win;
	static bool leftclick;
	static bool rightclick;
	static GLfloat pointsize;
	static bool shift;
	static int width;
	static int height;
	static glm::mat4 P; // P for projection
	static glm::mat4 V; // V for view
	static void initialize_objects();
	static void clean_up();
	static GLFWwindow* create_window(int width, int height);
	static void resize_callback(GLFWwindow* window, int width, int height);
	static void idle_callback();
	static void display_callback(GLFWwindow*);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static glm::vec3 trackBallMapping(int x, int y);
	static glm::vec3 mousepos;
	static bool getcurpos;
	static double curscroll;
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	GLuint cubemapTexture;
	static glm::mat4 rotmatr;
	static float rot;
	static glm::mat4 rotmatrneg;
	static float rotneg;
	static bool m;
	static bool rotboo;
	static int counter;
	static bool direction;
	static bool controlPointClicked;
	static GLuint cubmapTexture;
};

#endif
