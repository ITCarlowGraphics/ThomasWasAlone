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
#include "Box.h"
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
	renderer.init(sdl_renderer);


	//create some game objects

	Box* box1 = new Box(Rect(50,50,30,40));
	box1->angVel = 0.5f;//radian per seconds	
	Box* box2 = new Box(Rect(50, 50, 30, 40));
	box2->angVel = -0.85f;//radian per seconds	

	gameObjects.push_back(box1);
	gameObjects.push_back(box2);

	return true;
	lastTime = SDL_GetTicks();

}

/**Destroys SDL_Window and SDL_Renderer*/
void Game::destroy()
{
	//empty out the game object vector
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		delete *i;
	}
	gameObjects.clear();

	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(window);
}

//** calls update on all game entities*/
void Game::update()
{
	unsigned int currentTime = SDL_GetTicks();
	unsigned int deltaTime = currentTime - lastTime;

	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		(*i)->Update(deltaTime);
	}


	lastTime = currentTime;
}

//** calls render on all game entities*/

void Game::render()
{


	SDL_Color clear_col = { 0,0,0,255 };

	renderer.clear(clear_col);

	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		(*i)->Render(renderer);
	}


	renderer.present();// display the new frame


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
