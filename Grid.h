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
#include "Point.h"
#include "IGridTraveller.h"
using namespace std;
namespace isgp {
	/**
	 * A class for easaly handaling a grid as a one dimensional array, with O(1) acces speed,
	 * it also handy for traversel of indivdual rows/columns or all tiles trough function pointers
	 */
	class Grid{
	private:
		unordered_map<int, unordered_map<int, Tile*>>* _tiles;
		Size const * const C_default_size = new Size(20, 20);
		/**
		 * size of the grid
		 */
		Size* _size;
		/**
		 * final step in the traversal proces, here the cordinates are known and only the
		 * functionpointer has to be called
		 * */
		void traverse(int x, int y, IGridTraveller& travellar);

		/**
		 * comman code for both contructors
		 */
		void init(int width, int height);
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
		void traverseRow(int y, IGridTraveller& travellar);
		/**
		 * The given function pointer will receive all the tiles and coordinates in the specified collumn
		 */
		void traverseCollumn(int x, IGridTraveller& travellar);
		/**
		 * The given function pointer will receive all the tiles in the grid and the cordiantes of them.
		 */
		void traverseTiles(IGridTraveller& travellar);
	};
}


#endif	/* GRID_H */

