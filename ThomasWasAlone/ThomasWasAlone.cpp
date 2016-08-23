// ThomasWasAlone.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
using namespace std;

#define SDL_MAIN_HANDLED

#ifdef __APPLE__
    #include "SDL2/SDL.h"
#elif _WIN64
    #include "SDL.h"
#endif

#include "Game.h"


/**Create and initialises an instance of game, and clean up when the game is closed*/

int main()
{
	Game game;

	cout << "Initialising Game" << endl;

	if (!game.init()) {
		cout << "Failed to init game"<<'\n';
	}

	game.loop();

	game.destroy();

    return 0;
}

