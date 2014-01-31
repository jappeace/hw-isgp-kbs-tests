/* 
 * File:   Grid.h
 * Author: jappie
 *
 * Created on January 31, 2014, 11:20 AM
 */

#ifndef GRID_H
#define	GRID_H

#include <unordered_map>
#include "Tile.h"
#include "Size.h"
#include "Tile.h"
using namespace std;
namespace isgp {
	/**
	 * A class for easaly handaling a grid as a one dimensional array, with O(1) acces speed,
	 * it also handy for traversel of indivdual rows/columns or all tiles trough function pointers
	 */
	class Grid{
	private:
		unordered_map<int, unordered_map<int, Tile>*>* _tiles;
		static Size const * const C_default_size = new Size(20, 20);
		Size* _size;
	public:
		Grid();
		~Grid();
		Grid(int width, int height);
		Tile getTileAt(int x, int y);
		Tile getTileAt(Point p);
	};
}


#endif	/* GRID_H */

