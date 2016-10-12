#pragma once

#include "Renderer.h"
#include "math.h"




class GameObject
{

public:
	GameObject() {};
	virtual ~GameObject() {};

	virtual void Render(Renderer& r)=0;
	virtual void Update(unsigned int deltaTime)=0;


};

