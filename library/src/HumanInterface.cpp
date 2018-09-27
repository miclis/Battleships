#include "HumanInterface.h"

using namespace std;

HumanInterface::HumanInterface()
{
	
}
vector<Point*> HumanInterface::AskWhereToArrange(Grid *baseGrid, Grid *targetgrid, Display *disp, int player)
{
	cout << "Now you will be arranging ships!" << endl << endl;
	
	//--------------------------OneFunnel ship--------------------------

	cout << "Arrange one-funnel ship" << endl;
	Point *cord11 = new Point();
	bool ifWrong = false;
	do {
		if (ifWrong == true) cout << "Wrong coordinates..." << endl;

		cout << "Give the coordinate of the column:" << endl;
		cin >> cord11->x;
		cout << "Give the coordinate of the row:" << endl;
		cin >> cord11->y;
		cord11->x -= 1;
		cord11->y -= 1;
		ifWrong = true;
	} while (!check.CheckIfArrangedProperly(cord11, baseGrid));

	vector<Point*> points;
	points.push_back(cord11);

	baseGrid->PlaceShip(cord11, 1);	// 1 - means One Funnel Ship

	disp->DrawShip(*cord11, disp->GiveGridPt(player));

	disp->UpdateGrid(false);

	system("cls");
	//-------------------------TwoFunnel ship--------------------------
	disp->HeaderText();
	cout << "Arrange two-funnel ship" << endl;
	Point *cord21 = new Point();
	Point *cord22 = new Point();
	ifWrong = false;
	do {
		if (ifWrong == true) cout << "Wrong coordinates..." << endl;

		cout << "Give the coordinate of the column:" << endl;
		cin >> cord21->x;
		cout << "Give the coordinate of the row:" << endl;
		cin >> cord21->y;
		cord21->x -= 1;
		cord21->y -= 1;
		ifWrong = true;
	} while (!check.CheckIfArrangedProperly(cord21, baseGrid));

	ifWrong = false;
	
	do {
		if (ifWrong == true) cout << "Wrong coordinates..." << endl;

		cout << "Give the coordinate of the column:" << " [current positions are: 1 (" << cord21->x + 1 << "," << cord21->y + 1 << ")]" << endl;
		cin >> cord22->x;
		cout << "Give the coordinate of the row:" << " [current positions are: 1 (" << cord21->x + 1 << "," << cord21->y + 1 << ")]" << endl;
		cin >> cord22->y;
		cord22->x -= 1;
		cord22->y -= 1;
		ifWrong = true;
	} while ( !check.CheckIfArrangedProperly(cord22, baseGrid) || !check.CheckIfTwoFunnelArrangedProperly(cord21, cord22, baseGrid) );

	points.push_back(cord21);
	points.push_back(cord22);

	baseGrid->PlaceShip(cord21, 2);
	baseGrid->PlaceShip(cord22, 2);

	disp->DrawShip(*cord21, disp->GiveGridPt(player));
	disp->DrawShip(*cord22, disp->GiveGridPt(player));

	disp->UpdateGrid(false);

	system("cls");
	//------------------------ThreeFunnel ship----------------------------
	disp->HeaderText();
	cout << "Arrange three-funnel ship" << endl;

	Point *cord31 = new Point();
	Point *cord32 = new Point();
	Point *cord33 = new Point();
	ifWrong = false;
	do {
		if (ifWrong == true) cout << "Wrong coordinates..." << endl;

		cout << "Give the coordinate of the column:" << endl;
		cin >> cord31->x;
		cout << "Give the coordinate of the row:" << endl;
		cin >> cord31->y;
		cord31->x -= 1;
		cord31->y -= 1;
		ifWrong = true;
	} while (!check.CheckIfArrangedProperly(cord31, baseGrid));

	ifWrong = false;
	do {
		if (ifWrong == true) cout << "Wrong coordinates..." << endl;

		cout << "Give the coordinate of the column:" << " [current positions are: 1 (" << cord31->x + 1 << "," << cord31->y + 1 << ")]" << endl;
		cin >> cord32->x;
		cout << "Give the coordinate of the row:" << " [current positions are: 1 (" << cord31->x + 1 << "," << cord31->y + 1 << ")]" << endl;
		cin >> cord32->y;
		cord32->x -= 1;
		cord32->y -= 1;
		ifWrong = true;
	} while ( !check.CheckIfArrangedProperly(cord32, baseGrid) || !check.CheckIfTwoFunnelArrangedProperly(cord31, cord32, baseGrid));

	ifWrong = false;
	do {
		if (ifWrong == true) cout << "Wrong coordinates..." << endl;

		cout << "Give the coordinate of the column:" << " [current positions are: 1 (" << cord31->x + 1 << "," << cord31->y + 1 << ")" << " | 2 (" << cord32->x + 1 <<  ","<< cord32->y + 1 << ")]" << endl;
		cin >> cord33->x;
		cout << "Give the coordinate of the row:" << " [current positions are: 1 (" << cord31->x + 1 << "," << cord31->y + 1 << ")" << " | 2 (" << cord32->x + 1 << "," << cord32->y + 1 << ")]" << endl;
		cin >> cord33->y;
		cord33->x -= 1;
		cord33->y -= 1;
		ifWrong = true;
	} while (!check.CheckIfArrangedProperly(cord33, baseGrid) || !check.CheckIfThreeFunnelArrangedProperly(cord31, cord32, cord33, baseGrid));

	points.push_back(cord31);
	points.push_back(cord32);
	points.push_back(cord33);

	baseGrid->PlaceShip(cord31, 3);
	baseGrid->PlaceShip(cord32, 3);
	baseGrid->PlaceShip(cord33, 3);


	disp->DrawShip(*cord31, disp->GiveGridPt(player));
	disp->DrawShip(*cord32, disp->GiveGridPt(player));
	disp->DrawShip(*cord33, disp->GiveGridPt(player));

	disp->UpdateGrid(false);

	return points;
}
Ship* HumanInterface::SelectShip(Grid *grid, Grid *opponentGrid, vector<class Ship*> ships, Display *disp)
{
	int whichShip = 0;
	bool ifWrong = false;
	do {
		if (ifWrong == true) cout << "Ship is unable to fire..." << endl << "Select different one." << endl;
		cout << "Select ship: [1, 2 or 3]" << endl;
		cin >> whichShip;
		ifWrong = true;
	} while (!check.CheckIfCanSelect(whichShip, grid, opponentGrid, ships));

	system("cls");
	disp->HeaderText();

	return ships.at(whichShip - 1);
}
Point HumanInterface::AskWhereToShoot(Ship* ship, Grid *grid)
{
	Point *whereToShoot = new Point();
	int whichShip = ship->GetWhichShip();

	bool ifWrong = false;

	do {
		if (ifWrong)
		{
			cout << "Wrong coordinates..." << endl;
		}

		cout << "Where do you want to shoot?" << endl;
		cout << "Give the coordinate of the column:\t";
		cin >> whereToShoot->x;
		cout << "Give the coordinate of the row:\t\t";
		cin >> whereToShoot->y;
		whereToShoot->x -= 1;
		whereToShoot->y -= 1;

		ifWrong = true;
	} while (!check.CheckIfCanShoot(whichShip, whereToShoot, grid));

	return *whereToShoot;
}
bool HumanInterface::AskIfDrawRange(Display *disp)
{
	char answer='a';
	do
	{
		system("cls");
		disp->HeaderText();
		cout << "Do you want ship ranges to be drawn on grid? [y/n]" << endl;
		cin >> answer;
	} while (!check.CheckIfProperAnswer(answer));
	system("cls");
	if (answer == 'y' || answer == 'Y') return true;
	else return false;
}
bool HumanInterface::AskIfEnableCheats(Display *disp)
{
	char answer = 'a';
	do
	{
		system("cls");
		disp->HeaderText();
		cout << "Do you want to enable God's Eye? [y/n]" << endl;
		cin >> answer;
		cout << endl;
	} while (!check.CheckIfProperAnswer(answer));
	if (answer == 'y' || answer == 'Y')
	{
		cout << "Cheats will be enabled after 1 round..." << endl;
		Sleep(1000);
		system("cls");
		return true;
	}
	system("cls");
	return false;
}
bool HumanInterface::AskIfShootAgain(Display *disp)
{
	char answer = 'a';
	do
	{
		system("cls");
		disp->HeaderText();
		cout << "Do you want to shoot again? [y/n]" << endl;
		cin >> answer;
		cout << endl;
	} while (!check.CheckIfProperAnswer(answer));
	if (answer == 'y' || answer == 'Y')	return true;
	system("cls");
	return false;
}
