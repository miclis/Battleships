
#include "GameLogic.h"

using namespace std;

GameLogic::GameLogic(bool newGame, bool mode, int maxRound, bool strategy1, bool strategy2, int round)
{
	this->newGame = newGame;
	this->mode = mode;
	this->maxRound = maxRound;
	this->strategy1 = strategy1;
	this->strategy2 = strategy2;
	this->round = round;
}
void GameLogic::Play(Display *disp, Grid *baseGridPlayer1, Grid *baseGridPlayer2, Grid *targetGridPlayer1, Grid *targetGridPlayer2)
{
	ComputerStrategy *compStrategy1 = new ComputerStrategy(&strategy1);
	ComputerStrategy *compStrategy2 = new ComputerStrategy(&strategy2);

	if (mode == 0)
	{
		//Display windows
		disp->Show(mode);

		HumanInterface *ui = new HumanInterface();
		Human player1(ui);

		vector<Point*> points;
		vector<Point*> pointsOneFunnel;
		vector<Point*> pointsTwoFunnel;
		vector<Point*> pointsThreeFunnel;

		//baseGridPlayer1 = Grid();
		//targetGridPlayer1 = Grid();

		int whichShipToHit;
		vector<class Ship*> opponentShips;

		if (newGame == true)
		{
			points = player1.ArrangeShips(baseGridPlayer1, targetGridPlayer1, disp, 1);
			
			//----------------------------------------------------
			//Creating ships
			//vector<Point*> pointsOneFunnel;
			pointsOneFunnel.push_back(points.at(0));

			//vector<Point*> pointsTwoFunnel;
			pointsTwoFunnel.push_back(points.at(1));
			pointsTwoFunnel.push_back(points.at(2));

			//vector<Point*> pointsThreeFunnel;
			pointsThreeFunnel.push_back(points.at(3));
			pointsThreeFunnel.push_back(points.at(4));
			pointsThreeFunnel.push_back(points.at(5));
		}
		else
		{
			for (int y = 0; y <= 9; y++)
			{
				for (int x = 0; x <= 9; x++)
				{
					Point point = Point(x, y);
					if (baseGridPlayer1->GetWhichShip(&point) == 1)
					{
						pointsOneFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(1));
					}
					else if (baseGridPlayer1->GetWhichShip(&point) == 2)
					{
						pointsTwoFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(1));
					}
					else if (baseGridPlayer1->GetWhichShip(&point) == 3)
					{
						pointsThreeFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(1));
					}

					if (baseGridPlayer1->GetIsShoot(x, y))
					{
						targetGridPlayer2->Shoot(&point);
						baseGridPlayer1->Shoot(&point);

						if (baseGridPlayer1->GetIsShip(x, y))
						{
							whichShipToHit = baseGridPlayer1->GetWhichShip(&point) - 1;
							opponentShips = baseGridPlayer1->ReturnShipInfo();
							opponentShips.at(whichShipToHit)->KillFunnel(&point, disp);

							disp->DrawShoot(point, disp->GiveGridPt(1));
							disp->DrawShip(point, disp->GiveGridPt(4));
						}
						disp->DrawShoot(point, disp->GiveGridPt(4));
					}
				}
			}
		}

		opponentShips.clear();
		
		

		OneFunnel *ship1 = new OneFunnel(pointsOneFunnel);
		TwoFunnel *ship2 = new TwoFunnel(pointsTwoFunnel);
		ThreeFunnel *ship3 = new ThreeFunnel(pointsThreeFunnel);

		points.clear();
		pointsOneFunnel.clear();
		pointsTwoFunnel.clear();
		pointsThreeFunnel.clear();

		vector<class Ship*> shipsPlayer1;
		shipsPlayer1.push_back(ship1);
		shipsPlayer1.push_back(ship2);
		shipsPlayer1.push_back(ship3);

		//Calculating and adding inRange slots to target grid
		shipsPlayer1.at(0)->CalculateRange(targetGridPlayer1, shipsPlayer1.at(0));
		shipsPlayer1.at(1)->CalculateRange(targetGridPlayer1, shipsPlayer1.at(1));
		shipsPlayer1.at(2)->CalculateRange(targetGridPlayer1, shipsPlayer1.at(2));
		
		//Ask if range is needed
		if (ui->AskIfDrawRange(disp))
		{
			disp->DrawRange(targetGridPlayer1, disp->GiveGridPt(3));
			disp->UpdateGrid(mode);
		}
		bool cheat = false;
		//Ask if enable cheats
		if (ui->AskIfEnableCheats(disp)) cheat = true;
	

		//Adding ship informations to grid
		baseGridPlayer1->SetShipsVector(&shipsPlayer1);
		//----------------------------------------------------------



		Computer player2(2);
		//Grid baseGridPlayer2 = Grid();
		//Grid targetGridPlayer2 = Grid();
		if (newGame == true)
		{
			points = player2.ArrangeShips(baseGridPlayer2, targetGridPlayer2, disp, 2);

			//----------------------------------------------------
			//Creating ships
			pointsOneFunnel.push_back(points.at(0));

			pointsTwoFunnel.push_back(points.at(1));
			pointsTwoFunnel.push_back(points.at(2));

			pointsThreeFunnel.push_back(points.at(3));
			pointsThreeFunnel.push_back(points.at(4));
			pointsThreeFunnel.push_back(points.at(5));
		}
		else
		{
			for (int y = 0; y <= 9; y++)
			{
				for (int x = 0; x <= 9; x++)
				{
					Point point = Point(x, y);
					if (baseGridPlayer2->GetWhichShip(&point) == 1)
					{
						pointsOneFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(2));
					}
					else if (baseGridPlayer2->GetWhichShip(&point) == 2)
					{
						pointsTwoFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(2));
					}
					else if (baseGridPlayer2->GetWhichShip(&point) == 3)
					{
						pointsThreeFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(2));
					}

					if (baseGridPlayer2->GetIsShoot(x, y))
					{
						targetGridPlayer1->Shoot(&point);
						baseGridPlayer2->Shoot(&point);

						if (baseGridPlayer2->GetIsShip(x, y))
						{
							whichShipToHit = baseGridPlayer2->GetWhichShip(&point) - 1;
							opponentShips = baseGridPlayer2->ReturnShipInfo();
							opponentShips.at(whichShipToHit)->KillFunnel(&point, disp);

							disp->DrawShoot(point, disp->GiveGridPt(2));
							disp->DrawShip(point, disp->GiveGridPt(3));
						}
						disp->DrawShoot(point, disp->GiveGridPt(3));
					}
				}
			}
		}

		opponentShips.clear();

		ship1 = new OneFunnel(pointsOneFunnel);
		ship2 = new TwoFunnel(pointsTwoFunnel);
		ship3 = new ThreeFunnel(pointsThreeFunnel);

		points.clear();
		pointsOneFunnel.clear();
		pointsTwoFunnel.clear();
		pointsThreeFunnel.clear();

		vector<class Ship*> shipsPlayer2;
		shipsPlayer2.push_back(ship1);
		shipsPlayer2.push_back(ship2);
		shipsPlayer2.push_back(ship3);

		//Calculating and adding inRange slots to target grid
		shipsPlayer2.at(0)->CalculateRange(targetGridPlayer2, shipsPlayer2.at(0));
		shipsPlayer2.at(1)->CalculateRange(targetGridPlayer2, shipsPlayer2.at(1));
		shipsPlayer2.at(2)->CalculateRange(targetGridPlayer2, shipsPlayer2.at(2));

		baseGridPlayer2->SetShipsVector(&shipsPlayer2);
		//----------------------------------------------------------

		//Actual game (rounds)
		do
		{
			round += 1;
			disp->RoundText(round);
			PlayRound(disp, &player1, &player2, baseGridPlayer1, targetGridPlayer1, baseGridPlayer2, targetGridPlayer2, shipsPlayer1, shipsPlayer2, compStrategy1, compStrategy1);
			disp->UpdateGrid(cheat);

		} while ( !(IsEnd() || player1.IsEnd(targetGridPlayer1, shipsPlayer1) || player2.IsEnd(targetGridPlayer2, shipsPlayer2)) );

		// Who won
		bool looser1 = false;
		bool looser2 = false;
		string namePlayer1 = player1.GetPlayerName();
		string namePlayer2 = player2.GetPlayerName();
		int sumHPPlayer1 = 0;
		int sumHPPlayer2 = 0;
		if (player1.IsEnd(targetGridPlayer1, shipsPlayer1)) looser1 = true;
		if (player2.IsEnd(targetGridPlayer2, shipsPlayer2)) looser2 = true;
		if (looser1 == false && looser2 == false)
		{
			for (auto it = shipsPlayer1.begin(); it != shipsPlayer1.end(); ++it)
			{
				sumHPPlayer1 += (*it)->GetHP();
			}

			for (auto it = shipsPlayer2.begin(); it != shipsPlayer2.end(); ++it)
			{
				sumHPPlayer2 += (*it)->GetHP();
			}
		}
		if (sumHPPlayer1 > sumHPPlayer2) looser2 = true;
		else if (sumHPPlayer1 < sumHPPlayer2) looser1 = true;
		disp->WhoWon(namePlayer1, namePlayer2, looser1, looser2);

		//Memory release
		delete ui;
		for (auto it = shipsPlayer1.begin(); it != shipsPlayer1.end(); ++it)
		{
			delete (*it);
		}
		for (auto it = shipsPlayer2.begin(); it != shipsPlayer2.end(); ++it)
		{
			delete (*it);
		}
	}
	else if (mode == 1)
	{
		//Display windows
		disp->Show(mode);

		Computer player1(1, "Computer1");
		//Grid baseGridPlayer1 = Grid();
		//Grid targetGridPlayer1 = Grid();

		vector<Point*> points;
		vector<Point*> pointsOneFunnel;
		vector<Point*> pointsTwoFunnel;
		vector<Point*> pointsThreeFunnel;

		int whichShipToHit;
		vector<class Ship*> opponentShips;

		if (newGame == true)
		{
			points = player1.ArrangeShips(baseGridPlayer1, targetGridPlayer1, disp, 1);

			//----------------------------------------------------
			//Creating ships
			pointsOneFunnel.push_back(points.at(0));

			pointsTwoFunnel.push_back(points.at(1));
			pointsTwoFunnel.push_back(points.at(2));

			pointsThreeFunnel.push_back(points.at(3));
			pointsThreeFunnel.push_back(points.at(4));
			pointsThreeFunnel.push_back(points.at(5));
		}
		else
		{
			for (int y = 0; y <= 9; y++)
			{
				for (int x = 0; x <= 9; x++)
				{
					Point point = Point(x, y);
					if (baseGridPlayer1->GetWhichShip(&point) == 1)
					{
						pointsOneFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(1));
					}
					else if (baseGridPlayer1->GetWhichShip(&point) == 2)
					{
						pointsTwoFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(1));
					}
					else if (baseGridPlayer1->GetWhichShip(&point) == 3)
					{
						pointsThreeFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(1));
					}

					if (baseGridPlayer1->GetIsShoot(x, y))
					{
						targetGridPlayer2->Shoot(&point);
						baseGridPlayer1->Shoot(&point);

						if (baseGridPlayer1->GetIsShip(x, y))
						{
							whichShipToHit = baseGridPlayer1->GetWhichShip(&point) - 1;
							opponentShips = baseGridPlayer1->ReturnShipInfo();
							opponentShips.at(whichShipToHit)->KillFunnel(&point, disp);

							disp->DrawShoot(point, disp->GiveGridPt(1));
							disp->DrawShip(point, disp->GiveGridPt(4));
						}
						disp->DrawShoot(point, disp->GiveGridPt(4));
					}
				}
			}
		}

		OneFunnel *ship1 = new OneFunnel(pointsOneFunnel);
		TwoFunnel *ship2 = new TwoFunnel(pointsTwoFunnel);
		ThreeFunnel *ship3 = new ThreeFunnel(pointsThreeFunnel);

		opponentShips.clear();
		points.clear();
		pointsOneFunnel.clear();
		pointsTwoFunnel.clear();
		pointsThreeFunnel.clear();

		vector<class Ship*> shipsPlayer1;
		shipsPlayer1.push_back(ship1);
		shipsPlayer1.push_back(ship2);
		shipsPlayer1.push_back(ship3);

		//Calculating and adding inRange slots to target grid
		shipsPlayer1.at(0)->CalculateRange(targetGridPlayer1, shipsPlayer1.at(0));
		shipsPlayer1.at(1)->CalculateRange(targetGridPlayer1, shipsPlayer1.at(1));
		shipsPlayer1.at(2)->CalculateRange(targetGridPlayer1, shipsPlayer1.at(2));

		baseGridPlayer1->SetShipsVector(&shipsPlayer1);
		//----------------------------------------------------------



		Computer player2(2, "Computer2");
		//Grid baseGridPlayer2 = Grid();
		//Grid targetGridPlayer2 = Grid();
		
		if (newGame == true)
		{
			points = player2.ArrangeShips(baseGridPlayer2, targetGridPlayer2, disp, 2);

			//----------------------------------------------------
			//Creating ships
			pointsOneFunnel.push_back(points.at(0));

			pointsTwoFunnel.push_back(points.at(1));
			pointsTwoFunnel.push_back(points.at(2));

			pointsThreeFunnel.push_back(points.at(3));
			pointsThreeFunnel.push_back(points.at(4));
			pointsThreeFunnel.push_back(points.at(5));
		}
		else
		{
			Point point;
			for (int y = 0; y <= 9; y++)
			{
				point.y = y;
				for (int x = 0; x <= 9; x++)
				{
					point.x = x;
					if (baseGridPlayer2->GetWhichShip(&point) == 1)
					{
						pointsOneFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(2));
					}
					else if (baseGridPlayer2->GetWhichShip(&point) == 2)
					{
						pointsTwoFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(2));
					}
					else if (baseGridPlayer2->GetWhichShip(&point) == 3)
					{
						pointsThreeFunnel.push_back(&point);

						disp->DrawShip(point, disp->GiveGridPt(2));
					}

					if (baseGridPlayer2->GetIsShoot(x, y))
					{
						targetGridPlayer1->Shoot(&point);
						baseGridPlayer2->Shoot(&point);

						if (baseGridPlayer2->GetIsShip(x, y))
						{
							whichShipToHit = baseGridPlayer2->GetWhichShip(&point) - 1;
							opponentShips = baseGridPlayer2->ReturnShipInfo();
							opponentShips.at(whichShipToHit)->KillFunnel(&point, disp);

							disp->DrawShoot(point, disp->GiveGridPt(2));
							disp->DrawShip(point, disp->GiveGridPt(3));
						}
						disp->DrawShoot(point, disp->GiveGridPt(3));
					}
				}
			}
		}

		disp->UpdateGrid(mode);


		ship1 = new OneFunnel(pointsOneFunnel);
		ship2 = new TwoFunnel(pointsTwoFunnel);
		ship3 = new ThreeFunnel(pointsThreeFunnel);

		opponentShips.clear();
		points.clear();
		pointsOneFunnel.clear();
		pointsTwoFunnel.clear();
		pointsThreeFunnel.clear();

		vector<class Ship*> shipsPlayer2;
		shipsPlayer2.push_back(ship1);
		shipsPlayer2.push_back(ship2);
		shipsPlayer2.push_back(ship3);

		//Calculating and adding inRange slots to target grid
		shipsPlayer2.at(0)->CalculateRange(targetGridPlayer2, shipsPlayer2.at(0));
		shipsPlayer2.at(1)->CalculateRange(targetGridPlayer2, shipsPlayer2.at(1));
		shipsPlayer2.at(2)->CalculateRange(targetGridPlayer2, shipsPlayer2.at(2));

		baseGridPlayer2->SetShipsVector(&shipsPlayer2);
		//----------------------------------------------------------

		system("PAUSE");
		//Actual game (rounds)
		do
		{
			round += 1;
			disp->RoundText(round);
			PlayRound(disp, &player1, &player2, baseGridPlayer1, targetGridPlayer1, baseGridPlayer2, targetGridPlayer2, shipsPlayer1, shipsPlayer2, compStrategy2, compStrategy1);
			disp->UpdateGrid(mode);

			system("PAUSE");

		} while ( !(IsEnd() || player1.IsEnd(targetGridPlayer1, shipsPlayer1) || player2.IsEnd(targetGridPlayer2, shipsPlayer2)) );

		// Who won
		bool looser1 = false;
		bool looser2 = false;
		string namePlayer1 = player1.GetPlayerName();
		string namePlayer2 = player2.GetPlayerName();
		int sumHPPlayer1 = 0;
		int sumHPPlayer2 = 0;
		if (player1.IsEnd(targetGridPlayer1, shipsPlayer1)) looser1 = true;
		if (player2.IsEnd(targetGridPlayer2, shipsPlayer2)) looser2 = true;
		if (looser1 == false && looser2 == false)
		{
			for (auto it = shipsPlayer1.begin(); it != shipsPlayer1.end(); ++it)
			{
				sumHPPlayer1 += (*it)->GetHP();
			}

			for (auto it = shipsPlayer2.begin(); it != shipsPlayer2.end(); ++it)
			{
				sumHPPlayer2 += (*it)->GetHP();
			}
		}
		if (sumHPPlayer1 > sumHPPlayer2) looser2 = true;
		else if (sumHPPlayer1 < sumHPPlayer2) looser1 = true;
		disp->WhoWon(namePlayer1, namePlayer2, looser1, looser2);

		//Memory release
		for (auto it = shipsPlayer1.begin(); it != shipsPlayer1.end(); ++it)
		{
			delete (*it);
		}
		for (auto it = shipsPlayer2.begin(); it != shipsPlayer2.end(); ++it)
		{
			delete (*it);
		}
	}

	//Memory release
	delete compStrategy1;
	delete compStrategy2;
}
void GameLogic::PlayRound(Display *disp, Player *player1, Player *player2, Grid *baseGridPlayer1, Grid *targetGridPlayer1, Grid *baseGridPlayer2, Grid *targetGridPlayer2, vector<class Ship*> shipsPlayer1, vector<class Ship*> shipsPlayer2, ComputerStrategy *strategy1, ComputerStrategy *strategy2)
{
	player1->PlayTurn(disp, player1, baseGridPlayer1, baseGridPlayer2, targetGridPlayer1, targetGridPlayer2, shipsPlayer1, strategy1);

	player2->PlayTurn(disp, player2, baseGridPlayer2, baseGridPlayer1, targetGridPlayer2, targetGridPlayer1, shipsPlayer2, strategy2);

	// Saving current state of the game to file
	fstream file;

	file.open("Battleships.txt", ios::out);
	if (file.is_open() == true)
	{
		string line1;
		string line2;
		string isWaiting1;
		string isWaiting2;

		for (int i = 0; i <= 9; i++)
		{
			
			for (int j = 0; j <= 9; j++)
			{
				Point point = Point(j, i);

				// Base grid of Player 1
				// Ships
				if (baseGridPlayer1->GetWhichShip(&point) == 0)
				{
					line1.append("0");
				}
				else if (baseGridPlayer1->GetWhichShip(&point) == 1)
				{
					line1.append("1");
				}
				else if (baseGridPlayer1->GetWhichShip(&point) == 2)
				{
					line1.append("2");
				}
				else if (baseGridPlayer1->GetWhichShip(&point) == 3)
				{
					line1.append("3");
				}
				// Shoot
				if (baseGridPlayer1->GetIsShoot(point.x, point.y) == 0)
				{
					line1.append("n");	// n - not shoot
				}
				else
				{
					line1.append("s");	// s - shoot
				}
				line1.append(" ");

				// Base grid of Player 2
				// Ships
				if (baseGridPlayer2->GetWhichShip(&point) == 0)
				{
					line2.append("0");
				}
				else if (baseGridPlayer2->GetWhichShip(&point) == 1)
				{
					line2.append("1");
				}
				else if (baseGridPlayer2->GetWhichShip(&point) == 2)
				{
					line2.append("2");
				}
				else if (baseGridPlayer2->GetWhichShip(&point) == 3)
				{
					line2.append("3");
				}
				// Shoot
				if (baseGridPlayer2->GetIsShoot(point.x, point.y) == 0)
				{
					line2.append("n");	// n - not shoot
				}
				else
				{
					line2.append("s");	// s - shoot
				}
				line2.append(" ");
			}
			line1.append("\n");
			line2.append("\n");
		}

		file << "Round " << round << " of " << maxRound << endl;
		file << "Mode " << mode << endl;
		file << "Strategy1 " << this->strategy1 << endl;
		file << "Strategy2 " << this->strategy2 << endl << endl;

		file << "Player 1" << endl;
		file.write(&line1[0], line1.length());
		/*for (auto it = shipsPlayer1.begin(); it != shipsPlayer1.end(); ++it)
		{
			if ((*it)->GetIsWaiting() && (*it)->GetWhichShip() == 2)
			{
				file << "Two-Funnel ship is waiting" << endl;
			}
			else if ((*it)->GetIsWaiting() && (*it)->GetWhichShip() == 3)
			{
				file << "Three-Funnel ship is waiting" << endl;
			}
		}*/
		
		file << "\nPlayer 2" << endl;
		file.write(&line2[0], line2.length());
		/*for (auto it = shipsPlayer2.begin(); it != shipsPlayer2.end(); ++it)
		{
			if ((*it)->GetIsWaiting() && (*it)->GetWhichShip() == 2)
			{
				file << "Two-Funnel ship is waiting" << endl;
			}
			else if ((*it)->GetIsWaiting() && (*it)->GetWhichShip() == 3)
			{
				file << "Three-Funnel ship is waiting" << endl;
			}
		}*/

		file.close();
	}
}
bool GameLogic::IsEnd()
{
	if (round == maxRound)
	{
		return 1;
	}
	else return 0;
}
