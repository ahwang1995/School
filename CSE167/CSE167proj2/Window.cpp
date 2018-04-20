#include "window.h"
#include <string>
#include <time.h>

const char* window_title = "GLFW Starter Project";
Cube * cube;
GLint shaderProgram;

// On some systems you need to change this to the absolute path
#define VERTEX_SHADER_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/shader.vert"
#define FRAGMENT_SHADER_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/shader.frag"

// Default camera parameters
glm::vec3 cam_pos(0.0f, 0.0f, 20.0f);		// e  | Position of camera
glm::vec3 cam_look_at(0.0f, 0.0f, 0.0f);	// d  | This is where the camera looks at
glm::vec3 cam_up(0.0f, 1.0f, 0.0f);			// up | What orientation "up" is
glm::vec3 Window::mousepos;

double Window::curscroll = 0.0;
int Window::width;
int Window::height;
bool Window::shift;
bool Window::win;
bool Window::leftclick;
bool Window::rightclick;
bool Window::getcurpos;
GLfloat Window::pointsize = 1.0f;

glm::mat4 Window::P;
glm::mat4 Window::V;
OBJObject * Window::curr;
OBJObject * bunny;
OBJObject * bear;
OBJObject * dragon;
void Window::initialize_objects()
{
	//OBJObject bear("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/bear.obj");
	//OBJObject bunny("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/bunny.obj");
	//OBJObject dragon("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/dragon.obj");
	//curr = &bunny;
	bunny = new OBJObject("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/bunny.obj");
	bear = new OBJObject("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/bear.obj");
	dragon = new OBJObject("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/dragon.obj");
	//cube = new Cube();
	curr = bunny;
	// Load the shader program. Make sure you have the correct filepath up top
	shaderProgram = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
}

// Treat this as a destructor function. Delete dynamically allocated memory here.
void Window::clean_up()
{
	//delete(cube);
	delete(curr);
	glDeleteProgram(shaderProgram);
}

GLFWwindow* Window::create_window(int width, int height)
{
	// Initialize GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return NULL;
	}

	// 4x antialiasing
	glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__ // Because Apple hates comforming to standards
	// Ensure that minimum OpenGL version is 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Enable forward compatibility and allow a modern OpenGL context
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// Create the GLFW window
	GLFWwindow* window = glfwCreateWindow(width, height, window_title, NULL, NULL);

	// Check if the window could not be created
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		fprintf(stderr, "Either GLFW is not installed or your graphics card does not support modern OpenGL.\n");
		glfwTerminate();
		return NULL;
	}

	// Make the context of the window
	glfwMakeContextCurrent(window);

	// Set swap interval to 1
	glfwSwapInterval(1);

	// Get the width and height of the framebuffer to properly resize the window
	glfwGetFramebufferSize(window, &width, &height);
	// Call the resize callback to make sure things get drawn immediately
	Window::resize_callback(window, width, height);

	return window;
}

void Window::resize_callback(GLFWwindow* window, int width, int height)
{
	Window::width = width;
	Window::height = height;
	// Set the viewport size. This is the only matrix that OpenGL maintains for us in modern OpenGL!
	glViewport(0, 0, width, height);

	if (height > 0)
	{
		P = glm::perspective(45.0f, (float)width / (float)height, 0.1f, 1000.0f);
		V = glm::lookAt(cam_pos, cam_look_at, cam_up);
	}
}

void Window::idle_callback()
{
	// Call the update function the cube
	curr->update();

	//cube->update();
}

