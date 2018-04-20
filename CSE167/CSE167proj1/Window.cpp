#include "Window.h"


const char* window_title = "GLFW Starter Project";
//Cube cube(5.0f);
OBJObject bear("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode-master\\CSE167StarterCode-master/bear.obj");
OBJObject bunny("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode-master\\CSE167StarterCode-master/bunny.obj");
OBJObject dragon("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode-master\\CSE167StarterCode-master/dragon.obj");
OBJObject * Window::curr = &bunny;

int Window::width;
int Window::height;
bool Window::shift;
bool Window::win;
GLfloat Window::pointsize = 1.0f;



OBJObject * Window::initialize_objects()
{
	return curr;
}

void Window::clean_up()
{
	win = 0;
}

GLFWwindow* Window::create_window(int width, int height)
{
	// Initialize GLFW.
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return NULL;
	}

	// 4x antialiasing
	glfwWindowHint(GLFW_SAMPLES, 4);

	// Create the GLFW window
	GLFWwindow* window = glfwCreateWindow(width, height, window_title, NULL, NULL);

	// Check if the window could not be created
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return NULL;
	}

	// Make the context of the window
	glfwMakeContextCurrent(window);

	// Set swap interval to 1
	glfwSwapInterval(1);

	// Call the resize callback to make sure things get drawn immediately
	Window::resize_callback(window, width, height);

	return window;
}

void Window::resize_callback(GLFWwindow* window, int width, int height)
{
	Window::width = width;
	Window::height = height;
	// Set the viewport size
	glViewport(0, 0, width, height);
	// Set the matrix mode to GL_PROJECTION to determine the proper camera properties
	glMatrixMode(GL_PROJECTION);
	// Load the identity matrix
	glLoadIdentity();
	// Set the perspective of the projection viewing frustum
	gluPerspective(60.0, double(width) / (double)height, 1.0, 1000.0);
	// Move camera back 20 units so that it looks at the origin (or else it's in the origin)
	glTranslatef(0, 0, -20);
	GLFW_Rasterizer::resizeCallback(window, width, height);
}

void Window::idle_callback()
{
	// Perform any updates as necessary. Here, we will spin the cube slightly.

	//cube.update();
	(*curr).update();
	
}

bool Window::getwin()
{
	return win;
}
void Window::display_callback(GLFWwindow* window)
{
	if (!win)
	{
	
	// Clear the color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Set the matrix mode to GL_MODELVIEW
	glMatrixMode(GL_MODELVIEW);
	// Load the identity matrix
	glLoadIdentity();

	// Render objects

	//cube.draw();

	(*curr).draw();


	// Gets events, including input such as keyboard and mouse or window resizing
	glfwPollEvents();
	// Swap buffers
	glfwSwapBuffers(window);
	}
	else if (win)
	{
		GLFW_Rasterizer::displayCallback(window);
	}
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
			curr = &bunny;
		}
		if (key == GLFW_KEY_F2)
		{
			curr = &dragon;
		}
		if (key == GLFW_KEY_F3)
		{
			curr = &bear;
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
