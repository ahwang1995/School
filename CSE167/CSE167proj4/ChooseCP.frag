#version 330
uniform uint code;
 
out vec4 color;
 
void main()
{
    color = vec4(code/255.0,0,0,0);
}