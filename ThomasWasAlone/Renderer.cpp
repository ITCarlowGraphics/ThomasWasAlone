#include "stdafx.h"
#include <iostream>
using namespace std;
#define SDL_MAIN_HANDLED

#ifdef __APPLE__
    #include "SDL2/SDL.h"
#elif _WIN32
    #include "SDL.h"
#endif

#include "Renderer.h"




Renderer::Renderer():renderer(NULL)
{
	
}

void Renderer::init(SDL_Renderer *r) {
	renderer = r;
}


Renderer::~Renderer()
{
}
