#include "stdafx.h"

#include <iostream>
using namespace std;



#include "LTimer.h"
#include "Box.h"
#include "Game.h"
#include "InputManager.h"

const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


Game::Game()
{
}


Game::~Game()
{
}


bool Game::init() {


	
	Size2D winSize(800,600);

	//creates our renderer, which looks after drawnig and the window
	renderer.init(winSize,"Thomas was alone");

	//set up the viewport
	//we want the vp centred on origin and 20 units wide
	float aspectRatio = winSize.w / winSize.h;
	float vpWidth = 20;
	Size2D vpSize(vpWidth, vpWidth /aspectRatio);
	Point2D vpBottomLeft( -vpSize.w / 2, - vpSize.h / 2);

	Rect vpRect(vpBottomLeft,vpSize);
	renderer.setViewPort(vpRect);


	//create some game objects

	SpinningBox* box1 = new SpinningBox(Rect(5,0,4,0.2));
	box1->col = Colour(255, 255, 0);
	box1->angVel = 0.5f;//radian per seconds	
	SpinningBox* box2 = new SpinningBox(Rect(5, 0, 1, 1));
	box2->angVel = -0.85f;//radian per seconds
	box2->col = Colour(50, 255, 255);
	SpinningBox* box3 = new SpinningBox(Rect(0, 0, 1, 1));
	box3->angVel = -0.1f;//radian per seconds	
	box3->col = Colour(200, 100, 255);
	SpinningBox* box4 = new SpinningBox(Rect(0, 0, 1, 1));
	box4->angVel = .0f;//radian per seconds	

	//calibration check: this box should be just inside bottom left of window
	SpinningBox* box5 = new SpinningBox(Rect(-vpWidth/2, (-vpWidth / 2) / aspectRatio, 1, 1));
	box5->col = Colour(255,0,0);//red
	//calibration check: this box should be just inside top right of window
	SpinningBox* box6 = new SpinningBox(Rect((vpWidth / 2)-1, ((vpWidth / 2) / aspectRatio) -1, 1, 1));
	box6->col = Colour(255, 100, 0);//orange


	gameObjects.push_back(box1);
	gameObjects.push_back(box2);
	gameObjects.push_back(box3);
	gameObjects.push_back(box4);
	gameObjects.push_back(box5);
	gameObjects.push_back(box6);

	
	lastTime = LTimer::gameTime();
	return true;

}


void Game::destroy()
{
	//empty out the game object vector before quitting
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		delete *i;
	}
	gameObjects.clear();

	renderer.destroy();
}

//** calls update on all game entities*/
void Game::update()
{
	unsigned int currentTime = LTimer::gameTime();//millis since game started
	unsigned int deltaTime = currentTime - lastTime;

	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		(*i)->Update(deltaTime);
	}


	lastTime = currentTime;
}

//** calls render on all game entities*/

void Game::render()
{


	Colour black(0,0,0);

	renderer.clear(black);// prepare for new frame
	
	//render every object
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(), e= gameObjects.end(); i != e; i++) {
		(*i)->Render(renderer);
	}

	//renderer.drawRect(Rect(100, 100, 50, 50), Colour(255, 100, 50));
	renderer.present();// display the new frame

	
}

/** update and render game entities*/
void Game::loop()
{
	LTimer capTimer;//to cap framerate
	bool quit = false;
	
	
	InputManager inputManager;

	int frameNum = 0;
	while (!quit) {
		capTimer.start();

		inputManager.ProcessInput();

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
