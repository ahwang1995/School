#include "City.h"

const int SIZEX = 50;	//Width and height of city in terms of points (buildings etc)
const int SIZEZ = 50;
const float BLOCKWIDTH = 10;	//Average dist between two points in the grid
const int	RANDRANGE = 3;		//How much the points can vary - also extends the road blocks to fill gaps in roads

const int maxRoads = 120;		//Min and max number of roads
const int minRoads = 100;

const int minPark = 3;			//Min and max (HALF) park size - to ensure park is always centered it adds to either side
const int maxPark = 5;

const int metropSizeMin = 10;	//Size of the metropolis district, which will be in the center of the city
const int metropSizeMax = 15;

const int entrtnSizeMin = 10;	//Size of entertainment district, which will be in a random place in the city
const int entrtnSizeMax = 15;

glm::vec3 grid[SIZEX][SIZEZ];
int roadMap[SIZEX][SIZEZ];
Group* skyscrapers = new Group();
Group* stores = new Group();
Group* houses = new Group();
Group* roads = new Group();
Group* boundingboxes = new Group();
MatrixTransform* park;
MatrixTransform* ground;

GLfloat buildingColor[3] = { 0.7f, 0.7f, 0.7f };
GLuint scraperDiffuseMap, scraperSpecularMap, emissionMap,roadDiffuseMap,roadSpecularMap,groundDiffuseMap,groundSpecularMap,
	storeDiffuseMap, storeSpecularMap, houseDiffuseMap, houseSpecularMap, parkDiffuseMap, parkSpecularMap, itemDiffuseMap, itemSpecularMap
	, speeditemDiffuseMap, speeditemSpecularMap;;
GLuint scraperShaderProgram, roadshaderProgram, groundshaderProgram, storeshaderProgram, houseshaderProgram, parkshaderProgram,
	carboxshaderProgram,itemshaderProgram,speeditemshaderProgram;

