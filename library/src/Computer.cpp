#include "Computer.h"

//using namespace std;

Computer::Computer(int number, string name) : Player(name)
{
	SetName(name);
	SetNumber(number);
}
vector<Point*> Computer::ArrangeShips(Grid *basegrid, Grid *targetgrid, Display *disp, int player)
{
	//------------------Arranging One Funnel Ship------------------
	Point *cord11 = new Point();
		
	vector<Point*> points;
	
	cord11->x = rand() % 10;
	cord11->y = rand() % 10;

	points.push_back(cord11);
	
	basegrid->PlaceShip(cord11, 1);

	disp->DrawShip(*cord11, disp->GiveGridPt(player));
	
	//------------------Arranging Two Funnel Ship------------------
	Point *cord21 = new Point();
	Point *cord22 = new Point();

	do {
		cord21->x = rand() % 10;
		cord21->y = rand() % 10;

	} while (!CheckIfArrangedProperly(cord21, basegrid));

	int random;
		
	do {
		cord22->x = rand() % 3 + (cord21->x - 1);
		if (cord22->x == cord21->x)
		{

			random = rand() % 2;
			if (random == 0) cord22->y = cord21->y - 1;
			else cord22->y = cord21->y + 1;

		}
		else cord22->y = cord21->y;

	} while (!CheckIfArrangedProperly(cord22, basegrid));
	
	points.push_back(cord21);
	points.push_back(cord22);

	basegrid->PlaceShip(cord21, 2);
	basegrid->PlaceShip(cord22, 2);

	disp->DrawShip(*cord21, disp->GiveGridPt(player));
	disp->DrawShip(*cord22, disp->GiveGridPt(player));

	//---------------------Arranging Three Funnel Ship------------------------
	Point *cord31 = new Point();
	Point *cord32 = new Point();
	Point *cord33 = new Point();

	bool wrongThreeFunnel = true;
	do
	{
		do {
			cord31->x = rand() % 10;
			cord31->y = rand() % 10;

		} while (!CheckIfArrangedProperly(cord31, basegrid));

		do {
			cord32->x = rand() % 3 + (cord31->x - 1);
			if (cord32->x == cord31->x)
			{
				random = rand() % 2;
				if (random == 0) cord32->y = cord31->y - 1;
				else cord32->y = cord31->y + 1;
			}
			else cord32->y = cord31->y;

		} while (!CheckIfArrangedProperly(cord32, basegrid));

		if (cord31->x == cord32->x)
		{
			cord33->x = cord32->x;

			if (cord31->y < cord32->y) cord33->y = cord32->y + 1;
			else cord33->y = cord32->y - 1;

			if (!CheckIfArrangedProperly(cord33, basegrid))
			{
				if (cord31->y < cord32->y) cord33->y = cord31->y - 1;
				else cord33->y = cord31->y + 1;
			}
			if (CheckIfArrangedProperly(cord33, basegrid)) wrongThreeFunnel = false;
		}
		else {
			cord33->y = cord32->y;

			if (cord31->x < cord32->x) cord33->x = cord32->x + 1;
			else cord33->x = cord32->x - 1;

			if (!CheckIfArrangedProperly(cord33, basegrid))
			{
				if (cord31->x < cord32->x) cord33->x = cord31->x - 1;
				else cord33->x = cord31->x + 1;
			}
			if (CheckIfArrangedProperly(cord33, basegrid)) wrongThreeFunnel = false;
		}

	}while (wrongThreeFunnel);

	points.push_back(cord31);
	points.push_back(cord32);
	points.push_back(cord33);

	basegrid->PlaceShip(cord31, 3);
	basegrid->PlaceShip(cord32, 3);
	basegrid->PlaceShip(cord33, 3);

	disp->DrawShip(*cord31, disp->GiveGridPt(player));
	disp->DrawShip(*cord32, disp->GiveGridPt(player));
	disp->DrawShip(*cord33, disp->GiveGridPt(player));

	return points;
}
bool Computer::CheckIfArrangedProperly(Point *cord, Grid *grid)
{
	if (cord->x < 0 || cord->x >= 10 || cord->y < 0 || cord->y >= 10) return false;

	for (int x = cord->x - 1; x <= cord->x + 1; x++)
	{
		for (int y = cord->y - 1; y <= cord->y + 1; y++)
		{
			if (x >= 0 && x <= 9 && y >= 0 && y <= 9 && (grid->GetIsShip(x, y) == true)) return false;
		}
	}
	return true;
}
void Computer::PlayTurn(Display *disp, Player *player, Grid *baseGridOwn, Grid *baseGridOpponent, Grid *targetGridOwn, Grid *targetGridOpponent, vector<class Ship*> ships, ComputerStrategy* strategy)
{
	//Ship selection
	selectedShip = strategy->SelectShip(baseGridOwn, baseGridOpponent, ships);
	if (selectedShip->CheckIfEmpty())	//Checks if there is a ship selected 
	{
		cout << "Computer cannot select ship..." << endl;	//debug
	}

	//Removing isWaiting flag from ships
	for (auto i = ships.size();i != 0;i--)
	{
		ships.at(i - 1)->LetAct();
	}

	//Shot
	Point *target = new Point(FindTarget(targetGridOwn, baseGridOpponent));
	
	if (selectedShip->Shoot(*target, targetGridOwn, baseGridOpponent, disp))
	{
		if (player->GetPlayerNumber() == 1)
		{
			disp->DrawShoot(*target, disp->GiveGridPt(2));
			disp->DrawShip(*target, disp->GiveGridPt(3));
		}
		else if (player->GetPlayerNumber() == 2)
		{
			disp->DrawShoot(*target, disp->GiveGridPt(1));
			disp->DrawShip(*target, disp->GiveGridPt(4));
		}
	}
	///else disp->MissText();
	if (player->GetPlayerNumber() == 1) disp->DrawShoot(*target, disp->GiveGridPt(3));
	if (player->GetPlayerNumber() == 2) disp->DrawShoot(*target, disp->GiveGridPt(4));
	//If can shoot mulitple times
	if (selectedShip->GetWhichShip() == 2 || selectedShip->GetWhichShip() == 3)
	{
		//If there is a place it can shoot
		if (selectedShip->CheckIfOpponentsGrid(targetGridOwn,selectedShip))
		{
			///Option for random chance for a second shoot (uncomment)
			/*
			//Randomly choses wheter to shoot twice and wait or not to
			bool ifShootAgain = rand() % 2;	//false or true
			if (ifShootAgain)
			{*/
				target = new Point(FindTarget(targetGridOwn, baseGridOpponent));

				if (selectedShip->Shoot(*target, targetGridOwn, baseGridOpponent, disp))
				{
					if (player->GetPlayerNumber() == 1)
					{
						disp->DrawShoot(*target, disp->GiveGridPt(2));
						disp->DrawShip(*target, disp->GiveGridPt(3));
					}
					else if (player->GetPlayerNumber() == 2)
					{
						disp->DrawShoot(*target, disp->GiveGridPt(1));
						disp->DrawShip(*target, disp->GiveGridPt(4));
					}
				}
				///else disp->MissText();
				if (player->GetPlayerNumber() == 1) disp->DrawShoot(*target, disp->GiveGridPt(3));
				if (player->GetPlayerNumber() == 2) disp->DrawShoot(*target, disp->GiveGridPt(4));
				selectedShip->OrderToWait();
			//}
		}
	}

	delete target;
}
Point Computer::FindTarget(Grid* targetGridOwn, Grid *baseGridOpponent)
{
	srand(time(NULL));
	int *whichShip = new int(selectedShip->GetWhichShip());
	vector<Point*> *possibleTargets = new vector<Point*>;
	Point target;
	//Finding suitable targets
	for (int x = 0; x <= 9; x++)
	{
		for (int y = 0; y <= 9; y++)
		{
			if (*whichShip == 1)
			{
				if (targetGridOwn->GetInRange1(x, y) && !targetGridOwn->GetIsShoot(x,y))
				{
					possibleTargets->push_back(new Point(x, y));
				}
				
			}
			else if (*whichShip == 2)
			{
				if (targetGridOwn->GetInRange2(x, y) && !targetGridOwn->GetIsShoot(x, y))
				{
					possibleTargets->push_back(new Point(x, y));
				}
			}
			else
			{
				if (targetGridOwn->GetInRange3(x, y) && !targetGridOwn->GetIsShoot(x, y))
				{
					possibleTargets->push_back(new Point(x, y));
				}
			}

		}
	}
	//Checking for likely targets
	//vector<Point*> *likelyTargets = new vector<Point*>;


	//Randomly choosing one
	target = *possibleTargets->at(rand() % possibleTargets->size());

	for (auto it = possibleTargets->begin();it != possibleTargets->end();++it)
	{
		delete (*it);
	}

	return target;
}