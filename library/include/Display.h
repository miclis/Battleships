#ifndef DISPLAY_H_
#define DISPLAY_H_
	
#include "CImg.h"
#include "Point.h"
#include "Grid.h"
#include <iostream>
#include <string>

using namespace cimg_library;
using namespace std;

class Display
{
private:
	CImg<float> baseGridOwn;
	CImg<float> baseGridOpponent;
	CImg<float> targetGridOwn;
	CImg<float> targetGridOpponent;
	CImgDisplay bgown;
	CImgDisplay bgopp;
	CImgDisplay tgown;
	CImgDisplay tgopp;

public:
	Display();
	void Show(bool mode);
	void UpdateGrid(bool mode = true);
	void DrawShoot(Point cord,CImg<float>* grid);
	void DrawShip(Point cord,CImg<float>* grid);
	void DrawRange(Grid* rangeGrid, CImg<float>* grid);
	CImg<float>* GiveGridPt(int grid);
	void RoundText(int round);
	void WhoWon(string namePlayer1, string namePlayer2, bool looser1, bool looser2);
	void HeaderText();
	void WrongParamsText();
	void WrongRoundLimitText();
	void WrongFileText();
	void GameFinishedText();
	void HitText();
	void SunkText();
	void MissText();	///Hidden option - can be enabled if needed (uncomment in Computer::Shoot and Human:Shoot)
};
#endif