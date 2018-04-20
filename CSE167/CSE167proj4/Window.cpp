#define _CRT_SECURE_NO_DEPRECATE
#include "window.h"
#include <string>
#include <SOIL.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
const char* window_title = "GLFW Starter Project";
Cube * cube;
Bound * bound;
float speed;
int whichcurve;
int whichvertice;
int currcurve;
int currvertice;
//Sphere * sphere;
GLint shaderProgram;
GLint shaderProgram2;
GLint shaderProgram3;
GLint shaderProgram4;
GLint shaderProgram5;
static GLuint SkyboxVAO, SkyboxVBO;
// On some systems you need to change this to the absolute path
#define VERTEX_SHADER_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/shader.vert"
#define FRAGMENT_SHADER_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/shader.frag"
#define SKYBOX_VERTEX_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/shaderskybox.vert"
#define SKYBOX_FRAGMENT_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/shaderskybox.frag"
#define ChooseCP_VERTEX_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/ChooseCP.vert"
#define ChooseCP_FRAGMENT_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/ChooseCP.frag"
#define oddShader_VERTEX_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/oddshader.vert"
#define oddShader_FRAGMENT_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/oddshader.frag"
#define reflectionshader_VERTEX_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/reflectionshader.vert"
#define reflectionshader_FRAGMENT_PATH "C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/reflectionshader.frag"

// Default camera parameters
glm::vec3 cam_pos(0.0f, 0.0f, 20.0f);		// e  | Position of camera
glm::vec3 cam_look_at(0.0f, 0.0f, 0.0f);	// d  | This is where the camera looks at
glm::vec3 cam_up(0.0f, 1.0f, 0.0f);			// up | What orientation "up" is
glm::vec3 Window::mousepos;
glm::mat4 Window::rotmatr;
float Window::rot;
glm::mat4 Window::rotmatrneg;
float Window::rotneg;
double Window::curscroll = 0.0;
int Window::width;
int Window::height;
bool Window::shift;
bool Window::win;
bool Window::leftclick;
bool Window::rightclick;
bool Window::getcurpos;
bool Window::m;
bool Window::rotboo;
int Window::counter;
bool Window::direction;
bool Window::controlPointClicked;
glm::mat4 Window::initialheight;
//GLfloat fov = 45.0f;
GLfloat Window::pointsize = 1.0f;

