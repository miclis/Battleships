#include "Human.h"

using namespace std;

Human::Human(HumanInterface *ui, string name) : Player(name)
{
	SetName(name);
	this->ui = ui;
}
vector<Point*> Human::ArrangeShips(Grid *baseGrid, Grid* targetGrid, Display *disp, int player)
{
	return ui->AskWhereToArrange(baseGrid, targetGrid, disp, player);
}
void Human::PlayTurn(Display *disp, Player *player, Grid *baseGridOwn, Grid *baseGridOpponent, Grid *targetGridOwn, Grid *targetGridOpponent, vector<class Ship*> ships, ComputerStrategy* strategy)
{
	//Ship selection
	selectedShip = ui->SelectShip(baseGridOwn, baseGridOpponent, ships);

	//Removing isWaiting flag from ships
	for (auto i = ships.size();i != 0;i--)
	{
		ships.at(i-1)->LetAct();
	}

	//Shot
	Point *target = new Point(ui->AskWhereToShoot(selectedShip, targetGridOwn));
	disp->DrawShoot(*target, disp->GiveGridPt(3));
	disp->UpdateGrid(false);
	//If target was hit
	if (selectedShip->Shoot(*target, targetGridOwn, baseGridOpponent, disp))
	{
		disp->DrawShoot(*target, disp->GiveGridPt(2));
		disp->DrawShip(*target, disp->GiveGridPt(3));
	}
	///else disp->MissText();
	//If can shoot multiple times
	if (selectedShip->GetWhichShip() == 2 || selectedShip->GetWhichShip() == 3)
	{
		//If there is a place it can shoot
		if(selectedShip->CheckIfOpponentsGrid(targetGridOwn,selectedShip))
		{
			if (ui->AskIfShootAgain(disp))
			{
				target = new Point(ui->AskWhereToShoot(selectedShip, targetGridOwn));
				disp->DrawShoot(*target, disp->GiveGridPt(3));
				//If target was hit
				if (selectedShip->Shoot(*target, targetGridOwn, baseGridOpponent, disp))
				{
					disp->DrawShoot(*target, disp->GiveGridPt(2));
					disp->DrawShip(*target, disp->GiveGridPt(3));
				}
				///else disp->MissText();
				selectedShip->OrderToWait();
			}
		}
	}

	delete target;
}
