#include "game.h"

#define VERT_PATH "shaders/hello_triangle.vert"
#define FRAG_PATH "shaders/hello_triangle.frag"

int main()
{
	struct game g;

	float vertices[] = {
		-0.5, -0.5, 0.0,
		 0.5, -0.5, 0.0,
		 0.0,  0.5, 0.0
	};
	GLuint vao, vbo, shader;

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

		glUseProgram(shader);
		glBindVertexArray(vao);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		game_swap_window(&g);
	}

	game_close(&g);
	return 0;
}
