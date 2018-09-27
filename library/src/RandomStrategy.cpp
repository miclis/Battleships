#include "RandomStrategy.h"

RandomStrategy::RandomStrategy()
{

}
Ship* RandomStrategy::SelectShip(Grid* grid,Grid *opponentGrid, vector<class Ship*> ships)
{
	int whichToSelect;
	bool ifCheckedShip1 = false;
	bool ifCheckedShip2 = false;
	bool ifCheckedShip3 = false;

	do{

		whichToSelect = rand() % 3;
		if (whichToSelect == 0)
		{
			ifCheckedShip1 = true;
		}
		else if (whichToSelect == 1) 
		{
			ifCheckedShip2 = true;
		}
		else
		{
			ifCheckedShip3 = true;
		}

	} while (  !(ships.at(whichToSelect)->CheckIfCanSelect()  ||  ships.at(whichToSelect)->CheckIfOpponentsGrid(opponentGrid, ships.at(whichToSelect)) ) || (!ifCheckedShip1 && !ifCheckedShip2 && !ifCheckedShip3) );	// || (!ifCheckedShip1 && !ifCheckedShip2 && !ifCheckedShip3)  - NOT SURE IF OK

	if ( ships.at(whichToSelect)->CheckIfCanSelect()  &&  ships.at(whichToSelect)->CheckIfOpponentsGrid(opponentGrid, ships.at(whichToSelect)) ) return ships.at(whichToSelect);
	else
	{
		OneFunnel EMPTY;
		EMPTY.SetEmpty();
		return &EMPTY;
	}

	//---------------
	/*bool ship0 = 0;
	bool ship1 = 0;
	bool ship2 = 0;

	int whichtoselect = 1 + rand() % 3;
	vector<Ship*> playerShips = grid->ReturnShipInfo();

	while ((!playerShips.at(whichtoselect)->CheckIfCanShoot(grid)) && !(ship0 && ship1 && ship2))
	{
		if (whichtoselect = 1) ship0 = true;
		if (whichtoselect = 2) ship1 = true;
		if (whichtoselect = 3) ship2 = true;
		whichtoselect = 1 + rand() % playerShips.size();
	}
	if (ship0 && ship1 && ship2)
	{
		OneFunnel EMPTY;
		EMPTY.SetEmpty();
		return &EMPTY;
	}
	return playerShips.at(whichtoselect);*/
}