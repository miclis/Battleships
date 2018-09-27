#include <boost/test/unit_test.hpp>

#include "TwoFunnel.h"

BOOST_AUTO_TEST_SUITE(TwoFunnelTests)

BOOST_AUTO_TEST_CASE(Test1) {
	TwoFunnel ship1;

	BOOST_CHECK_EQUAL(ship1.GetHP(), 2);
	BOOST_CHECK_EQUAL(ship1.GetWhichShip(), 2);
}

BOOST_AUTO_TEST_CASE(Test2) {
	TwoFunnel ship1;

	Point point;
	Display display;

	ship1.KillFunnel(&point, &display);

	BOOST_CHECK_EQUAL(ship1.GetHP(), 1);
	BOOST_CHECK_EQUAL(ship1.GetWhichShip(), 2);
}

BOOST_AUTO_TEST_SUITE_END()