/*
 * File:   gridTestClass.cpp
 * Author: jappie
 *
 * Created on Feb 1, 2014, 12:43:34 PM
 */

#include "gridTestClass.h"



CPPUNIT_TEST_SUITE_REGISTRATION(gridTestClass);

gridTestClass::gridTestClass() {
}

gridTestClass::~gridTestClass() {
}

void gridTestClass::setUp() {
}

void gridTestClass::tearDown() {
}

void gridTestClass::testGrid() {
	int width;
	int height;
	isgp::Grid grid(width, height);
	if (true /*check result*/) {
		CPPUNIT_ASSERT(false);
	}
}

void gridTestClass::testGetTileAt() {
	int x;
	int y;
	isgp::Grid grid;
	Tile* result = grid.getTileAt(x, y);
	if (true /*check result*/) {
		CPPUNIT_ASSERT(false);
	}
}

void gridTestClass::testGetTileAt2() {
	Point* p;
	isgp::Grid grid;
	Tile* result = grid.getTileAt(p);
	if (true /*check result*/) {
		CPPUNIT_ASSERT(false);
	}
}

void gridTestClass::testTraverseCollumn() {
	int x;
	IGridTraveller* travellar;
	isgp::Grid grid;
	grid.traverseCollumn(x, travellar);
	if (true /*check result*/) {
		CPPUNIT_ASSERT(false);
	}
}

void gridTestClass::testTraverseRow() {
	int y;
	IGridTraveller* travellar;
	isgp::Grid grid;
	grid.traverseRow(y, travellar);
	if (true /*check result*/) {
		CPPUNIT_ASSERT(false);
	}
}

void gridTestClass::testTraverseTiles() {
	IGridTraveller* travellar;
	isgp::Grid grid;
	grid.traverseTiles(travellar);
	if (true /*check result*/) {
		CPPUNIT_ASSERT(false);
	}
}

