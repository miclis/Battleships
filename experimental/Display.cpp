#include "Display.h"

Display::Display()
{
	//Setting number colors
	unsigned char purple[] = { 255,0,255 };
	//Assigning window size
	baseGridOwn.assign(400, 400, 1, 3, 0);
	//baseGridOwn.assign("navy.bmp");
	//Drawing grid
	for (int y = 1;y < baseGridOwn.width();++y)
	{
		for (int x = 1;x < baseGridOwn.height();++x)
		{
			if (x % 40 == 0)
			{
				baseGridOwn(x, y, 0, 0) = 0;
				baseGridOwn(x, y, 0, 1) = 0;
				baseGridOwn(x, y, 0, 2) = 255;
			}
			if (y % 40 == 0)
			{
				baseGridOwn(x, y, 0, 0) = 0;
				baseGridOwn(x, y, 0, 1) = 0;
				baseGridOwn(x, y, 0, 2) = 255;
			}
		}
	}
	//Drawing numbers
	baseGridOwn.draw_text(0, (40 * 0) + 13, "1", purple);
	baseGridOwn.draw_text(0, (40 * 1) + 13, "2", purple);
	baseGridOwn.draw_text(0, (40 * 2) + 13, "3", purple);
	baseGridOwn.draw_text(0, (40 * 3) + 13, "4", purple);
	baseGridOwn.draw_text(0, (40 * 4) + 13, "5", purple);
	baseGridOwn.draw_text(0, (40 * 5) + 13, "6", purple);
	baseGridOwn.draw_text(0, (40 * 6) + 13, "7", purple);
	baseGridOwn.draw_text(0, (40 * 7) + 13, "8", purple);
	baseGridOwn.draw_text(0, (40 * 8) + 13, "9", purple);
	baseGridOwn.draw_text(0, (40 * 9) + 13, "10", purple);

	baseGridOwn.draw_text((40 * 0) + 18, 0, "1", purple);
	baseGridOwn.draw_text((40 * 1) + 18, 0, "2", purple);
	baseGridOwn.draw_text((40 * 2) + 18, 0, "3", purple);
	baseGridOwn.draw_text((40 * 3) + 18, 0, "4", purple);
	baseGridOwn.draw_text((40 * 4) + 18, 0, "5", purple);
	baseGridOwn.draw_text((40 * 5) + 18, 0, "6", purple);
	baseGridOwn.draw_text((40 * 6) + 18, 0, "7", purple);
	baseGridOwn.draw_text((40 * 7) + 18, 0, "8", purple);
	baseGridOwn.draw_text((40 * 8) + 18, 0, "9", purple);
	baseGridOwn.draw_text((40 * 9) + 18, 0, "10", purple);

	targetGridOwn.assign(400, 400, 1, 3, 0);
	for (int y = 1;y < targetGridOwn.width();++y)
	{
		for (int x = 1;x < targetGridOwn.height();++x)
		{
			if (x % 40 == 0)
			{
				targetGridOwn(x, y, 0, 0) = 200;
				targetGridOwn(x, y, 0, 1) = 0;
				targetGridOwn(x, y, 0, 2) = 0;
			}
			if (y % 40 == 0)
			{
				targetGridOwn(x, y, 0, 0) = 200;
				targetGridOwn(x, y, 0, 1) = 0;
				targetGridOwn(x, y, 0, 2) = 0;
			}
		}
	}
	targetGridOwn.draw_text(0, (40 * 0) + 13, "1", purple);
	targetGridOwn.draw_text(0, (40 * 1) + 13, "2", purple);
	targetGridOwn.draw_text(0, (40 * 2) + 13, "3", purple);
	targetGridOwn.draw_text(0, (40 * 3) + 13, "4", purple);
	targetGridOwn.draw_text(0, (40 * 4) + 13, "5", purple);
	targetGridOwn.draw_text(0, (40 * 5) + 13, "6", purple);
	targetGridOwn.draw_text(0, (40 * 6) + 13, "7", purple);
	targetGridOwn.draw_text(0, (40 * 7) + 13, "8", purple);
	targetGridOwn.draw_text(0, (40 * 8) + 13, "9", purple);
	targetGridOwn.draw_text(0, (40 * 9) + 13, "10", purple);

	targetGridOwn.draw_text((40 * 0) + 18, 0, "1", purple);
	targetGridOwn.draw_text((40 * 1) + 18, 0, "2", purple);
	targetGridOwn.draw_text((40 * 2) + 18, 0, "3", purple);
	targetGridOwn.draw_text((40 * 3) + 18, 0, "4", purple);
	targetGridOwn.draw_text((40 * 4) + 18, 0, "5", purple);
	targetGridOwn.draw_text((40 * 5) + 18, 0, "6", purple);
	targetGridOwn.draw_text((40 * 6) + 18, 0, "7", purple);
	targetGridOwn.draw_text((40 * 7) + 18, 0, "8", purple);
	targetGridOwn.draw_text((40 * 8) + 18, 0, "9", purple);
	targetGridOwn.draw_text((40 * 9) + 18, 0, "10", purple);

	baseGridOpponent.assign(400, 400, 1, 3, 0);
	for (int y = 1;y < baseGridOpponent.width();++y)
	{
		for (int x = 1;x < baseGridOpponent.height();++x)
		{
			if (x % 40 == 0)
			{
				baseGridOpponent(x, y, 0, 0) = 0;
				baseGridOpponent(x, y, 0, 1) = 0;
				baseGridOpponent(x, y, 0, 2) = 255;
			}
			if (y % 40 == 0)
			{
				baseGridOpponent(x, y, 0, 0) = 0;
				baseGridOpponent(x, y, 0, 1) = 0;
				baseGridOpponent(x, y, 0, 2) = 255;
			}
		}
	}
	baseGridOpponent.draw_text(0, (40 * 0) + 13, "1", purple);
	baseGridOpponent.draw_text(0, (40 * 1) + 13, "2", purple);
	baseGridOpponent.draw_text(0, (40 * 2) + 13, "3", purple);
	baseGridOpponent.draw_text(0, (40 * 3) + 13, "4", purple);
	baseGridOpponent.draw_text(0, (40 * 4) + 13, "5", purple);
	baseGridOpponent.draw_text(0, (40 * 5) + 13, "6", purple);
	baseGridOpponent.draw_text(0, (40 * 6) + 13, "7", purple);
	baseGridOpponent.draw_text(0, (40 * 7) + 13, "8", purple);
	baseGridOpponent.draw_text(0, (40 * 8) + 13, "9", purple);
	baseGridOpponent.draw_text(0, (40 * 9) + 13, "10", purple);

	baseGridOpponent.draw_text((40 * 0) + 18, 0, "1", purple);
	baseGridOpponent.draw_text((40 * 1) + 18, 0, "2", purple);
	baseGridOpponent.draw_text((40 * 2) + 18, 0, "3", purple);
	baseGridOpponent.draw_text((40 * 3) + 18, 0, "4", purple);
	baseGridOpponent.draw_text((40 * 4) + 18, 0, "5", purple);
	baseGridOpponent.draw_text((40 * 5) + 18, 0, "6", purple);
	baseGridOpponent.draw_text((40 * 6) + 18, 0, "7", purple);
	baseGridOpponent.draw_text((40 * 7) + 18, 0, "8", purple);
	baseGridOpponent.draw_text((40 * 8) + 18, 0, "9", purple);
	baseGridOpponent.draw_text((40 * 9) + 18, 0, "10", purple);

	targetGridOpponent.assign(400, 400, 1, 3, 0);
	for (int y = 1;y < targetGridOpponent.width();++y)
	{
		for (int x = 1;x < targetGridOpponent.height();++x)
		{
			if (x % 40 == 0)
			{
				targetGridOpponent(x, y, 0, 0) = 200;
				targetGridOpponent(x, y, 0, 1) = 0;
				targetGridOpponent(x, y, 0, 2) = 0;
			}
			if (y % 40 == 0)
			{
				targetGridOpponent(x, y, 0, 0) = 200;
				targetGridOpponent(x, y, 0, 1) = 0;
				targetGridOpponent(x, y, 0, 2) = 0;
			}
		}
	}
	targetGridOpponent.draw_text(0, (40 * 0) + 13, "1", purple);
	targetGridOpponent.draw_text(0, (40 * 1) + 13, "2", purple);
	targetGridOpponent.draw_text(0, (40 * 2) + 13, "3", purple);
	targetGridOpponent.draw_text(0, (40 * 3) + 13, "4", purple);
	targetGridOpponent.draw_text(0, (40 * 4) + 13, "5", purple);
	targetGridOpponent.draw_text(0, (40 * 5) + 13, "6", purple);
	targetGridOpponent.draw_text(0, (40 * 6) + 13, "7", purple);
	targetGridOpponent.draw_text(0, (40 * 7) + 13, "8", purple);
	targetGridOpponent.draw_text(0, (40 * 8) + 13, "9", purple);
	targetGridOpponent.draw_text(0, (40 * 9) + 13, "10", purple);

	targetGridOpponent.draw_text((40 * 0) + 18, 0, "1", purple);
	targetGridOpponent.draw_text((40 * 1) + 18, 0, "2", purple);
	targetGridOpponent.draw_text((40 * 2) + 18, 0, "3", purple);
	targetGridOpponent.draw_text((40 * 3) + 18, 0, "4", purple);
	targetGridOpponent.draw_text((40 * 4) + 18, 0, "5", purple);
	targetGridOpponent.draw_text((40 * 5) + 18, 0, "6", purple);
	targetGridOpponent.draw_text((40 * 6) + 18, 0, "7", purple);
	targetGridOpponent.draw_text((40 * 7) + 18, 0, "8", purple);
	targetGridOpponent.draw_text((40 * 8) + 18, 0, "9", purple);
	targetGridOpponent.draw_text((40 * 9) + 18, 0, "10", purple);
}
CImg<float>* Display::GiveGridPt(int grid)
{
	if (grid == 1)
	{
		return &baseGridOwn;
	}
	else if (grid == 2)
	{
		return &baseGridOpponent;
	}
	else if (grid == 3)
	{
		return &targetGridOwn;
	}
	else if (grid == 4)
	{
		return &targetGridOpponent;
	}
}
void Display::Show(bool mode)
{

	if (mode == 0)
	{
		bgown.assign(baseGridOwn, "Player1 Ships", 0, false, false);
		tgown.assign(targetGridOwn, "Player1 Target Net", 0, false, false);
	}
	else
	{
		bgown.assign(baseGridOwn, "Player1 Ships", 0, false, false);
		bgopp.assign(baseGridOpponent, "Player2 Ships", 0, false, false);
		tgown.assign(targetGridOwn, "Player1 Target Net", 0, false, false);
		tgopp.assign(targetGridOpponent, "Player2 Target Net", 0, false, false);
	}
}
void Display::DrawShoot(Point cord, CImg<float>* grid)
{
	for (int x = cord.x * 39 + cord.x + 1; x <= 39 * (cord.x + 1) + cord.x; ++x)
	{
		for (int y = cord.y * 39 + cord.y + 1; y <= 39 * (cord.y + 1) + cord.y; ++y)
		{
			if (grid->atXY(x, y) == 0)
			{
				grid->atXY(x, y, 0, 0) += 220;

			}
			//Option if range is shown
			else if (grid->atXY(x, y) >= 20 && grid->atXY(x, y) <= 40)
			{
				grid->atXY(x, y, 0, 0) = 220;
				grid->atXY(x, y, 0, 1) = 0;
				grid->atXY(x, y, 0, 2) = 0;
			}
		}
	}
}
void Display::DrawShip(Point cord, CImg<float>* grid)
{
	CImg<float> funnel("funnel.bmp");
	grid->draw_image(10, 10, funnel);
	//for(int x =)
	/*for (int x = cord.x * 39 + cord.x + 1 + 9; x <= 39 * (cord.x + 1) + cord.x - 9; ++x)
	{
		for (int y = cord.y * 39 + cord.y + 1 + 9; y <= 39 * (cord.y + 1) + cord.y - 9; ++y)
		{
			grid->atXY(x, y, 0, 1) += 180;
		}
	}*/
}
void Display::DrawRange(Grid* rangeGrid, CImg<float>* grid)
{
	for (int m = 0;m < 10;++m)
	{
		for (int n = 0;n < 10;++n)
		{
			for (int x = m * 39 + m + 1; x <= 39 * (m + 1) + m; ++x)
			{
				for (int y = n * 39 + n + 1; y <= 39 * (n + 1) + n; ++y)
				{
					if (rangeGrid->GetInRange3(m,n) && grid->atXY(x,y,0,2) !=255)
					{
						grid->atXY(x, y, 0, 0) = 20;
						grid->atXY(x, y, 0, 1) = 20;
						grid->atXY(x, y, 0, 2) = 20;
					}
					if (rangeGrid->GetInRange2(m, n) && grid->atXY(x, y, 0, 2) != 255)
					{
						grid->atXY(x, y, 0, 0) = 30;
						grid->atXY(x, y, 0, 1) = 30;
						grid->atXY(x, y, 0, 2) = 30;
					}
					if (rangeGrid->GetInRange1(m, n) && grid->atXY(x, y, 0, 2) != 255)
					{
						grid->atXY(x, y, 0, 0) = 40;
						grid->atXY(x, y, 0, 1) = 40;
						grid->atXY(x, y, 0, 2) = 40;
					}
				}
			}
		}
	}
}

