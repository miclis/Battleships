#ifndef HUMANINTERFACE_H_
#define HUMANINTERFACE_H_

#include "Player.h"
#include "Ship.h"
#include "Point.h"
#include "Grid.h"
#include "Human.h"

#include "CheckValidity.h"
#include "OneFunnel.h"
#include "TwoFunnel.h"
#include "ThreeFunnel.h"

#include <cstdlib>		// to use function: "system()"
#include "time.h"
#include <iostream>
#include <string>

using namespace std;

class Human;
class Display;

class HumanInterface
{
private:
	CheckValidity check;
public:
	HumanInterface();
	vector<Point*> AskWhereToArrange(Grid *baseGrid, Grid *targetGrid, Display *disp, int player);
	Ship* SelectShip(Grid *grid, Grid *opponentGrid, vector<class Ship*> ships, Display *disp = NULL);
	Point AskWhereToShoot(Ship *ship, Grid *grid);
	bool AskIfDrawRange(Display *disp);
	bool AskIfEnableCheats(Display *disp);
	bool AskIfShootAgain(Display *disp);
};
#endif