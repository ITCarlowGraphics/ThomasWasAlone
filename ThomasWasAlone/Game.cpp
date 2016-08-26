#include "stdafx.h"

#include <iostream>
using namespace std;
#define SDL_MAIN_HANDLED
#ifdef __APPLE__
#include "SDL2/SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
#include "SDL.h"
#endif


#include "LTimer.h"
#include "Renderer.h"
#include "Game.h"


const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


Game::Game()
{
}


Game::~Game()
{
}

/**Initialises SDL, creates a SDL_Renderer, an SDL_Window, and Renderer*/
bool Game::init() {


	
	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

										   // Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Thomas Was Alone",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		800,                               // width, in pixels
		600,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		cout <<"Could not create window: " << SDL_GetError() << std::endl;
		return false;
	}

	sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (sdl_renderer == NULL) {
		// In the case that the renderer could not be made...
		cout << "Could not create renderer: " << SDL_GetError() << std::endl;
		return false;
	}


	return true;
}

/**Destroys SDL_Window and SDL_Renderer*/
void Game::destroy()
{
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(window);
}

//** calls update on all game entities*/
void Game::update()
{
}

//** calls render on all game entities*/

void Game::render()
{
	cout << "render"<< endl;
}

/** update and render game entities*/
void Game::loop()
{
	LTimer capTimer;//to cap framerate
	bool quit = false;
	SDL_Event e;
	while (!quit) {
		capTimer.start();

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		//check for exit

		update();
		render();

		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}
