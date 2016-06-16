#include "stdafx.h"
#include <iostream>
using namespace std;
#define SDL_MAIN_HANDLED
#include "SDL.h"

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
