#include "game.h"

bool game_init(struct game *g)
{
	g->quit = false;
	g->event_handlers = (struct event_handlers){0};

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		goto error;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	g->window = SDL_CreateWindow(WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (!g->window) goto error;

	g->context = SDL_GL_CreateContext(g->window);
	if (!g->context) goto error;

	SDL_GL_MakeCurrent(g->window, g->context);
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		SDL_SetError("failed to initialize GLAD");
		goto error;
	}

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	return true;

error:
	g->quit = true;
	printf("ERROR: %s\n", SDL_GetError());
	SDL_Quit();
	return false;
}

void game_close(struct game *g)
{
	SDL_GL_DeleteContext(g->context);
	SDL_DestroyWindow(g->window);

	g->quit = true;
	g->window = g->context = NULL;

	SDL_Quit();
}
