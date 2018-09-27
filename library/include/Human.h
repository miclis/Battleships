#ifndef HUMAN_H_
#define HUMAN_H_


//#include "Ship.h"
//#include "OneFunnel.h"
//#include "TwoFunnel.h"
//#include "ThreeFunnel.h"
#include "CheckValidity.h"
#include "Player.h"
#include "HumanInterface.h"
#include "Display.h"
#include "Grid.h"

#include <cstdlib>
#include <iostream>


using namespace std;

class HumanInterface;

class Human : public Player
{
private:
	HumanInterface *ui;
public:
	Human(HumanInterface *ui, string name = "Human");
	virtual vector<Point*> ArrangeShips(Grid *baseGrid, Grid* targetGrid, Display *disp, int player = 1);
	virtual void PlayTurn(Display *disp, Player *player, Grid *baseGridOwn, Grid *baseGridOpponent, Grid *targetGridOwn, Grid *targetGridOpponent, vector<class Ship*> ships, ComputerStrategy* strategy = NULL);
};
#endif
