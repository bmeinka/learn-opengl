#include "game.h"

#define VERT_PATH "shaders/hello_triangle.vert"
#define FRAG_PATH "shaders/hello_triangle.frag"
#define FRAG_ALT_PATH "shaders/hello_triangle_alt.frag"

int main()
{
	struct game g;

	/*
	 * create two shader programs where the second program uses a different
	 * fragment shader that outputs the color yellow; draw two triangles
	 * where one outputs the color yellow
	 */
	float vertices[2][9] = {
		{-1.0, -0.5, 0.0, 0.0, -0.5, 0.0, -0.5, 0.5, 0.0},
		{0.0, -0.5, 0.0, 0.5, 0.5, 0.0, 1.0, -0.5, 0.0}
	};
	GLuint shaders[2], vaos[2], vbos[2];

	game_init(&g);

	glGenBuffers(2, vbos);
	glGenVertexArrays(2, vaos);

	for (size_t i = 0; i < 2; i++) {
		glBindVertexArray(vaos[i]);
		glBindBuffer(GL_ARRAY_BUFFER, vbos[i]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[i]), vertices[i], GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
		glEnableVertexAttribArray(0);
	}
	
	shaders[0] = load_shader(VERT_PATH, FRAG_PATH);
	shaders[1] = load_shader(VERT_PATH, FRAG_ALT_PATH);

	while (!g.quit) {
		handle_events(&g);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		for (size_t i = 0; i < 2; i++) {
			glUseProgram(shaders[i]);
			glBindVertexArray(vaos[i]);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glBindVertexArray(0);
		}

		game_swap_window(&g);
	}

	game_close(&g);
	return 0;
}
