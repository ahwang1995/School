#include "window.h"

const char* window_title = "GLFW Starter Project";
GLint shaderProgram, selectionShader, reflectShader,roadshaderProgram,
	groundshaderProgram, storeshaderProgram, houseshaderProgram, parkshaderProgram, particleShader, 
	carShader, textShader, carboxShader, boxShader, itemShader,speeditemshader;
GLuint particleTexture, carDiffuse, carSpecular;

// On some systems you need to change this to the absolute path
#define VERTEX_SHADER_PATH "../shader.vert"
#define FRAGMENT_SHADER_PATH "../shader.frag"
//to track where the car is
glm::vec3 Window::carPosition;
glm::vec3 Window::carSize;
glm::vec3 Window::itemPosition;
//stores all bounding box positions
std::vector<glm::vec3> Window::boxPositions;
std::vector<glm::vec3> Window::boxSizes;
std::vector<BoundingBox*> Window::boxlist;
std::vector<glm::vec3> Window::itemPositions;
std::vector<glm::vec3> Window::itemSizes;
std::vector<Cube*> Window::items;
std::vector<BoundingBox*> Window::itemboxes;
std::vector<glm::vec3> Window::speeditemPositions;
std::vector<glm::vec3> Window::speeditemSizes;
std::vector<Cube*> Window::speeditems;
std::vector<BoundingBox*> Window::speeditemboxes;
Group* Window::itemboundingboxes = new Group();
Group* Window::itemgroup = new Group();
Group* Window::speeditemgroup = new Group();
Group* Window::speeditemboundingboxes = new Group();
Group* carGroup;
BoundingBox* Window::carBox;
bool Window::showparticles;
int Window::particletimer;
MatrixTransform * transPe;

int Window::width;
int Window::height;

glm::mat4 Window::P;
glm::mat4 Window::V;

glm::vec3 lastPoint;
glm::vec3 mouse_pos;

bool Window::showboxes = false;
GLuint currPoint = 0;

double poffset;

//hmwk 3
GLuint cubemapTexture;
float zoom = 45.0f;

//hmwk 5
Group* world;
City* city;
Car* car;

// Setup skybox VAO
GLuint skyboxVAO, skyboxVBO;
GLint skyboxShader;

Camera camera(glm::vec3(0.0f, 10.0f, 0.0f));
GLfloat lastX = Window::width / 2.0;
GLfloat lastY = Window::height / 2.0;
bool keys[1024];

// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame

bool mouse_left_pressed = false;

int mode = 1;	//MODE 0 = FREE ROAM, 1 = LOOK AT CAR
const float PI = 3.1415926535;

std::map<GLchar, Character> Characters;
GLuint textVAO, textVBO;

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

