#ifndef RANDOMSTRATEGY_H_
#define RANDOMSTRATEGY_H_

#include "Ship.h"
#include "Player.h"
#include "ComputerStrategy.h"
#include "OneFunnel.h"

class RandomStrategy //: public ComputerStrategy
{
public:
	RandomStrategy();
	//virtual
	Ship* SelectShip(Grid* grid, Grid *opponentGrid, vector<class Ship*> ships);
};
#endif