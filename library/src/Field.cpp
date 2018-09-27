#include "Field.h"

using namespace std;

Field::Field()
{
	isShoot = false;
	isShip = 0;
	inRange1 = false;
	inRange2 = false;
	inRange3 = false;
}
void Field::PlaceShip(int whichShip)
{
	isShip = whichShip;
}
void Field::SetIsShoot()
{
	isShoot = true;
}
void Field::SetInRange(int whichShip)
{
	if (whichShip == 1) inRange1 = true;
	else if (whichShip == 2) inRange2 = true;
	else if (whichShip == 3) inRange3 = true;
}
bool Field::GetIsShoot()
{
	if (isShoot) return true;
	else return false;
}
//done
int Field::GetIsShip()
{
	return isShip;
}
bool Field::GetInRange1()
{
	return inRange1;
}
bool Field::GetInRange2()
{
	return inRange2;
}
bool Field::GetInRange3()
{
	return inRange3;
}