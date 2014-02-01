/* 
 * File:   Grid.h
 * Author: jappie
 *
 * Created on January 31, 2014, 11:20 AM
 */

#ifndef GRID_H
#define	GRID_H

#include <vector>
#include "Tile.h"
#include "Size.h"
#include "Point.h"
#include "IGridTraveller.h"
#include <iostream>
#include "StrConverter.h"
using namespace std;
namespace isgp {
	/**
	 * A class for easaly handaling a grid as a one dimensional array, with O(1) acces speed,
	 * it also handy for traversel of indivdual rows/columns or all tiles trough function pointers
	 */
	class Grid{
	private:
		vector<Tile*>* _tiles;
		int _tilesLength;
		static const int C_default_h = 20;
		static const int C_default_w = 20;
		/**
		 * size of the grid
		 */
		Size* _size;
		/**
		 * final step in the traversal proces, here the cordinates are known and only the
		 * functionpointer has to be called
		 * */
		void traverse(int x, int y, IGridTraveller* travellar);

		/**
		 * comman code for both contructors
		 */
		void init(int width, int height);
		/**
		 * this function prevents the same calculation showing up in several places
         * @param x
         * @param y
         * @return the index
         */
		int getTileIndex(int x, int y);
	public:

		/** default constructor will use the C_default_size for initiliztion */
		Grid();
		/** initialize the grid to the specified size*/
		Grid(int width, int height);
		/**
		 * destructor
		 */
		~Grid();

		/**
		 * retrieve tile at postiotion
		 */
		Tile* getTileAt(int x, int y);
		/**
		 * shorthand for getTileAt(int x, int y)
		 */
		Tile* getTileAt(Point& p);

		/**
		 * The given function pointer will receive all the tiles and coordinates in the specified row
		 */
		void traverseRow(int y, IGridTraveller* travellar);
		/**
		 * The given function pointer will receive all the tiles and coordinates in the specified collumn
		 */
		void traverseCollumn(int x, IGridTraveller* travellar);
		/**
		 * The given function pointer will receive all the tiles in the grid and the cordiantes of them.
		 */
		void traverseTiles(IGridTraveller* travellar);
        Size* getSize() const;
	};
}


#endif	/* GRID_H */

