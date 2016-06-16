#pragma once
class Renderer{
	SDL_Renderer *renderer;

public:
	Renderer();
	void init(SDL_Renderer * r);
	~Renderer();
};

