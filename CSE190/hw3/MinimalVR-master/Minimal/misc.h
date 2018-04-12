#pragma once

// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// GL Includes
#include <GL/glew.h> // Contains all the necessery OpenGL includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
// A class for random functions we can use where ever!
class Misc {
public:

	// Prtins a matrix, useful for debugging!
	static void Misc::printMat(glm::mat4 M) {
		printf("[ %f, %f, %f, %f;\n %f, %f, %f, %f;\n %f, %f, %f, %f;\n %f, %f, %f, %f; ]\n",
			M[0][0], M[0][1], M[0][2], M[0][3],
			M[1][0], M[1][1], M[1][2], M[1][3],
			M[2][0], M[2][1], M[2][2], M[2][3],
			M[3][0], M[3][1], M[3][2], M[3][3]);
	}

	static void Misc::printVec(glm::vec3 v) {
		printf("[ %f, %f, %f ]\n",
			v.x, v.y, v.z);
	}

	static float Misc::random(float min, float max) {
		int accuracy = 1000;

		// Create a random number between 0 and (max - min) * 1000
		float r = rand() % accuracy * (max - min) + 1;
		// r is now between 0 and (max - min)
		r /= 1000.0f;
		// r is now between min and max
		r += min;

		return r;
	}

	//! Load a ppm file from disk.
	// @input filename The location of the PPM file.  If the file is not found, an error message
	//		will be printed and this function will return 0
	// @input width This will be modified to contain the width of the loaded image, or 0 if file not found
	// @input height This will be modified to contain the height of the loaded image, or 0 if file not found
	//
	// @return Returns the RGB pixel data as interleaved unsigned chars (R0 G0 B0 R1 G1 B1 R2 G2 B2 .... etc) or 0 if an error ocured

	static unsigned char* loadPPM(const char* filename, int& width, int& height)
	{
		const int BUFSIZE = 128;
		FILE* fp;
		unsigned int read;
		unsigned char* rawData;
		char buf[3][BUFSIZE];
		char* retval_fgets;
		size_t retval_sscanf;

		if ((fp = fopen(filename, "rb")) == NULL)
		{
			std::cerr << "error reading ppm file, could not locate " << filename << std::endl;
			width = 0;
			height = 0;
			return 0;
		}

		// Read magic number:
		retval_fgets = fgets(buf[0], BUFSIZE, fp);

		// Read width and height:
		do
		{
			retval_fgets = fgets(buf[0], BUFSIZE, fp);
		} while (buf[0][0] == '#');
		retval_sscanf = sscanf(buf[0], "%s %s", buf[1], buf[2]);
		width = atoi(buf[1]);
		height = atoi(buf[2]);

		// Read maxval:
		do
		{
			retval_fgets = fgets(buf[0], BUFSIZE, fp);
		} while (buf[0][0] == '#');

		// Read image data:
		rawData = new unsigned char[width * height * 3];
		read = fread(rawData, width * height * 3, 1, fp);
		fclose(fp);
		if (read != 1)
		{
			std::cerr << "error parsing ppm file, incomplete data" << std::endl;
			delete[] rawData;
			width = 0;
			height = 0;

			return 0;
		}

		return rawData;
	}

	static GLint TextureFromFile(const char* filename)
	{
		//Generate texture ID and load texture data
		GLuint textureID;
		glGenTextures(1, &textureID);
		int width, height;
		unsigned char* image = loadPPM(filename, width, height);
		// Assign texture to ID
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);

		// Parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);

		return textureID;
	}

};