City::City(GLuint sp, GLuint roadsp, GLuint groundsp, GLuint storesp, GLuint housesp, GLuint parksp,GLuint carboxsp,GLuint itemsp, GLuint speeditemsp) {
	scraperShaderProgram = sp;
	roadshaderProgram = roadsp;
	groundshaderProgram = groundsp;
	storeshaderProgram = storesp;
	houseshaderProgram = housesp;
	parkshaderProgram = parksp;
	carboxshaderProgram = carboxsp;
	itemshaderProgram = itemsp;
	speeditemshaderProgram = speeditemsp;
	//Generate a city randomly
	generate();

	//Set up the ground
	float groundtexts[6] = { 20.0f,20.0f,20.0f,20.0f,20.0f,20.0f };
	Cube* c = new Cube(groundshaderProgram, groundtexts);
	ground = new MatrixTransform(glm::scale(glm::mat4(1.0f), glm::vec3(BLOCKWIDTH * SIZEX, 1, BLOCKWIDTH * SIZEZ)));
	ground->addChild(c);

	glGenTextures(1, &scraperDiffuseMap);
	glGenTextures(1, &scraperSpecularMap);
	Window::generateMap("../blue_building.png", scraperDiffuseMap);
	Window::generateMap("../nospecular.png", scraperSpecularMap);
	glUseProgram(scraperShaderProgram);
	glUniform1i(glGetUniformLocation(scraperShaderProgram, "material.diffuse"), 1);
	glUniform1i(glGetUniformLocation(scraperShaderProgram, "material.specular"), 2);

	glGenTextures(1, &roadDiffuseMap);
	glGenTextures(1, &roadSpecularMap);
	Window::generateMap("../roadtexture.png", roadDiffuseMap);
	Window::generateMap("../nospecular.png", roadSpecularMap);
	glUseProgram(roadshaderProgram);
	glUniform1i(glGetUniformLocation(roadshaderProgram, "material.diffuse"), 3);
	glUniform1i(glGetUniformLocation(roadshaderProgram, "material.specular"), 4);

	glGenTextures(1, &groundDiffuseMap);
	glGenTextures(1, &groundSpecularMap);
	Window::generateMap("../concrete_rough_0065_01_preview.png", groundDiffuseMap);
	Window::generateMap("../nospecular.png", groundSpecularMap);
	glUseProgram(groundshaderProgram);
	glUniform1i(glGetUniformLocation(groundshaderProgram, "material.diffuse"), 5);
	glUniform1i(glGetUniformLocation(groundshaderProgram, "material.specular"), 6);

	//store
	glGenTextures(1, &storeDiffuseMap);
	glGenTextures(1, &storeSpecularMap);
	Window::generateMap("../store.png", storeDiffuseMap);
	Window::generateMap("../nospecular.png", storeSpecularMap);
	glUseProgram(storeshaderProgram);
	glUniform1i(glGetUniformLocation(storeshaderProgram, "material.diffuse"), 7);
	glUniform1i(glGetUniformLocation(storeshaderProgram, "material.specular"), 8);

	//house
	glGenTextures(1, &houseDiffuseMap);
	glGenTextures(1, &houseSpecularMap);
	Window::generateMap("../house2.png", houseDiffuseMap);
	Window::generateMap("../nospecular.png", houseSpecularMap);
	glUseProgram(houseshaderProgram);
	glUniform1i(glGetUniformLocation(houseshaderProgram, "material.diffuse"), 9);
	glUniform1i(glGetUniformLocation(houseshaderProgram, "material.specular"), 10);

	//park
	glGenTextures(1, &parkDiffuseMap);
	glGenTextures(1, &parkSpecularMap);
	Window::generateMap("../grass.png", parkDiffuseMap);
	Window::generateMap("../nospecular.png", parkSpecularMap);
	glUseProgram(parkshaderProgram);
	glUniform1i(glGetUniformLocation(parkshaderProgram, "material.diffuse"), 11);
	glUniform1i(glGetUniformLocation(parkshaderProgram, "material.specular"), 12);

	//item
	glGenTextures(1, &itemDiffuseMap);
	glGenTextures(1, &itemSpecularMap);
	Window::generateMap("../cratetexture.png", itemDiffuseMap);
	Window::generateMap("../nospecular.png", itemSpecularMap);
	glUseProgram(itemshaderProgram);
	glUniform1i(glGetUniformLocation(itemshaderProgram, "material.diffuse"), 30);
	glUniform1i(glGetUniformLocation(itemshaderProgram, "material.specular"), 31);

	//speeditem
	glGenTextures(1, &speeditemDiffuseMap);
	glGenTextures(1, &speeditemSpecularMap);
	Window::generateMap("../speedtexture.png", speeditemDiffuseMap);
	Window::generateMap("../nospecular.png", speeditemSpecularMap);
	glUseProgram(speeditemshaderProgram);
	glUniform1i(glGetUniformLocation(speeditemshaderProgram, "material.diffuse"), 28);
	glUniform1i(glGetUniformLocation(speeditemshaderProgram, "material.specular"), 29);
}

