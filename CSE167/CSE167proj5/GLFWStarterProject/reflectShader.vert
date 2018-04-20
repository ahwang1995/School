#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 Normal;
out vec3 Position;

uniform mat4 modelview;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * modelview * vec4(position, 1.0f);
    Normal = mat3(transpose(inverse(modelview))) * normal;
    Position = vec3(modelview * vec4(position, 1.0f));
}  