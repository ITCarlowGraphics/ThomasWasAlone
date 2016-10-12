#include "stdafx.h"
#include <iostream>
using namespace std;
#define SDL_MAIN_HANDLED

#ifdef __APPLE__
    #include "SDL2/SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
    #include "SDL.h"
#endif

#include "Renderer.h"




Renderer::Renderer():renderer(NULL)
{
	
}

void Renderer::init(SDL_Renderer *r) {
	renderer = r;
}

void Renderer::drawRect(Rect& r, Colour& c) {
	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
	SDL_Rect sr;
	sr.h = (int)r.size.h;
	sr.w = (int)r.size.w;
	sr.x = (int)r.pos.x;
	sr.y = (int)r.pos.y;
	SDL_RenderFillRect(renderer, &sr);

}

void Renderer::present() {
	SDL_RenderPresent(renderer);
}

void Renderer::clear(SDL_Color& col) {
	SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
	SDL_RenderClear(renderer);

}
Renderer::~Renderer()
{
}
