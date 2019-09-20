#include "game.h"

#ifndef VERT_PATH
#define VERT_PATH "shaders/hello_triangle.vert"
#endif

#ifndef FRAG_PATH
#define FRAG_PATH "shaders/hello_triangle.frag"
#endif

int main()
{
	struct game g;
	float t;

	float vertices[] = {
		/* position */   /* color */
		-0.5, -0.5, 0.0, 1.0, 0.0, 0.0,
		 0.5, -0.5, 0.0, 0.0, 1.0, 0.0,
		 0.0,  0.5, 0.0, 0.0, 0.0, 1.0,
	};
	GLuint vao, vbo, shader, x_offset;

	game_init(&g);

	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/* position attribute */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	/* color attribute */
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	shader = load_shader(VERT_PATH, FRAG_PATH);

	while (!g.quit) {
		handle_events(&g);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);

		t = sin(get_time());
		x_offset = glGetUniformLocation(shader, "x_offset");
		glUniform1f(x_offset, t);
		glBindVertexArray(vao);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);

		game_swap_window(&g);
	}

	game_close(&g);
	return 0;
}
