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
void gridTestClass::testTile(int x, int y){
	Tile* result = test_grid->getTileAt(x, y);
	CPPUNIT_ASSERT(result != NULL);
	CPPUNIT_ASSERT(result->GetBottom()	== test_grid->getTileAt(x, y-1));
	CPPUNIT_ASSERT(result->GetLeft()	== test_grid->getTileAt(x-1, y));
	CPPUNIT_ASSERT(result->GetTop()		== test_grid->getTileAt(x, y+1));
	CPPUNIT_ASSERT(result->GetRight()	== test_grid->getTileAt(x+1, y));
}
void gridTestClass::setUp() {
	test_grid = new Grid(20, 20);
}

void gridTestClass::tearDown() {
}

void gridTestClass::testGrid() {
	// test uneven grids
	int width = 10;
	int height = 13;
	Grid* g = new Grid(width, height);
	
	CPPUNIT_ASSERT(g->getSize()->GetHeight() == height);
	CPPUNIT_ASSERT(g->getSize()->GetWidth() == width);

	// what to do with a negative
	width = -10;
	height = 13;
	g = new Grid(width, height);
	
	CPPUNIT_ASSERT(g->getSize()->GetHeight() == height);
	CPPUNIT_ASSERT(g->getSize()->GetWidth() == width);
	
	// what to do with 2 negatives
	width = -10;
	height = -13;
	g = new Grid(width, height);
	
	CPPUNIT_ASSERT(g->getSize()->GetHeight() == height);
	CPPUNIT_ASSERT(g->getSize()->GetWidth() == width);
	
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

