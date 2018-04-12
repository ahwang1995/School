#version 330 core
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;    
    float shininess;
}; 

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;  
in vec3 Normal;  
  
out vec4 color;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;

uniform float flag;

void main()
{  
	if (flag >= 1) color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	else color = vec4(0.0f, 1.0f, 0.0f, 1.0f);
} 