void Window::initialize_objects()
{
	std::vector<const GLchar*> faces;
	faces.push_back("../sky_right.png");
	faces.push_back("../sky_left.png");
	faces.push_back("../sky_up.png");
	faces.push_back("../sky_down.png");
	faces.push_back("../sky_back.png");
	faces.push_back("../sky_front.png");
	cubemapTexture = loadCubemap(faces);

	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glBindVertexArray(0);

	skyboxShader = LoadShaders("../skyshader.vert", "../skyshader.frag");

	// Load the shader program. Make sure you have the correct filepath up top
	shaderProgram = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	roadshaderProgram = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	groundshaderProgram = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	storeshaderProgram = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	houseshaderProgram = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	parkshaderProgram = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	itemShader = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	speeditemshader = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

	selectionShader = LoadShaders("./selectionShader.vert", "./selectionShader.frag");
	reflectShader = LoadShaders("./reflectShader.vert", "./reflectShader.frag");
	particleShader = LoadShaders("./particleShader.vert", "./particleShader.frag");

	//Set up the world
	world = new Group();

	//Testing the particle emitter!
	glGenTextures(1, &particleTexture);
	int width, height;
	unsigned char* image;
	image = SOIL_load_image("../woodText.png", &width, &height, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, particleTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	showparticles = 0;
	ParticleEmitter* pe = new ParticleEmitter(particleShader, particleTexture, 10000);
	transPe = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,-50.0f,0.0f)));
	transPe->addChild(pe);
	particletimer = 0;
	world->addChild(transPe);

	//car bounding box
	carSize = glm::vec3(2.0f, 2.0f, 2.0f);
	//carGroup = new Group();
	carboxShader = LoadShaders("../simpleShader.vert", "../simpleShader.frag");
	carBox = new BoundingBox(carboxShader);
	MatrixTransform* carboxSize = new MatrixTransform(glm::scale(glm::mat4(1.0f), Window::carSize));
	carboxSize->addChild(carBox);

	//Set up car
	Group* carObj = createCarObject();
	car = new Car(glm::vec3(0, 2, 0), carObj, carShader, carDiffuse, carSpecular, carboxSize,pe);

	//Add all objects to world
	city = new City(shaderProgram,roadshaderProgram,groundshaderProgram,
		storeshaderProgram,houseshaderProgram,parkshaderProgram, carboxShader,itemShader, speeditemshader);
	world->addChild(city);

	world->addChild(car);


	//Text set up
	// Compile and setup the shader
	textShader = LoadShaders("./textShader.vert", "./textShader.frag");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(width), 0.0f, static_cast<GLfloat>(height));
	glUseProgram(textShader);
	glUniformMatrix4fv(glGetUniformLocation(textShader, "projection"), 1, GL_FALSE, &(projection[0][0]));

	// FreeType
	FT_Library ft;
	// All functions return a value different than 0 whenever an error occurred
	if (FT_Init_FreeType(&ft))
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

	// Load font as face
	FT_Face face;
	if (FT_New_Face(ft, "./fonts/arial.ttf", 0, &face))
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

	// Set size to load glyphs as
	FT_Set_Pixel_Sizes(face, 0, 48);

	// Disable byte-alignment restriction
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Load first 128 characters of ASCII set
	for (GLubyte c = 0; c < 128; c++)
	{
		// Load character glyph 
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
			continue;
		}
		// Generate texture
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
		);
		// Set texture options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// Now store character for later use
		Character character = {
			texture,
			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			face->glyph->advance.x
		};
		Characters.insert(std::pair<GLchar, Character>(c, character));
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	// Destroy FreeType once we're finished
	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	// Configure VAO/VBO for texture quads
	glGenVertexArrays(1, &textVAO);
	glGenBuffers(1, &textVBO);
	glBindVertexArray(textVAO);
	glBindBuffer(GL_ARRAY_BUFFER, textVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Group* Window::createCarObject() {
	//Shader
	carShader = LoadShaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
	
	//Set up the textures
	glGenTextures(1, &carDiffuse);
	glGenTextures(1, &carSpecular);
	generateMap("../carTextureBig.png", carDiffuse);
	generateMap("../nospecular.png", carSpecular);
	glUseProgram(carShader);
	glUniform1i(glGetUniformLocation(carShader, "material.diffuse"), 14);
	glUniform1i(glGetUniformLocation(carShader, "material.specular"), 15);

	//Lower part
	float texVals[6] = { 0,0,0,0,0,1 };
	Cube* carLower = new Cube(carShader, texVals);
	MatrixTransform* lowerScale = new MatrixTransform(glm::scale(glm::mat4(1.0f), glm::vec3(2.0f,1.2f,1.2f)));
	lowerScale->addChild(carLower);

	//Upper part

	//Create the cubes
	Group* carObject = new Group();
	carObject->addChild(lowerScale);
	return carObject;
}

void Window::generateMap(const char* file, GLuint map)
{
	int width, height;
	unsigned char* image;
	// BuildingDiffuse map
	image = SOIL_load_image(file, &width, &height, 0, SOIL_LOAD_RGB);
	glBindTexture(GL_TEXTURE_2D, map);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
}

void Window::setShaders(GLuint shaderProgram)
{
	glUseProgram(shaderProgram);
	GLuint uColor = glGetUniformLocation(shaderProgram, "objectColor");
	GLuint uLightColor = glGetUniformLocation(shaderProgram, "lightColor");
	GLuint uLightPos = glGetUniformLocation(shaderProgram, "lightPos");
	GLuint uCamPos = glGetUniformLocation(shaderProgram, "viewPos");
	GLfloat lightColour[3] = { 1, 1, 1 };
	glUniform3fv(uLightColor, 1, lightColour);
	GLfloat lightPos[3] = { 0, 50, 0 };
	glUniform3fv(uLightPos, 1, lightColour);
	glm::vec3 temp = Window::getCamPos();
	GLfloat * camPos = &temp.x;
	glUniform3fv(uCamPos, 1, camPos);
}

GLuint Window::loadCubemap(std::vector<const GLchar*> faces)
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);

	int width, height;
	unsigned char* image;

	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	for (GLuint i = 0; i < faces.size(); i++)
	{
		image = SOIL_load_image(faces[i], &width, &height, 0, SOIL_LOAD_RGB);
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

// Treat this as a destructor function. Delete dynamically allocated memory here.
void Window::clean_up()
{
	//delete(cube);
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
		//P = glm::perspective(camera.Zoom, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
		//V = camera.GetViewMatrix();
	}
}

