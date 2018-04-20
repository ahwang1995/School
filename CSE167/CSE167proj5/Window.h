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
#include "Cube.h"
#include "GLFWStarterProject/Sphere.h"
#include "GLFWStarterProject/Group.h"
#include "GLFWStarterProject/MatrixTransform.h"
#include <glm/gtc/matrix_transform.hpp>
#include "shader.h"
#include "OBJObject.h"
#include "GLFWStarterProject/BezierCurve.h"
#include "GLFWStarterProject/RollerCoaster.h"
#include "GLFWStarterProject/City.h"
#include "GLFWStarterProject/Camera.h"
#include "GLFWStarterProject/ParticleEmitter.h"
#include "GLFWStarterProject/Car.h"
class BoundingBox;
#include <map>

#include <SOIL.h>

#include <ft2build.h>
#include FT_FREETYPE_H 

/// Holds all state information relevant to a character as loaded using FreeType
struct Character {
	GLuint TextureID;   // ID handle of the glyph texture
	glm::ivec2 Size;    // Size of glyph
	glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
	GLuint Advance;    // Horizontal offset to advance to next glyph
};

#include <vector>

#include <SOIL.h>
#include <iostream>
using namespace std;

class Window
{
public:
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

	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static glm::vec3 Window::trackBallMapping(glm::vec3 point);
	static float Window::mag(glm::vec3 vec);	//hmwk 3
	static void Window::cam_translate(float x, float y, float z);
	static GLuint Window::loadCubemap(std::vector<const GLchar*> faces);
	static void setLights(GLuint shaderProgram);
	//hmwk 4
	static glm::vec3 getCamPos();

	//hwk5
	static void do_movement();
	static Group* createCarObject();
	static void generateMap(const char* file, GLuint map);
	static void setShaders(GLuint shaderProgram);

	//For rendering tex
	static void RenderText(GLuint shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

	//bounding boxes
	static glm::vec3 carPosition;
	static glm::vec3 carSize;
	static glm::vec3 itemPosition;
	static std::vector<glm::vec3> boxPositions;
	static std::vector<glm::vec3> boxSizes;
	static std::vector<BoundingBox*> boxlist;
	static std::vector<glm::vec3> itemPositions;
	static std::vector<glm::vec3> itemSizes;
	static std::vector<Cube*> items;
	static std::vector<BoundingBox*> itemboxes;
	static std::vector<glm::vec3> speeditemPositions;
	static std::vector<glm::vec3> speeditemSizes;
	static std::vector<Cube*> speeditems;
	static std::vector<BoundingBox*> speeditemboxes;
	static Group* speeditemboundingboxes;
	static Group* itemboundingboxes;
	static Group* itemgroup;
	static Group* speeditemgroup;
	static bool showboxes;
	static bool showparticles;
	static int particletimer;
	static BoundingBox* carBox;
};

#endif
