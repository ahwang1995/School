#version 330 core
layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

out vec2 TexCoords;
out vec4 ParticleColor;

uniform mat4 projection;
uniform mat4 modelview;
uniform vec3 offset;
uniform vec4 color;

void main()
{
    float scale = 1.0f;
    TexCoords = vertex.zw;
    ParticleColor = color;		//Have to take the rotation out of the modelview
    gl_Position = projection * mat4(vec4(1,0,0,0),vec4(0,1,0,0),vec4(0,0,1,0),modelview[3]) * (vec4((vertex.xy * scale), 0.0, 1.0) + vec4(offset, 0.0));
}