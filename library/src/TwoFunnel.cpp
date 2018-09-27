#include "TwoFunnel.h"

using namespace std;

TwoFunnel::TwoFunnel() : Ship()
{
	SetRange(3);
	SetHP(2);
}
TwoFunnel::TwoFunnel(vector<Point*> point) : Ship()
{
	SetRange(3);
	SetHP(2);
	for (auto it = point.begin(); it != point.end(); ++it)
	{
		Funnel *newFunnel = new Funnel(*it);
		funnels.push_back(*newFunnel);
	}
}

void TwoFunnel::CalculateRange(Grid *grid, Ship* chosenShip)
{
	int x1, y1;
	vector<Point> position = chosenShip->ReturnShipPosition();

	for (auto it = position.begin(); it != position.end(); ++it)
	{
		x1 = it->x;
		y1 = it->y;
		Point *temp = new Point();

		for (int j = y1 + range; j >= y1 - range; j--)
		{
			for (int i = x1 - range; i <= x1 + range; i++)
			{
				if (i >= 0 && i < 10 && j >= 0 && j < 10)
				{
					temp->x = i;
					temp->y = j;
					grid->SetInRange(temp, 2);
				}
			}
		}
	}
}