#ifndef ONEFUNNEL_H_
#define ONEFUNNEL_H_

#include "Point.h"
#include <vector>
#include "Ship.h"

class OneFunnel : public Ship
{
public:
	OneFunnel();
	OneFunnel(vector<Point*> point);
	virtual void CalculateRange(Grid* grid, Ship *chosenShip);
};
#endif