void Display::UpdateGrid(bool mode)
{
	if (mode == false)
	{
		bgown = baseGridOwn;
		tgown = targetGridOwn;
	}
	else
	{
		bgown = baseGridOwn;
		bgopp = baseGridOpponent;
		tgown = targetGridOwn;
		tgopp = targetGridOpponent;
	}
}

void Display::RoundText(int round)
{
	system("cls");
	HeaderText();
	cout << "Round " << round << endl << endl;
}
void Display::WhoWon(string namePlayer1, string namePlayer2, bool looser1, bool looser2)
{
	system("cls");
	HeaderText();
	if (looser1 == false && looser2 == false)
	{
		cout << "No one won!" << endl;
	}
	else if (looser1 == false && looser2 == true)
	{
		cout << namePlayer1 << " won!" << endl;
	}
	else if (looser1 == true && looser2 == false)
	{
		cout << namePlayer2 << " won!" << endl;
	}
	else cout << "Both players won!" << endl;
	system("PAUSE");
}
void Display::HeaderText()
{
	cout << "BATTLESHIPS" << endl;
	cout << "=================================================================================================================" << endl << endl;
}
void Display::WrongParamsText()
{
	cout << "Wrong arguments!\n\nPlease provide following arguments:" << endl;
	cout << "1. Maximum number of rounds (max 20) \n2. Computer strategy (random or greedy) \n3. (Optional) Game mode (if you want the game to be played computer vs computer add strategy type again as third argument" << endl << endl;
	cout << "eg. of invocation:\nBattleships 17 greedy random" << endl << endl;
	system("Pause");
}
void Display::WrongRoundLimitText()
{
	cout << "Too big rounds number... Setting it to max (20)." << endl << endl;
}
void Display::HitText()
{
	cout << "HIT!" << endl;
}
void Display::SunkText()
{
	cout << "Ship has been sunk!" << endl;
	system("PAUSE");
}
void Display::MissText()
{
	cout << "Miss..." << endl;
	Sleep(500);
}