glm::mat4 Window::P;
glm::mat4 Window::V;
GLuint Window::cubmapTexture;
OBJObject * Window::curr;
OBJObject * bunny;
OBJObject * bear;
OBJObject * dragon;
Group * bezwah;
int location;
int cplocation;
ControlPoints * selectedPoint;
BezierCurve * selectedCurve;
glm::vec3 ctrlPoints[40];
BezierCurve * curvearray[10];
ControlPoints * controlarray[40];
Group * Points;
Sphere * sphere;
MatrixTransform* spherematrix;
float ratio;
float Hnear;
float Wnear;
Group * spheregroup;
void Window::initialize_objects()
{
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

	//OBJObject bear("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/bear.obj");
	//OBJObject bunny("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/bunny.obj");
	//OBJObject dragon("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/dragon.obj");
	//curr = &bunny;
	bunny = new OBJObject("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/bunny.obj");
	bear = new OBJObject("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/bear.obj");
	dragon = new OBJObject("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/dragon.obj");
	//sphere = new Sphere();
	curr = bunny;
	vector<const GLchar*> textures_faces;
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/midnight-silence_bk.jpg");//good
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/midnight-silence_ft.jpg");
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/midnight-silence_lf.jpg");//good
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/midnight-silence_rt.jpg");
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/midnight-silence_dn.jpg");
	textures_faces.push_back("C:\\Users\\Andrew\\Desktop\\School\\Computer Science\\CSE 167\\CSE167StarterCode2-master\\CSE167StarterCode2-master/midnight-silence_up.jpg");//good
	// Load the shader program. Make sure you have the correct filepath up top
	shaderProgram = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	shaderProgram2 = LoadShaders(SKYBOX_VERTEX_PATH, SKYBOX_FRAGMENT_PATH);
	shaderProgram3 = LoadShaders(ChooseCP_VERTEX_PATH, ChooseCP_FRAGMENT_PATH);
	shaderProgram4 = LoadShaders(oddShader_VERTEX_PATH, oddShader_FRAGMENT_PATH);
	shaderProgram5 = LoadShaders(reflectionshader_VERTEX_PATH, reflectionshader_FRAGMENT_PATH);
	glGenVertexArrays(1, &SkyboxVAO);
	glGenBuffers(1, &SkyboxVBO);
	glBindVertexArray(SkyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, SkyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glBindVertexArray(0);
	m = false;
	rotboo = false;
	speed = 0;
	cubmapTexture = loadCubemap(textures_faces);
	int cpindex = 0;
	for (int c = 0; c < 360;)
	{
		if (cpindex % 4 == 2 || cpindex % 4 == 1)
		{
			glm::vec3 circlepoint = glm::vec3(10 * (float)cos(c), 10 * (float)sin(c),( rand() % 20) - 10);
			ctrlPoints[cpindex] = circlepoint;
			c += 18;
		}
		cpindex++;
	}
	for (int i = 4; i < 40; i += 4)
	{
		ctrlPoints[i] = (ctrlPoints[i - 2] + ctrlPoints[i + 1]) / 2.0f;
		ctrlPoints[i-1] = (ctrlPoints[i - 2] + ctrlPoints[i + 1]) / 2.0f;
	}
	ctrlPoints[0] = (ctrlPoints[38] + ctrlPoints[1]) / 2.0f;
	ctrlPoints[39] = (ctrlPoints[38] + ctrlPoints[1]) / 2.0f;
	bezwah = new Group();
	int curveindex = 0;
	for (int i = 0; i < 40; i += 4)
	{
		BezierCurve * tempbez = new BezierCurve(ctrlPoints[i], ctrlPoints[i + 1], ctrlPoints[i + 2], ctrlPoints[i + 3],shaderProgram4);
		bezwah->addChild(tempbez);
		curvearray[curveindex] = tempbez;
		curveindex++;
	}
	Points = new Group();
	int pointindex = 0;
	for (int i = 0; i < 40; i++)
	{
		ControlPoints * control = new ControlPoints(shaderProgram3, ctrlPoints[i], i+1);
		Points->addChild(control);
		controlarray[pointindex] = control;
		pointindex++;
	}
	sphere = new Sphere(shaderProgram4);
	float bezierheight = -9999.0f;
	whichcurve = 0;
	whichvertice = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < curvearray[i]->Bezvertices.size(); j++)
		{
			if (curvearray[i]->Bezvertices[j].z > bezierheight)
			{
				bezierheight = curvearray[i]->Bezvertices[j].z;
				whichcurve = i;
				whichvertice = j;
			}
		}
	}
	currcurve = whichcurve;
	currvertice = whichvertice;
	spheregroup = new Group();
	//spherematrix = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(30.0f,0.0f,0.0f)));
	spherematrix = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(curvearray[whichcurve]->Bezvertices[whichvertice].x, curvearray[whichcurve]->Bezvertices[whichvertice].y, curvearray[whichcurve]->Bezvertices[whichvertice].z)));
	spherematrix->addChild(sphere);
	spheregroup->addChild(spherematrix);

}

// Treat this as a destructor function. Delete dynamically allocated memory here.
void Window::clean_up()
{
	//delete(cube);
	delete(curr);
	glDeleteProgram(shaderProgram);
	glDeleteProgram(shaderProgram2);
}

