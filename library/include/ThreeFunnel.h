#ifndef THREEFUNNEL_H_
#define THREEFUNNEL_H_

#include "Point.h"
#include <vector>
#include "Ship.h"
//#include "Funnel.h"

class ThreeFunnel : public Ship
{
public:
	ThreeFunnel();
	ThreeFunnel(vector<Point*> point);
	virtual void CalculateRange(Grid* grid, Ship* chosenShip);
};
#endif