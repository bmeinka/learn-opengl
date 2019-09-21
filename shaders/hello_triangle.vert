#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform float t;

out vec3 vertex_color;

vec3 calculate()
{
	vec3 ratios = vec3(
		mod(clamp(t, 0.0, 1.0), 1.0),
		mod(clamp(t - 1.0, 0.0, 1.0), 1.0),
		mod(clamp(t - 2.0, 0.0, 1.0), 1.0));
	return vec3(
		mod(1 - ratios.r, 1.0) + ratios.b,
		mod(1 - ratios.g, 1.0) + ratios.r,
		mod(1 - ratios.b, 1.0) + ratios.g);

}

void main()
{
	vec3 n;
	n = calculate();
	if (t == 0.0)
		n = vec3(1.0, 0.0, 0.0);
	if (t == 1.0)
		n = vec3(0.0, 1.0, 0.0);
	if (t == 2.0)
		n = vec3(0.0, 0.0, 1.0);

	vertex_color = vec3(
		n.r * color.r + n.g * color.b + n.b * color.g,
		n.r * color.g + n.g * color.r + n.b * color.b,
		n.r * color.b + n.g * color.g + n.b * color.r);
	gl_Position = vec4(position, 1.0);
}
