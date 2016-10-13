#pragma once

#include "GameObject.h"
#include "BasicTypes.h"

class SpinningBox:public GameObject
{
	
public:
	SpinningBox(Rect r) :rect(r) { angle = angVel = .0f; };
	SpinningBox();
	~SpinningBox();

	Rect rect;
	Colour col;

	float angle, angVel; //control rate of spin

	void Render(Renderer & r);

	void Update(unsigned int deltaTime);

};

