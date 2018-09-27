#include <boost/test/unit_test.hpp>

#include "Grid.h"

BOOST_AUTO_TEST_SUITE(GridTests)

BOOST_AUTO_TEST_CASE(Shoot) {
	Grid grid = Grid();

	Point point;

	BOOST_CHECK_EQUAL(grid.GetIsShoot(point.x, point.y), false);


	grid.Shoot(&point);

	BOOST_CHECK_EQUAL(grid.GetIsShoot(point.x,point.y), true);
}

BOOST_AUTO_TEST_CASE(PlaceShip) {
	Grid grid = Grid();

	Point point;

	BOOST_CHECK_EQUAL(grid.GetIsShip(point.x, point.y), false);
	BOOST_CHECK_EQUAL(grid.GetWhichShip(&point), 0);

	grid.PlaceShip(&point, 1);

	BOOST_CHECK_EQUAL(grid.GetIsShip(point.x, point.y), true);
	BOOST_CHECK_EQUAL(grid.GetWhichShip(&point), 1);
}

BOOST_AUTO_TEST_CASE(InRange) {
	Grid grid = Grid();

	Point point;

	BOOST_CHECK_EQUAL(grid.GetInRange1(point.x, point.y), false);
	BOOST_CHECK_EQUAL(grid.GetInRange2(point.x, point.y), false);
	BOOST_CHECK_EQUAL(grid.GetInRange3(point.x, point.y), false);

	grid.SetInRange(&point, 1);

	BOOST_CHECK_EQUAL(grid.GetInRange1(point.x, point.y), true);
	BOOST_CHECK_EQUAL(grid.GetInRange2(point.x, point.y), false);
	BOOST_CHECK_EQUAL(grid.GetInRange3(point.x, point.y), false);

	grid.SetInRange(&point, 2);

	BOOST_CHECK_EQUAL(grid.GetInRange1(point.x, point.y), true);
	BOOST_CHECK_EQUAL(grid.GetInRange2(point.x, point.y), true);
	BOOST_CHECK_EQUAL(grid.GetInRange3(point.x, point.y), false);

	grid.SetInRange(&point, 3);

	BOOST_CHECK_EQUAL(grid.GetInRange1(point.x, point.y), true);
	BOOST_CHECK_EQUAL(grid.GetInRange2(point.x, point.y), true);
	BOOST_CHECK_EQUAL(grid.GetInRange3(point.x, point.y), true);
}

BOOST_AUTO_TEST_SUITE_END()