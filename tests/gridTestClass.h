/*
 * File:   gridTestClass.h
 * Author: jappie
 *
 * Created on Feb 1, 2014, 12:43:33 PM
 */

#ifndef GRIDTESTCLASS_H
#define	GRIDTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "Grid.h"
#include "Tile.h"
class gridTestClass : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(gridTestClass);

	CPPUNIT_TEST(testGrid);
	CPPUNIT_TEST(testGetTileAt);
	CPPUNIT_TEST(testGetTileAt2);
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
	void testGrid();
	void testGetTileAt();
	void testGetTileAt2();
	void testTraverseCollumn();
	void testTraverseRow();
	void testTraverseTiles();

};

#endif	/* GRIDTESTCLASS_H */

