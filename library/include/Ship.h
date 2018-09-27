#ifndef SHIP_H_
#define SHIP_H_

#include "Point.h"
#include "Funnel.h"
#include "Grid.h"
#include "Display.h"

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Display;	//forward declaration

class Ship
{
protected:
	vector<Funnel> funnels;
	int range;
private:
	bool isWaiting = false;
	bool empty = false;
	int HP;
	
public:
	virtual ~Ship();
	vector<Point> ReturnShipPosition();
	bool Shoot(Point point, Grid* targetGridOwn, Grid* baseGridOpponent, Display* disp); //marks field on targetOwn and baseOpp as Shot and kills opponent's Funnel if hit
	void KillFunnel(Point *point, Display* disp);	//kills funnel
	virtual void CalculateRange(Grid* grid, Ship* chosenShip) = 0;	//sets fields on grid in range
	
	int GetHP();
	int GetWhichShip();		//returns the number of funnels of the ship
	
	void SetHP(int HP);
	void SetRange(int range);
	void SetEmpty();
	void OrderToWait();
	void LetAct();	//unmarks isWaiting flag
	bool GetIsWaiting();

	bool CheckIfEmpty();
	bool CheckIfCanShoot(Grid *grid);
	bool CheckIfCanSelect();
	bool CheckIfOpponentsGrid(Grid *targetGridOwn, Ship *chosenShip);	//checks if on opponents grid there is a place to shoot
};
#endif