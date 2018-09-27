#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Point.h"
#include "Field.h"
#include "Ship.h"

using std::vector;

class Grid //: public Field
{
private:
	Field *square[10][10];
	vector<class Ship*> *ships;
public:
	Grid();
	~Grid();
	void Shoot(Point *target);
	bool GetIsShip(int x, int y);
	int GetWhichShip(Point *point);
	Field* ReturnFieldInfo(int x,int y);
	bool GetIsShoot(int x, int y);
	void PlaceShip(Point *point, int whichShip);
	void SetInRange(Point *cord, int whichShip);

	bool GetInRange1(int x, int y);
	bool GetInRange2(int x, int y);
	bool GetInRange3(int x, int y);

	void SetShipsVector(vector<Ship*> *ships);
	vector<Ship*> ReturnShipInfo();
};
#endif