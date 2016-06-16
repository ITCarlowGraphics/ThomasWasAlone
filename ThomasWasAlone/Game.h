#pragma once
#include "Renderer.h"
class Game
{
	SDL_Window *window;                    
	SDL_Renderer *sdl_renderer;

	Renderer renderer;

public:
	Game();
	~Game();

	bool init();
	void destroy();

	void update();
	void render();
	void loop();
};

