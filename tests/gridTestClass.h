/*
 * File:   gridTestClass.h
 * Author: jappie
 *
 * Created on Feb 1, 2014, 12:43:33 PM
 */

#ifndef GRIDTESTCLASS_H
#define	GRIDTESTCLASS_H
#ifndef TEST_GRID_X
#define TEST_GRID_X 20
#define TEST_GRID_Y 20
#endif
#include <cppunit/extensions/HelperMacros.h>
#include "../Grid.h"
#include "../Tile.h"
#include "../IGridTraveller.h"
#include "../Exceptions.h"
#include "mocks.h"
using namespace isgp;
namespace isgp_test{
	class gridTestClass : public CPPUNIT_NS::TestFixture {

		CPPUNIT_TEST_SUITE(gridTestClass);

		CPPUNIT_TEST(testGrid);
		CPPUNIT_TEST(testGetTileAt_XY);
		CPPUNIT_TEST(testGetTileAtPoint);
		CPPUNIT_TEST(testTraverseCollumn);
		CPPUNIT_TEST(testTraverseRow);
		CPPUNIT_TEST(testTraverseTiles);

		CPPUNIT_TEST_SUITE_END();

	public:
		gridTestClass();
		virtual ~gridTestClass();
		void setUp();
		void tearDown();

	private:
		Grid* test_grid;
		void testGrid();
		void testGetTileAt_XY();
		void testGetTileAtPoint();
		void testTraverseCollumn();
		void testTraverseRow();
		void testTraverseTiles();

		void testTile(int x, int y);

	};
}
#endif	/* GRIDTESTCLASS_H */
