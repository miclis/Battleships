#include "ComputerStrategy.h"

using namespace std;

ComputerStrategy::ComputerStrategy(bool *strategy)
{
	this->strategy = strategy;
}

Ship* ComputerStrategy::SelectShip(Grid *grid, Grid *opponentGrid, vector<class Ship*> ships)
{
	if (strategy == 0)
	{
		RandomStrategy myStrategy;
		//cout << "random" << endl;
		return myStrategy.SelectShip(grid, opponentGrid, ships);
	}
	else
	{
		GreedyStrategy myStrategy;
		//cout << "greedy" << endl;
		return myStrategy.SelectShip(grid, opponentGrid, ships);
	}
}
