#include "ThreeFunnel.h"

using namespace std;

ThreeFunnel::ThreeFunnel() : Ship()
{
	SetRange(4);
	SetHP(3);
}
ThreeFunnel::ThreeFunnel(vector<Point*> point) : Ship()
{
	SetRange(4);
	SetHP(3);
	for (auto it = point.begin(); it != point.end(); ++it)
	{
		Funnel *newFunnel = new Funnel(*it);
		funnels.push_back(*newFunnel);
	}
}
void ThreeFunnel::CalculateRange(Grid *grid, Ship* chosenShip)
{
	int x1, y1;
	vector<Point> position = chosenShip->ReturnShipPosition();

	for (auto it = position.begin(); it != position.end(); ++it)
	{
		x1 = it->x;
		y1 = it->y;
		Point temp;

		for (int j = y1 + range; j >= y1 - range; --j)
		{
			for (int i = x1 - range; i <= x1 + range; ++i)
			{
				if (i >= 0 && i < 10 && j >= 0 && j < 10)
				{
					temp.x = i;
					temp.y = j;
					grid->SetInRange(&temp, 3);
				}
			}
		}
	}

}