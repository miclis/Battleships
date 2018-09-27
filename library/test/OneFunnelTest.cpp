#include <boost/test/unit_test.hpp>

#include "OneFunnel.h"

BOOST_AUTO_TEST_SUITE(OneFunnelTests)

BOOST_AUTO_TEST_CASE(Test1) {
	OneFunnel ship1;

	BOOST_CHECK_EQUAL(ship1.GetHP(), 1);
	BOOST_CHECK_EQUAL(ship1.GetWhichShip(), 1);
}

BOOST_AUTO_TEST_CASE(Test2) {
	OneFunnel ship1;

	Point point;
	Display display;

	ship1.KillFunnel(&point, &display);

	BOOST_CHECK_EQUAL(ship1.GetHP(), 0);
	BOOST_CHECK_EQUAL(ship1.GetWhichShip(), 1);
}

BOOST_AUTO_TEST_SUITE_END()