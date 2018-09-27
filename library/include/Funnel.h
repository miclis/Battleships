#ifndef FUNNEL_H_
#define FUNNEL_H_

#include "Point.h"

struct Funnel 
{
	Point pt;
	bool alive;
	Funnel(Point *point);
	bool GetAlive() { return alive; }
	Point GetPosition() { return pt; }
};
#endif