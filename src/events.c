#include "game.h"
#include <stdbool.h>
#include <SDL.h>
#include <glad/glad.h>

static void handle_resize(int32_t w, int32_t h)
{
	glViewport(0, 0, w, h);
}

static void handle_window_event(struct game *g, SDL_Event e)
{
	if (e.window.type == SDL_WINDOWEVENT_RESIZED)
		handle_resize(e.window.data1, e.window.data2);
	(void)g;
}

void handle_events(struct game *g)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT)
			g->quit = true;
		else if (e.type == SDL_WINDOWEVENT)
			handle_window_event(g, e);
		else if (e.type == SDL_KEYDOWN && g->event_handlers.keydown)
			g->event_handlers.keydown(g, e.key.keysym.sym);
	}
}
