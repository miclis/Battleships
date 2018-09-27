#include "GreedyStrategy.h"

GreedyStrategy::GreedyStrategy()
{

}
Ship* GreedyStrategy::SelectShip(Grid *grid, Grid *opponentGrid, vector<class Ship*> ships)
{
	if (ships.at(2)->CheckIfCanSelect() && ships.at(2)->CheckIfOpponentsGrid(opponentGrid, ships.at(2)) ) return ships.at(2);
	else if (ships.at(1)->CheckIfCanSelect() && ships.at(2)->CheckIfOpponentsGrid(opponentGrid, ships.at(1)) ) return ships.at(1);
	else if (ships.at(0)->CheckIfCanSelect() && ships.at(2)->CheckIfOpponentsGrid(opponentGrid, ships.at(0)) ) return ships.at(0);
	else
	{
		OneFunnel EMPTY;
		EMPTY.SetEmpty();
		return &EMPTY;
	}

	//-------------------

	/*int whichtoselect;
	vector<Ship*> playerShips = grid->ReturnShipInfo();
	
	if (playerShips.at(3)->CheckIfCanShoot(grid)) whichtoselect = 3;
	else if (playerShips.at(2)->CheckIfCanShoot(grid)) whichtoselect = 2;
	else if (playerShips.at(1)->CheckIfCanShoot(grid)) whichtoselect = 1;
	else
	{
		OneFunnel EMPTY;
		EMPTY.SetEmpty();
		return &EMPTY;
	}
	return playerShips.at(whichtoselect);*/
}