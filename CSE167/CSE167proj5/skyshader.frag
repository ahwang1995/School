#version 330 core
in vec3 TexCoords;
out vec4 color;

uniform samplerCube skybox;

void main()
{
    // Color everything a hot pink color. An alpha of 1.0f means it is not transparent.
    color = texture(skybox, TexCoords);
}