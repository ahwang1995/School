#include "GLFW_Rasterizer.h"
	static int window_width = 512, window_height = 512;
	static float* pixels = new float[window_width * window_height * 3];

	//using namespace std;
	//OBJObject* rascurr = Window::initialize_objects();
	struct Color    // generic color class
	{
		float r, g, b;  // red, green, blue
	};

	void loadData()
	{
		// point cloud parser goes here
	}

	// Clear frame buffer
	void clearBuffer()
	{
		Color clearColor = { 0.0, 0.0, 1.0 };   // clear color: black
		for (int i = 0; i < window_width*window_height; ++i)
		{
			pixels[i * 3] = clearColor.r;
			pixels[i * 3 + 1] = clearColor.g;
			pixels[i * 3 + 2] = clearColor.b;
		}
	}

	// Draw a point into the frame buffer
	void drawPoint(int x, int y, float r, float g, float b)
	{
		int offset = y*window_width * 3 + x * 3;
		pixels[offset] = r;
		pixels[offset + 1] = g;
		pixels[offset + 2] = b;
	}

	void rasterize()
	{
		// Put your main rasterization loop here
		// It should go over the point model and call drawPoint for every point in it
		glm::vec3 e = glm::vec3(0, 0, 20);
		glm::vec3 d = glm::vec3(0, 0, 0);
		glm::vec3 up = glm::vec3(0, 1, 0);
		glm::mat4 C_inverse = glm::lookAt(e, d, up);
		glm::mat4 P = glm::perspective(glm::radians(60.0f), (float)window_width / (float)window_height, 1.0f, 1000.0f);
		glm::mat4 D((float)Window::width / 2.0f,0.0f,0.0f,0.0f,0.0f, (float)Window::height / 2.0f,
						0.0f,0.0f,0.0f,0.0f,1.0f/2.0f,0.0f,(float)Window::width / 2.0f, (float)Window::height / 2.0f,
						1.0f/2.0f, 1.0f);
		glm::mat4 M = Window::curr->toWorld;
		glm::mat4 a = D*P*C_inverse*M;
		for (unsigned int i = 0; i < Window::curr->vertices.size(); ++i)
		{
			glm::vec4 p = glm::vec4(Window::curr->vertices[i].x, Window::curr->vertices[i].y, Window::curr->vertices[i].z, 1);
			glm::vec4 todraw = a*p;
			if ((todraw.x / todraw.w > 0) && (todraw.y / todraw.w > 0) && (todraw.x / todraw.w < window_width) && (todraw.y / todraw.w < window_height))
			{
				drawPoint(todraw.x / todraw.w, todraw.y / todraw.w,
					(Window::curr->normals[i].x + 1.0f) / 2.0f, (Window::curr->normals[i].y + 1.0f) / 2.0f, (Window::curr->normals[i].z + 1.0f) / 2.0f);

				for (int a = -Window::pointsize / 2; a < Window::pointsize; a++)
				{
					for (int b = -a; b < Window::pointsize; b++)
					{
						if (((todraw.x / todraw.w)+ a > 0) && ((todraw.y / todraw.w) + b > 0) && ((todraw.x / todraw.w) + a < window_width) && ((todraw.y / todraw.w) + b < window_height))
						{
							drawPoint((todraw.x / todraw.w) + a, (todraw.y / todraw.w) + b,
								(Window::curr->normals[i].x + 1.0f) / 2.0f, (Window::curr->normals[i].y + 1.0f) / 2.0f, (Window::curr->normals[i].z + 1.0f) / 2.0f);
						}
					}
				}
			}
		}
	}

	// Called whenever the window size changes
	void GLFW_Rasterizer::resizeCallback(GLFWwindow* window, int width, int height)
	{
		window_width = width;
		window_height = height;
		delete[] pixels;
		pixels = new float[window_width * window_height * 3];
	}

	void GLFW_Rasterizer::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		// Check for a key press
		if (action == GLFW_PRESS /* TODO REMOVE FROM STARTER */ || action == GLFW_REPEAT)
		{
			// Check if escape was pressed
			if (key == GLFW_KEY_ESCAPE)
			{
				// Close the window. This causes the program to also terminate.
				glfwSetWindowShouldClose(window, GL_TRUE);
			}
		}
	}

	void GLFW_Rasterizer::displayCallback(GLFWwindow* window)
	{
		if (Window::win) {
			clearBuffer();
			rasterize();

			// glDrawPixels writes a block of pixels to the framebuffer
			glDrawPixels(Window::width, Window::height, GL_RGB, GL_FLOAT, pixels);

			// Gets events, including input such as keyboard and mouse or window resizing
			glfwPollEvents();
			// Swap buffers
			glfwSwapBuffers(window);
		}
		else if (!Window::win) {
			Window::display_callback(window);
		}
	}

	void GLFW_Rasterizer::errorCallback(int error, const char* description)
	{
		// Print error
		fputs(description, stderr);
	}

