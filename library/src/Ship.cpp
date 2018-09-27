#include "Ship.h"

using namespace std;

vector<Point> Ship::ReturnShipPosition()
{
	vector<Point> shipPos;
	for (auto i = funnels.begin(); i != funnels.end(); ++i)
	{
		shipPos.push_back(i->GetPosition());
	}
	return shipPos;
}
Ship::~Ship()
{

}
void Ship::KillFunnel(Point *point, Display *disp)
{
	int isAlive = true;
	for (auto i = funnels.begin();i != funnels.end();++i)
	{
		if (i->pt.x == point->x && i->pt.y == point->y)
		{
			i->alive = false;
			HP -= 1;
		}
	}
	disp->HitText();
	if (HP == 0)
	{
		disp->SunkText();
	}
}
int Ship::GetHP()
{
	return HP;
}
void Ship::LetAct()
{
	isWaiting = false;
}
bool Ship::GetIsWaiting()
{
	return isWaiting;
}
int Ship::GetWhichShip()
{
	return funnels.size();
}
void Ship::SetHP(int HP)
{
	this->HP = HP;
}
void Ship::SetRange(int range)
{
	this->range = range;
}
void Ship::OrderToWait()
{
	isWaiting = true;
}
bool Ship::CheckIfCanShoot(Grid *grid)	//CheckIfCanSelect
{
	bool flag = false;
	int living = 0;
	for (int x = 0;x <= 9;++x)
	{
		for (int y = 0;y <= 9;++y)
		{
			if (GetWhichShip() == 1)
			{
				if (grid->ReturnFieldInfo(x, y)->GetInRange1() == GetWhichShip() && !grid->GetIsShoot(x, y))	//GetWhichShip ==1
				{
					flag = true;
				}
			}
			if (GetWhichShip() == 2)
			{
				if (grid->ReturnFieldInfo(x, y)->GetInRange2() == GetWhichShip() && !grid->GetIsShoot(x, y))
				{
					flag = true;
				}
			}
			if (GetWhichShip() == 3)
			{
				if (grid->ReturnFieldInfo(x, y)->GetInRange3() == GetWhichShip() && !grid->GetIsShoot(x, y))
				{
					flag = true;
				}
			}
		}
	}
	for (auto i = funnels.begin();i != funnels.end();++i)
	{
		living += i->alive;
	}
	if (living == 0) flag = false;
	if (isWaiting == true) flag = false;

	return flag;
}
bool Ship::CheckIfCanSelect()
{
	if (HP == 0) return false;
	else if (isWaiting) return false;
	else return true;
}
bool Ship::CheckIfOpponentsGrid(Grid *targetGridOwn, Ship *chosenShip)
{
	bool canBeShoot = false;
	Point *point = new Point();
	// Check if there is a place in the range of the ship that wasn't shoot on the opponent's grid !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int x = 0; x <= range; x++)	// <= czy <   ???
	{
		for (int y = 0; y <= range; y++)
		{
			for (auto it = chosenShip->funnels.begin(); it != chosenShip->funnels.end(); ++it)
			{
				if (it->GetPosition().x - x >= 0 && it->GetPosition().y - y >= 0)
				{
					point->x = it->GetPosition().x - x;
					point->y = it->GetPosition().y - y;
					if (!targetGridOwn->GetIsShoot(point->x, point->y)) { canBeShoot = true; break; }
				}
				if (it->GetPosition().x - x >= 0 && it->GetPosition().y + y <= 9)
				{
					point->x = it->GetPosition().x - x;
					point->y = it->GetPosition().y + y;
					if (!targetGridOwn->GetIsShoot(point->x, point->y)) { canBeShoot = true; break; }
				}
				if (it->GetPosition().x + x <= 9 && it->GetPosition().y - y >= 0)
				{
					point->x = it->GetPosition().x + x;
					point->y = it->GetPosition().y - y;
					if (!targetGridOwn->GetIsShoot(point->x, point->y)) { canBeShoot = true; break; }
				}
				if (it->GetPosition().x + x <= 9 && it->GetPosition().y + y <= 9)
				{
					point->x = it->GetPosition().x + x;
					point->y = it->GetPosition().y + y;
					if (!targetGridOwn->GetIsShoot(point->x, point->y)) { canBeShoot = true; break; }
				}
			}
		}
	}
	if (!canBeShoot) return false;
	else return true;
}

void Ship::SetEmpty()
{
	empty = true;
}

bool Ship::CheckIfEmpty()
{
	return empty;
}
bool Ship::Shoot(Point point, Grid* targetGridOwn, Grid* baseGridOpponent, Display* disp)
{
	targetGridOwn->Shoot(&point);
	baseGridOpponent->Shoot(&point);
	if (baseGridOpponent->GetIsShip(point.x, point.y) == true)
	{
		int whichShipToHit = baseGridOpponent->GetWhichShip(&point) - 1;
		vector<class Ship*> opponentShips = baseGridOpponent->ReturnShipInfo();
		opponentShips.at(whichShipToHit)->KillFunnel(&point,disp);
		return true;
	}
	return false;
}