void Window::idle_callback()
{
	// Call the update function the cube
	world->update(deltaTime);
}

void Window::display_callback(GLFWwindow* window)
{
	// Calculate deltatime of current frame
	GLfloat currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	do_movement();

	car->processKeys(keys[GLFW_KEY_UP], keys[GLFW_KEY_DOWN], keys[GLFW_KEY_LEFT], keys[GLFW_KEY_RIGHT]);

	//Update V and P
	// Make sure we are modifying the MODELVIEW matrix.
	//glMatrixMode(GL_MODELVIEW);
	if(mode == 0) V = camera.GetViewMatrix();
	else if (mode == 1) V = car->getView();
	P = glm::perspective(glm::radians(camera.Zoom), (float)width / (float)height, 0.1f, 1000.0f);

	// Clear the color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw skybox first
	glDepthMask(GL_FALSE);// Remember to turn depth writing off
	glUseProgram(skyboxShader);
	glm::mat4 view = glm::mat4(glm::mat3(V));	// Remove any translation component of the view matrix
	glm::mat4 projection = glm::perspective(zoom, (float)width / (float)height, 0.1f, 100.0f);
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader, "view"), 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader, "projection"), 1, GL_FALSE, &projection[0][0]);
	// skybox cube
	glBindVertexArray(skyboxVAO);
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(glGetUniformLocation(skyboxShader, "skybox"), 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthMask(GL_TRUE);
	setLights(shaderProgram);
	setLights(roadshaderProgram);
	setLights(groundshaderProgram);
	setLights(storeshaderProgram);
	setLights(houseshaderProgram);
	setLights(parkshaderProgram);
	setLights(itemShader);

	setLights(carboxShader);

	setLights(carShader);
	setLights(speeditemshader);
	// Render all objects in the world
	if (showparticles)
	{
		transPe->changeMat(glm::translate(glm::mat4(1.0f), itemPosition));
		particletimer++;
	}
	world->draw(V);

	//Draw text
	//RenderText(textShader, "This is sample text", 5.0f, 5.0f, 0.1f, glm::vec3(0.0, 0.0f, 0.0f));

	// Swap buffers
	glfwSwapBuffers(window);

	// Gets events, including input such as keyboard and mouse or window resizing
	glfwPollEvents();
}
void Window::setLights(GLuint shaderProgram)
{
	glUseProgram(shaderProgram);
	// Set material properties
	glUniform1f(glGetUniformLocation(shaderProgram, "material.shininess"), 32.0f);
	// Directional light
	glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
	glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.ambient"), 0.9f, 0.9f, 0.9f);
	glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.diffuse"), 0.4f, 0.4f, 0.4f);
	glUniform3f(glGetUniformLocation(shaderProgram, "dirLight.specular"), 0.5f, 0.5f, 0.5f);
	// Point light 1
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].position"), 0.0f, 5.0f, 0.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(shaderProgram, "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[0].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[0].linear"), 0.09);
	glUniform1f(glGetUniformLocation(shaderProgram, "pointLights[0].quadratic"), 0.032);
	// SpotLight
	glUniform3f(glGetUniformLocation(shaderProgram, "spotLights[0].position"), camera.Position.x, camera.Position.y, camera.Position.z);
	glUniform3f(glGetUniformLocation(shaderProgram, "spotLights[0].direction"), camera.Front.x, camera.Front.y, camera.Front.z);
	glUniform3f(glGetUniformLocation(shaderProgram, "spotLights[0].ambient"), 0.0f, 0.0f, 0.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "spotLights[0].diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(shaderProgram, "spotLights[0].specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLights[0].constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLights[0].linear"), 0.09);
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLights[0].quadratic"), 0.032);
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLights[0].cutOff"), glm::cos(glm::radians(12.5f)));
	glUniform1f(glGetUniformLocation(shaderProgram, "spotLights[0].outerCutOff"), glm::cos(glm::radians(15.0f)));
}
void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Key input
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
	if (key == GLFW_KEY_M && action == GLFW_PRESS) {
		mode = (mode + 1) % 2;
	}
	if (key == GLFW_KEY_R && action == GLFW_PRESS) {
		city->generate();
	}
	if (key == GLFW_KEY_B && action == GLFW_PRESS) {
		if (showboxes == false) showboxes = true;
		else showboxes = false;
	}
}