void City::generate() {
	//Clear previous city
	clear();

	//Randomly position points in the grid
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEZ; j++) {
			GLfloat x = (-SIZEX / 2 + i) * BLOCKWIDTH;
			GLfloat z = (-SIZEZ / 2 + j) * BLOCKWIDTH;
			if (RANDRANGE != 0) {
				x += (rand() % RANDRANGE - RANDRANGE / 2);
				z += (rand() % RANDRANGE - RANDRANGE / 2);
			}
			grid[i][j] = glm::vec3(x, 0.0f, z);
		}
	}

	//Generate park
	int parkRange = maxPark - minPark;
	int parkXlen = (rand() % parkRange + minPark); //Half width
	int parkZlen = (rand() % parkRange + minPark); //Half depth
												   //Place park in map - center point
	int parkX = rand() % (SIZEX - 1 - parkXlen * 2) + parkXlen + 1;
	int parkZ = rand() % (SIZEZ - 1 - parkZlen * 2) + parkZlen + 1;
	//Update roadMap
	for (int i = parkX - parkXlen; i <= parkX + parkXlen; i++) {
		for (int j = parkZ - parkZlen; j <= parkZ + parkZlen; j++) {
			roadMap[i][j] = 3;
		}
	}
	//Add the park cube
	float parktexts[6] = { 20.0f,20.0f,20.0f,20.0f,20.0f,20.0f };
	Cube* c = new Cube(parkshaderProgram, parktexts);
	glm::mat4 trans = glm::translate(glm::mat4(0.1f), glm::vec3(0, 0.5, 0));
	MatrixTransform * scale = new MatrixTransform(glm::scale(trans, glm::vec3(parkXlen * (BLOCKWIDTH) * 2, 1, parkZlen * (BLOCKWIDTH) * 2)));
	scale->addChild(c);
	park = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(grid[parkX][parkZ].x, 0, (grid[parkX][parkZ].z))));
	park->addChild(scale);

	//Generate roads
	int roadCountRange = maxRoads - minRoads;
	int roadCount = (rand() % roadCountRange + minRoads);
	for (int r = 0; r < roadCount; r++) {
		//Start in random position on grid
		int x = rand() % SIZEX;
		int z = rand() % SIZEZ;
		int dir = rand() % 4; // 1 = up, 2 = left, 3 = down, 4 == right
		int prob = 50; //Chance of changing direction is 1/prob
					   //Keep extending round until leaves city or hits another road?
		while (true) {
			//More in direction
			if (dir == 0) z += 1;
			else if (dir == 1) x += 1;
			else if (dir == 2) z -= 1;
			else if (dir == 3) x += 1;
			//Check for termination
			if (x < 0 || z < 0 || x >= SIZEX || z >= SIZEZ) break;
			if (roadMap[x][z] > 0) break;
			//Otherwise place road in map
			roadMap[x][z] = 1;
			placeRoad(x, z);
			//Chance of changing direction
			int old_dir = dir;
			if (rand() % prob == 1) {
				//Don't allow it to be the same or reverse, must turn left or right
				while ((dir % 2) == (old_dir % 2)) dir = rand() % 4;
			}
		}
	}

	//Decide on where the districts will be
	//Continue until the two don't intersect
	int metropSizeX, metropSizeZ, entrtnSizeX, entrtnSizeZ, entrtnStartX, entrtnStartZ;
	while (true) {
		//Metropolis
		metropSizeX = rand() % (metropSizeMax - metropSizeMin) + metropSizeMin;
		metropSizeZ = rand() % (metropSizeMax - metropSizeMin) + metropSizeMin;
		//Entertainment
		entrtnSizeX = rand() % (entrtnSizeMax - entrtnSizeMin) + entrtnSizeMin;
		entrtnSizeZ = rand() % (entrtnSizeMax - entrtnSizeMin) + entrtnSizeMin;
		entrtnStartX = rand() % (SIZEX - entrtnSizeMin);
		entrtnStartZ = rand() % (SIZEZ - entrtnSizeMin);
		//If they don't intersect, break
		bool flag = !overlap(glm::vec2(SIZEX / 2 - metropSizeX, SIZEZ / 2 - metropSizeZ),
			glm::vec2(SIZEX / 2 + metropSizeX, SIZEZ / 2 + metropSizeZ),
			glm::vec2(entrtnStartX, entrtnStartZ),
			glm::vec2(entrtnStartX + entrtnSizeX, entrtnStartZ + entrtnSizeZ));
		if (flag) break;
	}

	//Randomly position buildings in between the roads
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEZ; j++) {
			int putBuilding = rand() % 3;
			if (putBuilding == 1 & roadMap[i][j] == 0) {
				roadMap[i][j] = 2;
				//Place the building corresponding to the district it is in
				if (i >(SIZEX / 2) - (metropSizeX / 2) & i <(SIZEX / 2) + (metropSizeX / 2)
					& j >(SIZEZ / 2) - (metropSizeZ / 2) & j <(SIZEZ / 2) + (metropSizeZ / 2))
					placeSkyscraper(i, j);
				else if (i > entrtnStartX & i < entrtnStartX + entrtnSizeX
					& j > entrtnStartZ & j < entrtnStartZ + entrtnSizeX)
					placeStore(i, j);
				else placeHouse(i, j);
			}
		}
	}

	//place items
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEZ; j++) {
			int putItem = rand() % 10;
			int xitemOffset = rand() % (int)BLOCKWIDTH - (BLOCKWIDTH/2);
			int zitemOffset = rand() % (int)BLOCKWIDTH - (BLOCKWIDTH/2);
			if (putItem == 1 & roadMap[i][j] == 1) {
				placeItem(i,j,xitemOffset, zitemOffset);
			}
		}
	}

	//place speeditems
	for (int i = 0; i < SIZEX; i++) {
		for (int j = 0; j < SIZEZ; j++) {
			int putItem = rand() % 20;
			int xitemOffset = rand() % (int)BLOCKWIDTH - (BLOCKWIDTH / 2);
			int zitemOffset = rand() % (int)BLOCKWIDTH - (BLOCKWIDTH / 2);
			if (putItem == 1 & roadMap[i][j] == 1) {
				placespeedItem(i, j, xitemOffset, zitemOffset);
			}
		}
	}
	//Print road map
	printf("Road map:\n");
	for (int j = 0; j < SIZEZ; j++) {
		for (int i = 0; i < SIZEX; i++) {
			printf("%d ", roadMap[i][j]);
		}
		printf("\n");
	}
}

