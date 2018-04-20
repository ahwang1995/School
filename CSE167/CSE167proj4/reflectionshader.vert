#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 Normal;
out vec3 Position;

uniform mat4 projection;
uniform mat4 modelview;

void main()
{
    gl_Position = projection * modelview * vec4(position.x, position.y, position.z, 1.0);
    Normal = mat3(transpose(inverse(modelview))) * normal;
    Position = vec3(modelview * vec4(position, 1.0f));
}  