GLFWwindow* Window::create_window(int width, int height)
{
	// Initialize GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return NULL;
	}
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
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

}
GLuint Window::loadCubemap(vector<const GLchar*> textures_faces)
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
}
void Window::display_callback(GLFWwindow* window)
{
	//P = glm::perspective(fov, (float)width / (float)height, 0.1f, 1000.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDepthMask(GL_FALSE);
	//shaderProgram.Use();
	glUseProgram(shaderProgram2);
	glm::mat4 view = glm::mat4(glm::mat3(V));
	glm::mat4 projection = glm::mat4(P);
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram2, "view"), 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram2, "projection"), 1, GL_FALSE, &projection[0][0]);
	glBindVertexArray(SkyboxVAO);
	glActiveTexture(GL_TEXTURE0);
	// ... Set view and projection matrix
	glUniform1i(glGetUniformLocation(shaderProgram2, "skybox"), 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubmapTexture);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthMask(GL_TRUE);
	// Clear the color and depth buffers

	// Use the shader of programID
	glUseProgram(shaderProgram4);
	bezwah->draw(V);
	if (speed < 100)
	{
		speed += sqrt(2 * ((curvearray[whichcurve]->Bezvertices[whichvertice].z)-(curvearray[currcurve]->Bezvertices[currvertice].z))) + 1.0f;
	}
	else
	{
		if (currvertice < curvearray[currcurve]->Bezvertices.size())
		{
			currvertice++;
		}
		else if (currcurve < 9)
		{
			currcurve++;
			currvertice = 0;
		}
		else
		{
			currcurve = 0;
			currvertice = 0;
		}
		spherematrix = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(curvearray[currcurve]->Bezvertices[currvertice].x, curvearray[currcurve]->Bezvertices[currvertice].y, curvearray[currcurve]->Bezvertices[currvertice].z)));
		speed = 0;
	}
	spheregroup->draw(V);
	//Handles->draw(V);
	//Points->draw(V);
	// Gets events, including input such as keyboard and mouse or window resizing
	//glfwPollEvents();
	// Swap buffers
	glfwSwapBuffers(window);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shaderProgram3);
	Points->draw(V);
	glfwPollEvents();
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
		if (key == GLFW_KEY_M)
		{
			if (m == true)
			{
				m = false;
			}
			else if (m == false)
			{
				m = true;
			}
		}
		if (key == GLFW_KEY_A)
		{
			/*for (int i = -5; i < 5; i++)
			{
				for (int j = -5; j < 5; j++)
				{
					armymatr = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(i*10.0f,0.0f,j*10.0f)));
					armymatr->addChild(robot);
					manyrobots->addChild(armymatr);
				}
			}*/
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
		if (key == GLFW_KEY_H)
		{
			spherematrix = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(curvearray[whichcurve]->Bezvertices[whichvertice].x, curvearray[whichcurve]->Bezvertices[whichvertice].y, curvearray[whichcurve]->Bezvertices[whichvertice].z)));
			speed = 0;
			currcurve = whichcurve;
			currvertice = whichvertice;
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
		//glUseProgram(shaderProgram3);
		//Points->draw(V);
		unsigned char pix[4];
		glReadPixels(xpos,height-ypos,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&pix);
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
		if ((unsigned int)pix[0] > 0 && controlPointClicked == false)
		{
			controlPointClicked = true;
			location = ((unsigned int)pix[0]) - 1;
			cout << location << "\n";
			cplocation = location % 4;
		}
		if(controlPointClicked)
		{
			/*location = (unsigned int)pix[0] - 1;
			cplocation = location % 4;
			selectedPoint = controlarray[location];
			selectedCurve = curvearray[location / 4];*/
			if (cplocation == 0)
			{
				if (velocity > .0001)
				{
					controlarray[location]->editPoint(direction);
					curvearray[location / 4]->editPoint(direction, 0);
					controlarray[(location + 39) % 40]->editPoint(direction);
					controlarray[(location + 38) % 40]->editPoint(direction);
					controlarray[(location + 1) % 40]->editPoint(direction);
					curvearray[(location / 4)]->editPoint(direction,1);
					curvearray[((location / 4) + 9) % 10]->editPoint(direction, 3);
					curvearray[((location / 4) + 9) % 10]->editPoint(direction, 2);
				}
			}
			else if (cplocation == 3)
			{
				if (velocity > .0001)
				{
					controlarray[location]->editPoint(direction);
					curvearray[location / 4]->editPoint(direction, 3);
					controlarray[(location + 39) % 40]->editPoint(direction);
					controlarray[(location + 2) % 40]->editPoint(direction);
					controlarray[(location + 1) % 40]->editPoint(direction);
					curvearray[(location / 4)]->editPoint(direction, 2);
					curvearray[((location / 4) + 1) % 10]->editPoint(direction, 0);
					curvearray[((location / 4) + 1) % 10]->editPoint(direction, 1);
				}
			}
			else if (cplocation == 1)
			{
				if (velocity > .0001)
				{
					controlarray[location]->editPoint(direction);
					curvearray[location / 4]->editPoint(direction, 1);
					controlarray[(location + 37) % 40]->editPoint(-direction);
					curvearray[((location / 4) + 9) % 10]->editPoint(-direction, 2);
				}
			}
			else if (cplocation == 2)
			{
				if (velocity > .0001)
				{
					controlarray[location]->editPoint(direction);
					curvearray[location / 4]->editPoint(direction, 2);
					controlarray[(location + 3) % 40]->editPoint(-direction);
					curvearray[((location / 4) + 1) % 10]->editPoint(-direction, 1);
				}
			}
		}
		else if (velocity > .0001 && controlPointClicked == false)
		{
			glm::vec3 rotAxis;
			rotAxis = glm::cross(mousepos, curPoint);
			rot_angle =  velocity*100.0f;
			glm::mat4 rotmatr = glm::rotate(glm::mat4(1.0f), rot_angle/ 180.0f * glm::pi<float>(), rotAxis);
			V =  V*rotmatr;

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
			V = glm::translate(glm::mat4(1.0f), transvect) * V;
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
			controlPointClicked = false;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			rightclick = false;
		}
	}
	

}
void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
		V = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, yoffset/2)) * V;
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