void Window::do_movement()
{
	// Camera controls
	if (keys[GLFW_KEY_W])
		camera.ProcessKeyboard(FORWARD, deltaTime, keys[GLFW_KEY_LEFT_SHIFT]);
	if (keys[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime, keys[GLFW_KEY_LEFT_SHIFT]);
	if (keys[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime, keys[GLFW_KEY_LEFT_SHIFT]);
	if (keys[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime, keys[GLFW_KEY_LEFT_SHIFT]);
}

bool firstMouse = true;
void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left

	lastX = xpos;
	lastY = ypos;
	if (mouse_left_pressed) {
		camera.ProcessMouseMovement(xoffset, yoffset);
	}
}

void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		mouse_left_pressed = true;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		mouse_left_pressed = false;
	}
}

glm::vec3 Window::trackBallMapping(glm::vec3 point)    // The CPoint class is a specific Windows class. Either use separate x and y values for the mouse location, or use a Vector3 in which you ignore the z coordinate.
{
	glm::vec3 v;    // Vector v is the synthesized 3D position of the mouse location on the trackball
	float d;     // this is the depth of the mouse location: the delta between the plane through the center of the trackball and the z position of the mouse
	v.x = (2.0*point.x - Window::width) / Window::width;   // this calculates the mouse X position in trackball coordinates, which range from -1 to +1
	v.y = (Window::height - 2.0*point.y) / Window::height;   // this does the equivalent to the above for the mouse Y position
	v.z = 0.0;   // initially the mouse z position is set to zero, but this will change below
	d = mag(v);    // this is the distance from the trackball's origin to the mouse location, without considering depth (=in the plane of the trackball's origin)
	d = (d < 1.0) ? d : 1.0;   // this limits d to values of 1.0 or less to avoid square roots of negative values in the following line
	v.z = sqrtf(1.001 - d*d);  // this calculates the Z coordinate of the mouse position on the trackball, based on Pythagoras: v.z*v.z + d*d = 1*1
	normalize(v); // Still need to normalize, since we only capped d, not v.
	return v;  // return the mouse location on the surface of the trackball
}

float Window::mag(glm::vec3 vec) {
	float mag = vec.x * vec.x;
	mag += vec.y * vec.y;
	mag += vec.z * vec.z;
	mag = sqrt(mag);
	return mag;
}

glm::vec3 Window::getCamPos() {
	if (mode == 1) return car->getCamPos();
	else return camera.Position;
}

void Window::RenderText(GLuint shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color)
{
	// Activate corresponding render state	
	glUseProgram(shader);
	glUniform3f(glGetUniformLocation(shader, "textColor"), color.x, color.y, color.z);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(textVAO);

	// Iterate through all characters
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = Characters[*c];

		GLfloat xpos = x + ch.Bearing.x * scale;
		GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

		GLfloat w = ch.Size.x * scale;
		GLfloat h = ch.Size.y * scale;
		// Update VBO for each character
		GLfloat vertices[6][4] = {
			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos,     ypos,       0.0, 1.0 },
			{ xpos + w, ypos,       1.0, 1.0 },

			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos + w, ypos,       1.0, 1.0 },
			{ xpos + w, ypos + h,   1.0, 0.0 }
		};
		// Render glyph texture over quad
		glBindTexture(GL_TEXTURE_2D, ch.TextureID);
		// Update content of VBO memory
		glBindBuffer(GL_ARRAY_BUFFER, textVBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Be sure to use glBufferSubData and not glBufferData

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// Render quad
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += (ch.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}