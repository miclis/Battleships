#include "Point.h"
#include <regex>

using namespace std;

regex number("[0-9]");

Point::Point()
{
	x = 0;
	y = 0;
}
Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}
bool Point::operator==(const Point& b)
{
	if (this->x == b.x && this->y == b.y) return true;
	else return false;
}