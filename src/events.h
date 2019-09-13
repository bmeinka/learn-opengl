#pragma once
#include "game.h"
// #include <stdint.h>
// #include <SDL.h>

struct game;
typedef SDL_Keycode KEY;

#define ESCAPE '\033'

struct event_handlers_window {
	void (*resized)(struct game *g, int32_t w, int32_t h);
};

struct event_handlers {
	void (*keydown)(struct game *g, KEY e);
	struct event_handlers_window window;
};

void init_events(struct game *g);
void handle_events(struct game *g);