void Window::display_callback(GLFWwindow* window)
{
	// Clear the color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use the shader of programID
	glUseProgram(shaderProgram);
	
	// Render the cube
	curr->draw(shaderProgram);
	//cube->draw(shaderProgram);

	// Gets events, including input such as keyboard and mouse or window resizing
	glfwPollEvents();
	// Swap buffers
	glfwSwapBuffers(window);
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Check for a key press
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_LEFT_SHIFT || key == GLFW_KEY_RIGHT_SHIFT)
		{
			shift = true;
		}


		// Check if escape was pressed
		if (key == GLFW_KEY_ESCAPE)
		{
			// Close the window. This causes the program to also terminate.
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		if (key == GLFW_KEY_F1)
		{
			curr = bunny;
		}
		if (key == GLFW_KEY_F2)
		{
			curr = dragon;
		}
		if (key == GLFW_KEY_F3)
		{
			curr = bear;
		}
		if (key == GLFW_KEY_P && !shift)
		{
			if (pointsize > 1)
			{
				pointsize -= 1;
				glPointSize(pointsize);
			}
		}
		if (key == GLFW_KEY_P && shift)
		{
			pointsize += 1;
			glPointSize(pointsize);
		}
		if (key == GLFW_KEY_X && shift)
		{
			curr->moveObject("X");
		}
		if (key == GLFW_KEY_X && !shift)
		{
			curr->moveObject("x");
		}
		if (key == GLFW_KEY_Y && shift)
		{
			curr->moveObject("Y");
		}
		if (key == GLFW_KEY_Y && !shift)
		{
			curr->moveObject("y");
		}
		if (key == GLFW_KEY_Z && shift)
		{
			curr->moveObject("Z");
		}
		if (key == GLFW_KEY_Z && !shift)
		{
			curr->moveObject("z");
		}
		if (key == GLFW_KEY_S && shift)
		{
			curr->moveObject("S");
		}
		if (key == GLFW_KEY_S && !shift)
		{
			curr->moveObject("s");
		}
		if (key == GLFW_KEY_O && shift)
		{
			curr->moveObject("O");
		}
		if (key == GLFW_KEY_O && !shift)
		{
			curr->moveObject("o");
		}
		if (key == GLFW_KEY_R && !shift)
		{
			curr->moveObject("r");
		}
		if (key == GLFW_KEY_W)
		{
			if (win == false)
			{
				win = true;
			}
			else if (win == true)
			{
				win = false;
			}
		}
	}
	if (action == GLFW_RELEASE)
	{
		if (key == GLFW_KEY_LEFT_SHIFT || key == GLFW_KEY_RIGHT_SHIFT)
		{
			shift = false;
		}
	}
}
void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (getcurpos)
	{
		mousepos = trackBallMapping(xpos, ypos);
		getcurpos = false;
	}
	if (leftclick)
	{
		glm::vec3 direction;
		float pixel_diff;
		float rot_angle, zoom_factor;
		glm::vec3 curPoint;
		curPoint = trackBallMapping(xpos, ypos); // Map the mouse position to a logicalS										 // sphere location.
		direction = curPoint - mousepos;
		float velocity = direction.x*direction.x;
		velocity += direction.y*direction.y;
		velocity += direction.z*direction.z;
		velocity = sqrt(velocity);
		if (velocity > .0001)
		{

			glm::vec3 rotAxis;
			rotAxis = glm::cross(mousepos, curPoint);
			/*cout << rotAxis.x << "rotx \n";
			cout << rotAxis.y << "roty \n";
			cout << rotAxis.z << "rotz \n";*/
			rot_angle =  velocity*100.0f;
			glm::mat4 rotmatr = glm::rotate(glm::mat4(1.0f), rot_angle/ 180.0f * glm::pi<float>(), rotAxis);
			curr->toWorld =  rotmatr * curr->toWorld;

			mousepos = curPoint;

		}
	}
	if (rightclick)
	{
		glm::vec3 direction;
		float xdist;
		float ydist;
		glm::vec3 curPoint;
		curPoint = trackBallMapping(xpos, ypos); // Map the mouse position to a logical
											 // sphere location.
		direction = curPoint - mousepos;
		float velocity = sqrt(direction.x*direction.x);
		velocity += sqrt(direction.y*direction.y);
		if (velocity > .0001)
		{
			glm::vec3 transvect;
			transvect = glm::vec3((curPoint.x - mousepos.x)*30.0f, (curPoint.y - mousepos.y)*30.0f, 0.0f);
			curr->toWorld = glm::translate(glm::mat4(1.0f), transvect) * curr->toWorld;
			mousepos = curPoint;
		}
	}
}
void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			getcurpos = true;
			leftclick = true;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			getcurpos = true;
			rightclick = true;
		}
	}
	if (action == GLFW_RELEASE)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			leftclick = false;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			rightclick = false;
		}
	}
	

}
void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	if (curscroll < yoffset)
	{
		curr->toWorld = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 1)) * curr->toWorld;
		curscroll = yoffset;
	}
	if (curscroll > yoffset)
	{
		curr->toWorld = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -1)) * curr->toWorld;
		curscroll = yoffset;
	}
}
glm::vec3 Window::trackBallMapping(int x,int y)    // The CPoint class is a specific Windows class. Either use separate x and y values for the mouse location, or use a Vector3 in which you ignore the z coordinate.
{
	glm::vec3 v;    // Vector v is the synthesized 3D position of the mouse location on the trackball
	float d;     // this is the depth of the mouse location: the delta between the plane through the center of the trackball and the z position of the mouse
	v.x = (2.0*x - width) / width;   // this calculates the mouse X position in trackball coordinates, which range from -1 to +1
	v.y = (height - 2.0*y) /height;   // this does the equivalent to the above for the mouse Y position
	v.z = 0.0;   // initially the mouse z position is set to zero, but this will change below
	//d = v.length(); 
	d = v.x*v.x;
	d += v.y*v.y;
	d += v.z*v.z;// this is the distance from the trackball's origin to the mouse location, without considering depth (=in the plane of the trackball's origin)
	d = sqrt(d);
	d = (d<1.0) ? d : 1.0;   // this limits d to values of 1.0 or less to avoid square roots of negative values in the following line
	v.z = sqrtf(1.001 - d*d);  // this calculates the Z coordinate of the mouse position on the trackball, based on Pythagoras: v.z*v.z + d*d = 1*1
	normalize(v);
	/*v.x = (v.x + 1.0f) / 2.0f;
	v.y = (v.y + 1.0f) / 2.0f;
	v.z = (v.z + 1.0f) / 2.0f;*/
	//v.Normalize(); // Still need to normalize, since we only capped d, not v.
	return v;  // return the mouse location on the surface of the trackball
}