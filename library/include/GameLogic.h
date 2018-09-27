#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Grid.h"
#include "Display.h"

#include <fstream>

using namespace std;

class GameLogic
{
private:
	bool newGame;
	bool mode;	// 0 - Human-Comp	1 - Comp-Comp
	int maxRound;
	bool strategy1;	//0 - Random	1 - Greedy
	bool strategy2; //0 - Random	1 - Greedy
	int round;

	void PlayRound(Display *disp, Player *player1, Player *player2, Grid *baseGridPlayer1, Grid *targetGridPlayer1, Grid *baseGridPlayer2, Grid *targetGridPlayer2, vector<class Ship*> shipsPlayer1, vector<class Ship*> shipsPlayer2, ComputerStrategy* strategy1, ComputerStrategy* strategy2);
public:
	GameLogic(bool newGame, bool mode, int maxRound, bool strategy1, bool strategy2, int round);
	void Play(Display* disp, Grid *baseGridPlayer1, Grid *baseGridPlayer2, Grid *targetGridPlayer1, Grid *targetGridPlayer2);
	bool IsEnd();
};
#endif