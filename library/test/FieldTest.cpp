#include <boost/test/unit_test.hpp>

#include "Field.h"

BOOST_AUTO_TEST_SUITE(FieldTests)

BOOST_AUTO_TEST_CASE(GetIsShip) {
	Field field1;
	BOOST_CHECK_EQUAL(field1.GetIsShip(), 0);
}

BOOST_AUTO_TEST_CASE(GetIsShoot) {
	Field field;
	BOOST_CHECK_EQUAL(field.GetIsShoot(), false);
}

BOOST_AUTO_TEST_CASE(SetIsShoot) {
	Field field;
	field.SetIsShoot();

	BOOST_CHECK_EQUAL(field.GetIsShoot(), true);
}

BOOST_AUTO_TEST_CASE(SetIsShip) {
	Field field;
	field.PlaceShip(1);

	BOOST_CHECK_EQUAL(field.GetIsShip(), 1);

	Field field2;
	field.PlaceShip(2);

	BOOST_CHECK_EQUAL(field.GetIsShip(), true);
	BOOST_CHECK_EQUAL(field.GetIsShip(), 2);

	Field field3;
	field.PlaceShip(3);

	BOOST_CHECK_EQUAL(field.GetIsShip(), true);
	BOOST_CHECK_EQUAL(field.GetIsShip(), 3);
}

BOOST_AUTO_TEST_CASE(FieldTest) {
	Field field = Field();

	BOOST_CHECK_EQUAL(field.GetIsShoot(), false);
	BOOST_CHECK_EQUAL(field.GetIsShip(), 0);
	BOOST_CHECK_EQUAL(field.GetInRange1(), false);
	BOOST_CHECK_EQUAL(field.GetInRange2(), false);
	BOOST_CHECK_EQUAL(field.GetInRange3(), false);
}

BOOST_AUTO_TEST_SUITE_END()