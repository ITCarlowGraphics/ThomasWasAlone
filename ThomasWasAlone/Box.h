#pragma once

#include "GameObject.h"
#include "BasicTypes.h"

class Box:public GameObject
{
	
public:
	Box(Rect r) :rect(r) { angle = angVel = .0f; };
	Box();
	~Box();

	Rect rect;
	Colour col;

	float angle, angVel; //control rate of spin

	void Render(Renderer & r);

	void Update(unsigned int deltaTime);

};