bool City::overlap(glm::vec2 amin, glm::vec2 amax, glm::vec2 bmin, glm::vec2 bmax) {
	if (amax.x < bmin.x) return false; // a is left of b
	if (amin.x > bmax.x) return false; // a is right of b
	if (amax.y < bmin.y) return false; // a is above b
	if (amin.y > bmax.y) return false; // a is below b
	return true; // boxes overlap
}

void City::clear() {
	//Clear road map
	for (int i = 0; i < SIZEX; i++)
		for (int j = 0; j < SIZEZ; j++)
			roadMap[i][j] = 0;
	//Remove all buildings, roads, etc
	for (Node* n : skyscrapers->children) ((Cube*)n)->destroy();
	for (Node* n : stores->children) ((Cube*)n)->destroy();
	for (Node* n : houses->children) ((Cube*)n)->destroy();
	for (Node* n : roads->children) ((Cube*)n)->destroy();
	skyscrapers->children.clear();
	stores->children.clear();
	houses->children.clear();
	roads->children.clear();
	boundingboxes->children.clear();
	Window::boxPositions.clear();
	Window::boxSizes.clear();
	Window::itemPositions.clear();
	Window::itemSizes.clear();
	Window::itemboxes.clear();
	Window::items.clear();
	Window::itemboundingboxes->children.clear();
	Window::itemgroup->children.clear();
	Window::boxlist.clear();
	Window::speeditemPositions.clear();
	Window::speeditemSizes.clear();
	Window::speeditems.clear();
	Window::speeditemboxes.clear();
	Window::speeditemboundingboxes->children.clear();
	Window::speeditemgroup->children.clear();

}

void City::placeRoad(int x, int z) {
	float textmapping[6] = { 1.0f,1.0f,1.0f,1.0f,0.0f,1.0f };
	Cube* road = new Cube(roadshaderProgram, textmapping);
	float height = 1;
	glm::mat4 trans1 = glm::translate(glm::mat4(1.0f), grid[x][z]);
	glm::mat4 trans2 = glm::translate(trans1, glm::vec3(0, height / 2, 0));
	MatrixTransform* transform = new MatrixTransform(glm::scale(trans2, glm::vec3(BLOCKWIDTH + RANDRANGE, height, BLOCKWIDTH + RANDRANGE)));
	transform->addChild(road);
	roads->addChild(transform);
}

