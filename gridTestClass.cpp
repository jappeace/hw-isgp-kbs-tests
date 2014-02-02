/*
 * File:   gridTestClass.cpp
 * Author: jappie
 *
 * Created on Feb 1, 2014, 12:43:34 PM
 */

#include "gridTestClass.h"
using namespace isgp;
namespace isgp_test {
	CPPUNIT_TEST_SUITE_REGISTRATION(gridTestClass);

	gridTestClass::gridTestClass() {
	}

	gridTestClass::~gridTestClass() {
	}

	void gridTestClass::testTile(int x, int y) {
		Tile* result = test_grid->getTileAt(x, y);
		CPPUNIT_ASSERT(result != NULL);


		CPPUNIT_ASSERT(result->GetBottom() == test_grid->getTileAt(x, y - 1));
		CPPUNIT_ASSERT(result->GetLeft() == test_grid->getTileAt(x - 1, y));
		CPPUNIT_ASSERT(result->GetTop() == test_grid->getTileAt(x, y + 1));
		CPPUNIT_ASSERT(result->GetRight() == test_grid->getTileAt(x + 1, y));

		// the debuger shows somtimes that the pointers are the same, which should not *ever* happen
		// in a grid, these cases test for this behavior
		CPPUNIT_ASSERT(result->GetBottom() != result);
		CPPUNIT_ASSERT(result->GetLeft() != result);
		CPPUNIT_ASSERT(result->GetTop() != result);
		CPPUNIT_ASSERT(result->GetRight() != result);

		// making sure the tiles are on proper locations
		CPPUNIT_ASSERT(*result->GetPosition() == *new Point(x, y));
		CPPUNIT_ASSERT(*result->GetBottom()->GetPosition() == *new Point(x, y - 1));
		CPPUNIT_ASSERT(*result->GetLeft()->GetPosition() == *new Point(x - 1, y));
		CPPUNIT_ASSERT(*result->GetTop()->GetPosition() == *new Point(x, y + 1));
		CPPUNIT_ASSERT(*result->GetRight()->GetPosition() == *new Point(x + 1, y));


	}

	void gridTestClass::setUp() {
		test_grid = new Grid(TEST_GRID_X, TEST_GRID_Y);
	}

	void gridTestClass::tearDown() {
	}

	void gridTestClass::testGrid() {
		// test uneven grids
		unsigned width = 10;
		unsigned height = 13;
		Grid* g = new Grid(width, height);
		CPPUNIT_ASSERT(g->getSize()->GetHeight() == height);
		CPPUNIT_ASSERT(g->getSize()->GetWidth() == width);

		// what to do with a negative
		width = -10;
		height = 13;

		// negatives degrade to big numbers, so an exception is trhown
		try {
			g = new Grid(width, height);
			CPPUNIT_ASSERT("this code should not be reached because of an exception" == false);
		} catch (GridToLargeException arr) {
		}

		// what to do with 2 negatives, this creates an overflow in how many tiles there are
		width = -10;
		height = -13;

		// even bigger numbers... and again an exception is thrown
		try {
			g = new Grid(width, height);
			CPPUNIT_ASSERT("this code should not be reached because of an exception" == false);
		} catch (GridToLargeException arr) {
		}

	}

	void gridTestClass::testGetTileAt_XY() {
		int x = 7;
		int y = 4;
		testTile(x, y);
	}

	void gridTestClass::testGetTileAtPoint() {
		Point* p = new Point(15, 12);
		testTile(p->GetX(), p->GetY());
	}

	void gridTestClass::testTraverseCollumn() {
		int x = 5;
		GridTravellerMock* travellar =  new GridTravellerMock();
		test_grid->traverseCollumn(x, travellar);
		CPPUNIT_ASSERT(travellar->nrCalled == TEST_GRID_Y);
	}

	void gridTestClass::testTraverseRow() {
		int y = 8;
		GridTravellerMock* travellar =  new GridTravellerMock();
		test_grid->traverseRow(y, travellar);
		CPPUNIT_ASSERT(travellar->nrCalled == TEST_GRID_X);
	}

	void gridTestClass::testTraverseTiles() {
		GridTravellerMock* travellar =  new GridTravellerMock();
		test_grid->traverseTiles(travellar);
		CPPUNIT_ASSERT(travellar->nrCalled == TEST_GRID_X * TEST_GRID_Y);
	}
}