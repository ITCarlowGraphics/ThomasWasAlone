#include "stdafx.h"

#include <iostream>
using namespace std;
#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "Renderer.h"
#include "Game.h"


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