void City::placeItem(int x, int z,int xOff,int zOff)
{
	float itemmapping[6] = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f };
	Cube* item = new Cube(itemshaderProgram, itemmapping);
	float height = 1.6;
	MatrixTransform* transform = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(grid[x][z].x+xOff, height, grid[x][z].z+zOff)));
	transform->addChild(item);
	Window::itemgroup->addChild(transform);
	Window::items.push_back(item);
	//bounding box
	BoundingBox* citybox = new BoundingBox(carboxshaderProgram);
	MatrixTransform* boxtransform = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(grid[x][z].x + xOff, height, grid[x][z].z + zOff)));
	boxtransform->addChild(citybox);
	Window::itemboundingboxes->addChild(boxtransform);
	Window::itemPositions.push_back(glm::vec3(grid[x][z].x + xOff, height, grid[x][z].z + zOff));
	Window::itemSizes.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	Window::itemboxes.push_back(citybox);
}
void City::placespeedItem(int x, int z, int xOff, int zOff)
{
	float itemmapping[6] = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f };
	Cube* item = new Cube(speeditemshaderProgram, itemmapping);
	float height = 1.6;
	MatrixTransform* transform = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(grid[x][z].x + xOff, height, grid[x][z].z + zOff)));
	transform->addChild(item);
	Window::speeditemgroup->addChild(transform);
	Window::speeditems.push_back(item);
	//bounding box
	BoundingBox* citybox = new BoundingBox(carboxshaderProgram);
	MatrixTransform* boxtransform = new MatrixTransform(glm::translate(glm::mat4(1.0f), glm::vec3(grid[x][z].x + xOff, height, grid[x][z].z + zOff)));
	boxtransform->addChild(citybox);
	Window::speeditemboundingboxes->addChild(boxtransform);
	Window::speeditemPositions.push_back(glm::vec3(grid[x][z].x + xOff, height, grid[x][z].z + zOff));
	Window::speeditemSizes.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	Window::speeditemboxes.push_back(citybox);
}
void City::placeSkyscraper(int x, int z) {
	int maxHeight = 100;
	int minHeight = 60;
	float textmapping[6] = {8.0f,8.0f,8.0f,8.0f,0.0f,0.0f};
	Cube* building = new Cube(scraperShaderProgram, textmapping);
	float height = rand() % (maxHeight - minHeight) + minHeight;
	glm::mat4 trans1 = glm::translate(glm::mat4(1.0f), grid[x][z]);
	glm::mat4 trans2 = glm::translate(trans1, glm::vec3(0, height / 2, 0));
	MatrixTransform* transform = new MatrixTransform(glm::scale(trans2, glm::vec3(BLOCKWIDTH, height, BLOCKWIDTH)));
	transform->addChild(building);
	skyscrapers->addChild(transform);
	//bounding box
	BoundingBox* citybox = new BoundingBox(carboxshaderProgram);
	MatrixTransform* boxtransform = new MatrixTransform(glm::scale(trans2, glm::vec3((float)BLOCKWIDTH, (float)height, (float)BLOCKWIDTH)));
	boxtransform->addChild(citybox);
	boundingboxes->addChild(boxtransform);
	Window::boxPositions.push_back(glm::vec3(grid[x][z].x-4.15f, (float)height / 2.0f, grid[x][z].z- 4.15f));
	Window::boxSizes.push_back(glm::vec3((float)BLOCKWIDTH, (float)height, (float)BLOCKWIDTH));
	Window::boxlist.push_back(citybox);
}

void City::placeStore(int x, int z) {
	int maxHeight = 40;
	int minHeight = 20;
	float textmapping[6] = { 2.0f,2.0f,2.0f,2.0f,0.0f,0.0f };
	Cube* building = new Cube(storeshaderProgram, textmapping);
	float height = rand() % (maxHeight - minHeight) + minHeight;
	glm::mat4 trans1 = glm::translate(glm::mat4(1.0f), grid[x][z]);
	glm::mat4 trans2 = glm::translate(trans1, glm::vec3(0, height / 2, 0));
	MatrixTransform* transform = new MatrixTransform(glm::scale(trans2, glm::vec3(BLOCKWIDTH, height, BLOCKWIDTH)));
	transform->addChild(building);
	stores->addChild(transform);

	//bounding box
	BoundingBox* citybox = new BoundingBox(carboxshaderProgram);
	MatrixTransform* boxtransform = new MatrixTransform(glm::scale(trans2, glm::vec3((float)BLOCKWIDTH, (float)height, (float)BLOCKWIDTH)));
	boxtransform->addChild(citybox);
	boundingboxes->addChild(boxtransform);
	Window::boxPositions.push_back(glm::vec3(grid[x][z].x- 4.15f, (float)height / 2.0f, grid[x][z].z- 4.15f));
	Window::boxSizes.push_back(glm::vec3((float)BLOCKWIDTH, (float)height, (float)BLOCKWIDTH));
	Window::boxlist.push_back(citybox);
}

