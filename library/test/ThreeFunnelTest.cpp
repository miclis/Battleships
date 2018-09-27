#include <boost/test/unit_test.hpp>

#include "ThreeFunnel.h"

BOOST_AUTO_TEST_SUITE(ThreeFunnelTests)

BOOST_AUTO_TEST_CASE(Test1) {
	ThreeFunnel ship1;

	BOOST_CHECK_EQUAL(ship1.GetHP(), 3);
	BOOST_CHECK_EQUAL(ship1.GetWhichShip(), 3);
}

BOOST_AUTO_TEST_CASE(Test2) {
	ThreeFunnel ship1;

	Point point;
	Display display;

	ship1.KillFunnel(&point, &display);

	BOOST_CHECK_EQUAL(ship1.GetHP(), 2);
	BOOST_CHECK_EQUAL(ship1.GetWhichShip(), 3);
}

BOOST_AUTO_TEST_SUITE_END()