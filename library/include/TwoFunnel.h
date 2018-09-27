#ifndef TWOFUNNEL_H_
#define TWOFUNNEL_H_

#include "Point.h"
#include <vector>
#include "Ship.h"

class TwoFunnel : public Ship
{
public:
	TwoFunnel();
	TwoFunnel(vector<Point*> point);
	virtual void CalculateRange(Grid *grid, Ship* chosenShip);
};
#endif