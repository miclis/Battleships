#include <iostream>
#include <string>

#include "GameLogic.h"
#include "Display.h"
#include "Grid.h"
//#include "Player.h"
//#include "Human.h"
//#include "HumanInterface.h"
#include <regex>
#include <fstream>


using namespace std;

int main(int argc, char* argv[])
{
	srand(time(0)); //part of random generator
	system("cls");
	system("color 3");

	Display *disp = new Display;
	//Header
	disp->HeaderText();

	regex number("^[1-9][0-9]*$");
	regex file("\\w*.txt");
	regex greedy("^greedy$");
	regex random("random");
	//regex computer("computer");
	regex digit("[1-9]");

	if (!argv[1] || (argc < 2 || argc > 4) || ( !argv[2] && !regex_search(argv[1], file)) || (argv[2] && !regex_search(argv[1], number)) || (argv[2] && !regex_search(argv[2], random) && !regex_search(argv[2], greedy)) || (argv[2] && argv[3] && (!regex_search(argv[3],random) && !regex_search(argv[3], greedy))))
	{
		//Wrong parameters
		disp->WrongParamsText();
		system("cls");
		system("color 7");
		return 1;
	}
	if (!argv[2])
	{
		fstream file;

		file.open(argv[1], ios::in);
		if (file.is_open() == true)
		{
			//cout << "File opened" << endl;
			//system("PAUSE");

			string line;

			// Round
			getline(file, line);
			int round;
			if (line[6] == '1')
			{
				round = line[7] - '0';
				round += 10;
			}
			else round = line[6] - '0';
			
			int maxRound = line[line.length() - 1] - '0';
			if (line[line.length() - 2] == '1')
			{
				maxRound += 10;
			}

			if (round == maxRound)
			{
				disp->GameFinishedText();
				system("cls");
				system("color 7");
				return 1;
			}

			//cout << round << endl;
			//cout << maxRound << endl;

			// Mode
			getline(file, line);
			bool mode = line[line.length() - 1] - '0';

			//cout << mode << endl;

			// Strategy1
			getline(file, line);
			bool strategy1 = line[line.length() - 1] - '0';
			
			//cout << strategy1 << endl;
			
			// Strategy1
			getline(file, line);
			bool strategy2 = line[line.length() - 1] - '0';

			for (int i = 0; i < 2; i++)
			{
				getline(file, line);
			}

			// Grid of Player 1
			Grid baseGridPlayer1 = Grid();
			Grid targetGridPlayer2 = Grid();
			for (int y = 0; y <= 9; y++)
			{
				getline(file, line);

				for (int x = 0; x <= 9; x++)
				{
					Point point = Point(x, y);
					// Place ship on a grid
					if (line[x * 3] == '1') baseGridPlayer1.PlaceShip(&point, 1);
					else if (line[x * 3] == '2') baseGridPlayer1.PlaceShip(&point, 2);
					else if (line[x * 3] == '3') baseGridPlayer1.PlaceShip(&point, 3);

					// Place shoot filds on a grid
					if (line[x * 3 + 1] == 's')
					{
						// On base grid of Player 1
						baseGridPlayer1.Shoot(&point);

						// On target grid of Player 2
						targetGridPlayer2.Shoot(&point);
					}
				}
			}

			for (int i = 0; i < 2; i++)
			{
				getline(file, line);
			}

			// Grid of Player 2
			Grid baseGridPlayer2 = Grid();
			Grid targetGridPlayer1 = Grid();
			for (int y = 0; y <= 9; y++)
			{
				getline(file, line);

				for (int x = 0; x <= 9; x++)
				{
					Point point = Point(x, y);
					// Place ship on a grid
					if (line[x * 3] == '1') baseGridPlayer2.PlaceShip(&point, 1);
					else if (line[x * 3] == '2') baseGridPlayer2.PlaceShip(&point, 2);
					else if (line[x * 3] == '3') baseGridPlayer2.PlaceShip(&point, 3);

					// Place shoot filds on a grid
					if (line[x * 3 + 1] == 's')
					{
						// On base grid of Player 2
						baseGridPlayer2.Shoot(&point);

						// On target grid of Player 1
						targetGridPlayer1.Shoot(&point);
					}
				}
			}

			bool newGame = false;

			GameLogic* game = new GameLogic(newGame, mode, maxRound, strategy1, strategy2, round);
			game->Play(disp, &baseGridPlayer1, &baseGridPlayer2, &targetGridPlayer1, &targetGridPlayer2);
			delete game;

			file.close();
		}
		else
		{
			disp->WrongFileText();
			system("cls");
			system("color 7");
			return 1;
		}
	}

	else
	{
		if (atoi(argv[1]) > 20)
		{
			//Improper round number
			disp->WrongRoundLimitText();
			argv[1] = "20";
		}
		bool mode = 0;
		bool strategy1 = 0;
		bool strategy2 = 0;
		if (argv[3])
		{
			mode = 1;
			if (!strcmp(argv[2], "greedy"))
			{
				strategy2 = 1;
			}
		}
		if (!strcmp(argv[2], "greedy"))
		{
			strategy1 = 1;
		}
		Grid baseGridPlayer1 = Grid();
		Grid targetGridPlayer1 = Grid();
		Grid baseGridPlayer2 = Grid();
		Grid targetGridPlayer2 = Grid();


		bool newGame = true;

		GameLogic* game = new GameLogic(newGame, mode, atoi(argv[1]), strategy1, strategy2, 0);
		game->Play(disp, &baseGridPlayer1, &baseGridPlayer2, &targetGridPlayer1, &targetGridPlayer2);



		
		delete game;
	}

	delete disp;

	system("cls");
	system("color 7");

    return 0;
}