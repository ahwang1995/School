#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

struct Material {
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;

	// Constructor
	Material(float a1, float a2, float a3, 
		float d1, float d2, float d3, 
		float s1, float s2, float s3, float shine) {
		this->ambient = glm::vec3(a1, a2, a3);
		this->diffuse = glm::vec3(d1, d2, d3);
		this->specular = glm::vec3(s1, s2, s3);
		this->shininess = shine;
	}

	Material() {

	}

};

class MatLib {
public:

	static const Material EMERALD, CYAN_PLASTIC, GOLD, RED_RUBBER, CERAMIC, BRONZE, WHITE_RUBBER, WHITE, ORANGE_PLASTIC, RED_PLASTIC;

};