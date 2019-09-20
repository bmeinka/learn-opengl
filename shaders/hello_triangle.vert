#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform float x_offset;

out vec3 vertex_color;

void main()
{
	gl_Position = vec4(position.x + x_offset, position.yz, 1.0);
	vertex_color = color;
}
