#include <stdio.h>
#include "init.h"

// TODO: create a logger

#define show_error_and_quit() {\
	printf("ERROR: %s\n", SDL_GetError());\
	SDL_Quit();\
	return false;\
}

#define check_errors(fn) if (fn < 0) show_error_and_quit()
#define check_null(ptr) if (!ptr) show_error_and_quit()

static bool init_sdl()
{
	check_errors(SDL_Init(SDL_INIT_VIDEO));
	return true;
}

static bool init_gl_hints()
{
	check_errors(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3));
	check_errors(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3));
	check_errors(SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE));
	return true;
}

static bool init_window(struct window *window)
{
	window->window = SDL_CreateWindow(WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	check_null(window->window);
	return true;
}

static bool init_context(struct window *window)
{
	window->context = SDL_GL_CreateContext(window->window);
	check_null(window->context);
	SDL_GL_MakeCurrent(window->window, window->context);
	return true;
}

static bool init_glad()
{
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		puts("ERROR: failed to initialize glad");
		SDL_Quit();
		return false;
	}
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	return true;
}

bool window_initialize(struct window *window)
{
	window->quit = false;
	return (init_sdl() &&
		init_gl_hints() &&
		init_window(window) &&
		init_context(window) &&
		init_glad());
}

void window_close(struct window *window)
{
	SDL_GL_DeleteContext(window->context);
	SDL_DestroyWindow(window->window);
	window->window = window->context = NULL;
	SDL_Quit();
}
