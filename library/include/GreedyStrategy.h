#ifndef GREEDYSTRATEGY_H_
#define GREEDYSTRATEGY_H_

#include "ComputerStrategy.h"
#include "Ship.h"

class GreedyStrategy
{
public:
	GreedyStrategy();
	Ship* SelectShip(Grid *grid, Grid *opponentGrid, vector<class Ship*> ships);
};

#endif