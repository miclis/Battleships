#ifndef PLAYER_H_
#define PLAYER_H_


#include "Ship.h"
#include "Point.h"
#include "Grid.h"
//#include "HumanInterface.h"
#include <iostream>
#include "Display.h"

using namespace std;

class ComputerStrategy;

class Player
{
protected:
	Ship* selectedShip;
	string name;
private:
	int playerNumber;
public:
	Player();
	Player(string name);
	~Player();

	virtual vector<Point*> ArrangeShips(Grid *baseGrid, Grid* targetGrid, Display *disp, int player) = 0;
	virtual void PlayTurn(Display *disp, Player *player, Grid *baseGridOwn, Grid *baseGridOpponent, Grid *targetGridOwn, Grid *targetGridOpponent, vector<class Ship*> ships, ComputerStrategy* strategy) = 0;
	void SetName(string name);
	void SetNumber(int number);
	int GetPlayerNumber();
	string GetPlayerName();
	bool IsEnd(Grid *targetGridOwn, vector<class Ship*> ships);
};

#endif