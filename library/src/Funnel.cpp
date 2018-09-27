#include "Funnel.h"

using namespace std;

Funnel::Funnel(Point *point)
{
	pt.x = point->x;
	pt.y = point->y;
	alive = true;
}