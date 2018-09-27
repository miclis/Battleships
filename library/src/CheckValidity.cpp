#include "CheckValidity.h"

using namespace std;

CheckValidity::CheckValidity()
{

}
bool CheckValidity::CheckIfArrangedProperly(Point *cord, Grid *grid)
{
	if (cord->x < 0 || cord->x >= 10 || cord->y < 0 || cord->y >= 10) return false;

	bool flag = false;

	for (int x = cord->x - 1; x <= cord->x + 1; x++)
	{
		for (int y = cord->y - 1; y <= cord->y + 1; y++)
		{
			if (x >= 0 && x <= 9 && y >= 0 && y <= 9 && (grid->GetIsShip(x, y) == true)) return false;
		}
	}
	return true;
}
bool CheckValidity::CheckIfTwoFunnelArrangedProperly(Point *cord1, Point *cord2, Grid *grid)
{
	if (cord2->x == cord1->x)
	{
		if (cord2->y == cord1->y + 1 || cord2->y == cord1->y - 1) return true;
		else return false;
	}
	else if (cord2->y == cord1->y)
	{
		if (cord2->x == cord1->x + 1 || cord2->x == cord1->x - 1) return true;
		else return false;
	}
	else return false;
}
bool CheckValidity::CheckIfThreeFunnelArrangedProperly(Point *cord1, Point *cord2, Point *cord3, Grid *grid)
{
	if (cord1->x == cord2->x && cord3->x == cord1->x)
	{
		if (cord1->y < cord2->y)
		{
			if ((cord3->y == cord2->y + 1) || (cord3->y == cord1->y - 1)) return true;
			else return false;
		}
		else if (cord1->y > cord2->y)
		{
			if ((cord3->y == cord2->y - 1) || (cord3->y == cord1->y + 1)) return true;
			else return false;
		}
		else return false;
	}
	else if (cord1->y == cord2->y && cord3->y == cord1->y)
	{
		if (cord1->x < cord2->x)
		{
			if ((cord3->x == cord2->x + 1) || (cord3->x == cord1->x - 1)) return true;
			else return false;
		}
		else if (cord1->x > cord2->x)
		{
			if ((cord3->x == cord2->x - 1) || (cord3->x == cord1->x + 1)) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
bool CheckValidity::CheckIfCanShoot(int whichShip, Point *whereToShoot, Grid *grid)
{
	if (whereToShoot->x < 0 || whereToShoot->x > 9 || whereToShoot->y < 0 || whereToShoot->y > 9) return false;
	if (grid->GetIsShoot(whereToShoot->x,whereToShoot->y)) return false;
	else if (whichShip == 1 && grid->ReturnFieldInfo(whereToShoot->x, whereToShoot->y)->GetInRange1() == false) return false;
	else if (whichShip == 2 && grid->ReturnFieldInfo(whereToShoot->x, whereToShoot->y)->GetInRange2() == false) return false;
	else if (whichShip == 3 && grid->ReturnFieldInfo(whereToShoot->x, whereToShoot->y)->GetInRange3() == false) return false;
	else return true;
}
// Check if ship has HP and can shoot in this round
bool CheckValidity::CheckIfCanSelect(int whichShip, Grid *grid, Grid *opponentGrid, vector<class Ship*> ships)
{
	if (whichShip == 1)
	{
		if (ships.at(0)->CheckIfCanSelect() && ships.at(0)->CheckIfOpponentsGrid(opponentGrid, ships.at(0)) ) return true;
		else return false;
	}
	else if (whichShip == 2)
	{
		if ( ships.at(1)->CheckIfCanSelect() && ships.at(1)->CheckIfOpponentsGrid(opponentGrid, ships.at(1)) ) return true;
		else return false;
	}
	else if (whichShip == 3)
	{
		if ( ships.at(2)->CheckIfCanSelect() && ships.at(2)->CheckIfOpponentsGrid(opponentGrid, ships.at(2)) ) return true;
		else return false;
	}
	else return false;

}
bool CheckValidity::CheckIfProperAnswer(char answer)
{
	if (answer == 'Y' || answer == 'y' || answer == 'N' || answer == 'n') return true;
	else return false;
}