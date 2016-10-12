#include "stdafx.h"

#include "Box.h"


Box::Box()
{
}

Box::~Box()
{
}

void Box::Render(Renderer& r) {
	r.drawRect(rect,col);
}
void Box::Update(unsigned int deltaTime) {

	float radius = rect.pos.length();
	angle += angVel*deltaTime/1000;
	rect.pos.x = radius*(float)cos(angle);
	rect.pos.y = radius*(float)sin(angle);

}