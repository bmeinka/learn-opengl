#include "game.h"

int main()
{
	struct game g;
	game_init(&g);

	while (!g.quit) {
		handle_events(&g);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		game_swap_window(&g);
	}

	game_close(&g);
	return 0;
}
