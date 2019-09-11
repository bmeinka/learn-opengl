#pragma once
#include <stdbool.h>
#include <glad/glad.h>
#include <SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Learn OpenGL"

/* all the rendering context information we need */
struct window {
	bool quit;
	SDL_Window *window;
	SDL_GLContext context;
};

/* initialize a window for rendering */
bool window_initialize(struct window *window);

/* close a window */
void window_close(struct window *window);
