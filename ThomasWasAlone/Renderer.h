#pragma once
#ifdef __APPLE__
#include "SDL2/SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
#include "SDL.h"
#endif

#include "BasicTypes.h"

class Renderer{
	SDL_Renderer *renderer;

public:
	Renderer();
	void init(SDL_Renderer * r);
	void drawRect(Rect&, Colour&);
	void present();
	void clear(SDL_Color&);
	~Renderer();
};

