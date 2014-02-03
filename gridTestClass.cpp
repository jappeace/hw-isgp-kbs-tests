/*
 * File:   gridTestClass.cpp
 * Author: jappie
 *
 * Created on Feb 1, 2014, 12:43:34 PM
 */

#ifndef TEST_GRID_X
#define TEST_GRID_X 20
#define TEST_GRID_Y 20
#endif
#include "../prototype/Grid.h"
#include "../prototype/Tile.h"
#include "../prototype/IGridTraveller.h"
#include "../prototype/Exceptions.h"
#include "mocks.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace isgp;
namespace tests {

	TEST_CLASS(GridTestClass)
	{
	private:
		Grid* test_grid;
	public:
	void testTile(int x, int y) {
		Tile* result = test_grid->getTileAt(x, y);
		Assert::IsTrue(result != NULL);

		Assert::IsTrue(result->GetBottom() == test_grid->getTileAt(x, y - 1));
		Assert::IsTrue(result->GetLeft() == test_grid->getTileAt(x - 1, y));
		Assert::IsTrue(result->GetTop() == test_grid->getTileAt(x, y + 1));
		Assert::IsTrue(result->GetRight() == test_grid->getTileAt(x + 1, y));

		// the debuger shows somtimes that the pointers are the same, which should not *ever* happen
		// in a grid, these cases test for this behavior
		Assert::IsTrue(result->GetBottom() != result);
		Assert::IsTrue(result->GetLeft() != result);
		Assert::IsTrue(result->GetTop() != result);
		Assert::IsTrue(result->GetRight() != result);

		// making sure the tiles are on proper locations
		Assert::IsTrue(*result->GetPosition() == *new Point(x, y));
		Assert::IsTrue(*result->GetBottom()->GetPosition() == *new Point(x, y - 1));
		Assert::IsTrue(*result->GetLeft()->GetPosition() == *new Point(x - 1, y));
		Assert::IsTrue(*result->GetTop()->GetPosition() == *new Point(x, y + 1));
		Assert::IsTrue(*result->GetRight()->GetPosition() == *new Point(x + 1, y));


	}

	TEST_METHOD_INITIALIZE(SetUp){
		test_grid = new Grid(TEST_GRID_X, TEST_GRID_Y);
	}

	TEST_METHOD(testGrid) {
		// test uneven grids
		unsigned width = 10;
		unsigned height = 13;
		Grid* g = new Grid(width, height);
		Assert::IsTrue(g->getSize()->GetHeight() == height);
		Assert::IsTrue(g->getSize()->GetWidth() == width);

		// what to do with a negative
		width = -10;
		height = 13;

		// negatives degrade to big numbers, so an exception is trhown
		try {
			g = new Grid(width, height);
			Assert::IsTrue("this code should not be reached because of an exception" == false);
		} catch (GridToLargeException arr) {
		}

		// what to do with 2 negatives, this creates an overflow in how many tiles there are
		width = -10;
		height = -13;

		// even bigger numbers... and again an exception is thrown
		try {
			g = new Grid(width, height);
			Assert::IsTrue("this code should not be reached because of an exception" == false);
		} catch (GridToLargeException arr) {
		}

	}

	TEST_METHOD(testGetTileAt_XY) {
		int x = 7;
		int y = 4;
		testTile(x, y);
	}

	TEST_METHOD(testGetTileAtPoint) {
		Point* p = new Point(15, 12);
		testTile(p->GetX(), p->GetY());
	}

	TEST_METHOD(testTraverseCollumn) {
		int x = 5;
		GridTravellerMock* travellar =  new GridTravellerMock();
		test_grid->traverseCollumn(x, travellar);
		Assert::IsTrue(travellar->nrCalled == TEST_GRID_Y);
	}

	TEST_METHOD(testTraverseRow) {
		int y = 8;
		GridTravellerMock* travellar =  new GridTravellerMock();
		test_grid->traverseRow(y, travellar);
		Assert::IsTrue(travellar->nrCalled == TEST_GRID_X);
	}

	TEST_METHOD(testTraverseTiles) {
		GridTravellerMock* travellar =  new GridTravellerMock();
		test_grid->traverseTiles(travellar);
		Assert::IsTrue(travellar->nrCalled == TEST_GRID_X * TEST_GRID_Y);
	}
	}
}