void City::placeHouse(int x, int z) {
	int maxHeight = 10;
	int minHeight = 5;
	float textmapping[6] = { 2.0f,2.0f,2.0f,2.0f,0.0f,0.0f };
	Cube* building = new Cube(houseshaderProgram, textmapping);
	float height = rand() % (maxHeight - minHeight) + minHeight;
	glm::mat4 trans1 = glm::translate(glm::mat4(1.0f), grid[x][z]);
	glm::mat4 trans2 = glm::translate(trans1, glm::vec3(0, height / 2, 0));
	MatrixTransform* transform = new MatrixTransform(glm::scale(trans2, glm::vec3(BLOCKWIDTH, height, BLOCKWIDTH)));
	transform->addChild(building);
	houses->addChild(transform);

	//bounding box
	BoundingBox* citybox = new BoundingBox(carboxshaderProgram);
	MatrixTransform* boxtransform = new MatrixTransform(glm::scale(trans2, glm::vec3((float)BLOCKWIDTH, (float)height, (float)BLOCKWIDTH)));
	boxtransform->addChild(citybox);
	boundingboxes->addChild(boxtransform);
	Window::boxPositions.push_back(glm::vec3(grid[x][z].x- 4.15f, (float)height / 2.0f, grid[x][z].z- 4.15f));
	Window::boxSizes.push_back(glm::vec3((float)BLOCKWIDTH, (float)height, (float)BLOCKWIDTH));
	Window::boxlist.push_back(citybox);
}

void City::draw(glm::mat4 C) {
	Window::setShaders(scraperShaderProgram);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, scraperDiffuseMap);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, scraperSpecularMap);
	skyscrapers->draw(C);
	
	Window::setShaders(roadshaderProgram);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, roadDiffuseMap);
	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, roadSpecularMap);
	roads->draw(C);

	Window::setShaders(groundshaderProgram);
	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, groundDiffuseMap);
	glActiveTexture(GL_TEXTURE6);
	glBindTexture(GL_TEXTURE_2D, groundSpecularMap);
	ground->draw(C);

	Window::setShaders(storeshaderProgram);
	glActiveTexture(GL_TEXTURE7);
	glBindTexture(GL_TEXTURE_2D, storeDiffuseMap);
	glActiveTexture(GL_TEXTURE8);
	glBindTexture(GL_TEXTURE_2D, storeSpecularMap);
	stores->draw(C);

	Window::setShaders(houseshaderProgram);
	glActiveTexture(GL_TEXTURE9);
	glBindTexture(GL_TEXTURE_2D, houseDiffuseMap);
	glActiveTexture(GL_TEXTURE10);
	glBindTexture(GL_TEXTURE_2D, houseSpecularMap);
	houses->draw(C);

	Window::setShaders(parkshaderProgram);
	glActiveTexture(GL_TEXTURE11);
	glBindTexture(GL_TEXTURE_2D, parkDiffuseMap);
	glActiveTexture(GL_TEXTURE12);
	glBindTexture(GL_TEXTURE_2D, parkSpecularMap);
	park->draw(C);

	Window::setShaders(itemshaderProgram);
	glActiveTexture(GL_TEXTURE30);
	glBindTexture(GL_TEXTURE_2D, itemDiffuseMap);
	glActiveTexture(GL_TEXTURE31);
	glBindTexture(GL_TEXTURE_2D, itemSpecularMap);
	Window::itemgroup->draw(C);

	Window::setShaders(speeditemshaderProgram);
	glActiveTexture(GL_TEXTURE28);
	glBindTexture(GL_TEXTURE_2D, speeditemDiffuseMap);
	glActiveTexture(GL_TEXTURE29);
	glBindTexture(GL_TEXTURE_2D, speeditemSpecularMap);
	Window::speeditemgroup->draw(C);

	if (Window::showboxes) {
		boundingboxes->draw(Window::V);
		Window::itemboundingboxes->draw(Window::V);
		Window::speeditemboundingboxes->draw(Window::V);
	}
}

void City::update(float dt) {

}