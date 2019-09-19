#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include <glad/glad.h>
#include <SDL.h>

#include "events.h"
#include "shaders.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Learn OpenGL"

#define game_swap_window(g) SDL_GL_SwapWindow((g)->window)
#define get_time() SDL_GetTicks() / 1000.0

struct game {
	bool quit;
	SDL_Window *window;
	SDL_GLContext context;
	struct event_handlers event_handlers;
};

bool game_init(struct game *g);
void game_close(struct game *g);
