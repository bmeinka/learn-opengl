#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#include <SDL.h>
#include "init.h"

void handle_window_event(struct window *window, SDL_Event *e)
{
	if (e->window.event == SDL_WINDOWEVENT_RESIZED)
		glViewport(0, 0, e->window.data1, e->window.data2);
	(void)window;
}

void handle_input_event(struct window *window, SDL_Event *e)
{
	if (e->key.keysym.sym == SDLK_ESCAPE)
		window->quit = true;
}

int main()
{
	struct window window;
	window_initialize(&window);
	SDL_Event e;

	while (!window.quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				window.quit = true;
			else if (e.type == SDL_WINDOWEVENT)
				handle_window_event(&window, &e);
			else if (e.type == SDL_KEYDOWN)
				handle_input_event(&window, &e);
		}

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(window.window);
	}

	window_close(&window);
	return 0;
}
