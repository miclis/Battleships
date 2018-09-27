#ifndef POINT_H_
#define POINT_H_

struct Point
{
	Point();
	Point(int x, int y);
	int x;
	int y;
	bool operator==(const Point& b);
};
#endif