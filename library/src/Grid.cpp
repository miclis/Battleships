#include "Grid.h"

Grid::Grid()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			square[x][y] = new Field();
		}
	}
}
Grid::~Grid()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			delete square[x][y];
		}
	}
}
void Grid::Shoot(Point *target)
{
	square[target->x][target->y]->SetIsShoot();
}
bool Grid::GetIsShip(int x, int y)
{
	if (square[x][y]->GetIsShip() != 0) return true;
	else return false;
}
int Grid::GetWhichShip(Point* point)
{
	return square[point->x][point->y]->GetIsShip();
}
Field* Grid::ReturnFieldInfo(int x,int y)
{
	return square[x][y];
}
bool Grid::GetIsShoot(int x, int y)
{
	if (square[x][y]->GetIsShoot()) return true;
	else return false;
}
void Grid::PlaceShip(Point *point, int whichShip)
{
	square[point->x][point->y]->PlaceShip(whichShip);
}
vector<Ship*> Grid::ReturnShipInfo()
{
	return *ships;
}
void Grid::SetInRange(Point *cord, int whichShip)
{
	square[cord->x][cord->y]->SetInRange(whichShip);
}

bool Grid::GetInRange1(int x, int y)
{
	return square[x][y]->GetInRange1();
}
bool Grid::GetInRange2(int x, int y)
{
	return square[x][y]->GetInRange2();
}
bool Grid::GetInRange3(int x, int y)
{
	return square[x][y]->GetInRange3();
}
void Grid::SetShipsVector(vector<Ship*> *ships)
{
	this->ships = ships;
}