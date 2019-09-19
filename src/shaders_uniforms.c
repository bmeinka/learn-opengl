#include "game.h"

#ifndef VERT_PATH
#define VERT_PATH "shaders/hello_triangle.vert"
#endif

#ifndef FRAG_PATH
#define FRAG_PATH "shaders/uniforms.frag"
#endif

int main()
{
	struct game g;

	float vertices[] = {
		-0.5, -0.5, 0.0,
		 0.5, -0.5, 0.0,
		 0.0,  0.5, 0.0
	};
	GLuint vao, vbo, shader;

	float green;
	GLint vertex_color_location;

	game_init(&g);

	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	shader = load_shader(VERT_PATH, FRAG_PATH);

	while (!g.quit) {
		handle_events(&g);


		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		green = (sin(get_time()) / 2.0) + 0.5;
		vertex_color_location = glGetUniformLocation(shader, "our_color");
		glUseProgram(shader);
		glUniform4f(vertex_color_location, 0.0f, green, 0.0f, 1.0f);

		glBindVertexArray(vao);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);

		game_swap_window(&g);
	}

	game_close(&g);
	return 0;
}
