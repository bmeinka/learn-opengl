#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#include <SDL.h>
#include "game.h"

void handle_keydown(struct game *g, KEY e)
{
	if (e == ESCAPE)
		g->quit = true;
}

int main()
{
	struct game g;
	game_init(&g);
	g.event_handlers.keydown = &handle_keydown;

	while (!g.quit) {
		handle_events(&g);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		game_swap_window(&g);
	}

	game_close(&g);
	return 0;
}
