#ifndef COMPUTER_H_
#define COMPUTER_H_

#include "GameLogic.h"

#include "Ship.h"
#include "Grid.h"
#include "OneFunnel.h"
#include "TwoFunnel.h"
#include "ThreeFunnel.h"

#include "Player.h"
#include "RandomStrategy.h"
#include "GreedyStrategy.h"
#include "ComputerStrategy.h"

#include <cstdlib>
//#include <iostream>

class Computer : public Player
{
private:
	//Ship *selectedShip;
public:
	Computer(int playerNumber, string name = "Computer");
	vector<Point*> ArrangeShips(Grid *baseGrid, Grid* targetGrid, Display *disp, int player);
	bool CheckIfArrangedProperly(Point *cord, Grid *grid);
	virtual void PlayTurn(Display *disp, Player *player, Grid *baseGridOwn, Grid *baseGridOpponent, Grid *targetGridOwn, Grid *targetGridOpponent, vector<class Ship*> ships, ComputerStrategy* strategy);
	Point FindTarget(Grid* targetGridOwn, Grid *baseGridOpponent);
};

#endif