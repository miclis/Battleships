#ifndef CHECKVALIDITY_H_
#define CHECKVALIDITY_H_

#include "Player.h"
#include "Ship.h"
#include "Point.h"
#include "Grid.h"


class CheckValidity
{
public:
	CheckValidity();
	bool CheckIfArrangedProperly(Point *cord, Grid *grid);
	bool CheckIfTwoFunnelArrangedProperly(Point *cord1, Point *cord2, Grid *grid);
	bool CheckIfThreeFunnelArrangedProperly(Point *cord1, Point *cord2,Point *cord3, Grid *grid);
	bool CheckIfCanShoot(int whichShip, Point *whereToShoot, Grid *grid);
	bool CheckIfCanSelect(int whichShip, Grid *grid, Grid *opponentGrid, vector<class Ship*> ships);
	bool CheckIfProperAnswer(char answer);
};

#endif