#ifndef COMPUTERSTRATEGY_H_
#define COMPUTERSTRATEGY_H_

#include "Ship.h"
#include "Player.h"
#include "OneFunnel.h"

#include "RandomStrategy.h"
#include "GreedyStrategy.h"
#include "Computer.h"

class ComputerStrategy
{
private:
	bool *strategy;

public:
	ComputerStrategy(bool *strategy);
	Ship* SelectShip(Grid *grid, Grid *opponentGrid, vector<class Ship*> ships);
};

#endif
