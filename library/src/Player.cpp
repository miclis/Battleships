#include "Player.h"

using namespace std;

Player::Player()
{

}
Player::Player(string name)
{

}
Player::~Player()
{

}
void Player::SetName(string name)
{
	this->name = name;
}
void Player::SetNumber(int number)
{
	playerNumber = number;
}
int Player::GetPlayerNumber()
{
	return playerNumber;
}
string Player::GetPlayerName()
{
	return name;
}
bool Player::IsEnd(Grid *targetGridOwn, vector<class Ship*> ships)
{
	int numberOfShips = 3;
	int hasWhereToShoot = 3;
	for (int i = 0; i < 3; i++)
	{
		if (ships.at(i)->GetHP() == 0) numberOfShips--;
		if (!ships.at(i)->CheckIfOpponentsGrid(targetGridOwn, ships.at(i)))
		{
			hasWhereToShoot--;
		}
	}
	if (numberOfShips == 0) return true;
	else if (hasWhereToShoot == 0) return true;
	return false;
}