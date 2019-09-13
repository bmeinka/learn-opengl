#include "game.h"

static void handle_resize(struct game *g, int32_t w, int32_t h)
{
	(void)g;
	glViewport(0, 0, w, h);
}

static void handle_window_event(struct game *g, SDL_Event e)
{
	if (e.window.type == SDL_WINDOWEVENT_RESIZED)
		g->event_handlers.window.resized(g, e.window.data1, e.window.data2);
}

void init_events(struct game *g)
{
	g->event_handlers = (struct event_handlers){0};
	g->event_handlers.window.resized = &handle_resize;
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
