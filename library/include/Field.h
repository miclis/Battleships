#ifndef FIELD_H_
#define FIELD_H_

class Grid;

class Field
{
private:
	bool isShoot;
	int isShip;
	bool inRange1;
	bool inRange2;
	bool inRange3;
public:
	Field();
	void PlaceShip(int whichShip);
	void SetIsShoot();
	void SetInRange(int whichShip);
	bool GetIsShoot();
	int GetIsShip();
	bool GetInRange1();
	bool GetInRange2();
	bool GetInRange3();
};
#endif