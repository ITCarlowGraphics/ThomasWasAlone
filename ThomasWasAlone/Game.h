#pragma once

#include <vector>

#include "Renderer.h"
#include "GameObject.h"


class Game
{

	Renderer renderer;

	std::vector<GameObject*> gameObjects;

	unsigned int lastTime;//time of last update;
public:
	Game();
	~Game();

	bool init();
	void destroy();

	void update();
	void render();
	void loop();
};

