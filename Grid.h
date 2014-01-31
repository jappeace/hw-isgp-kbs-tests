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
		/**
		 * size of the grid
		 */
		Size* _size;
		/**
		 * final step in the traversal proces, here the cordinates are known and only the
		 * functionpointer has to be called
		 * */
		void traverse(int x, int y, void (with*)(&Tile,&Point));
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
		Tile getTileAt(int x, int y);
		/**
		 * shorthand for getTileAt(int x, int y)
		 */
		Tile getTileAt(&Point p);

		/**
		 * The given function pointer will receive all the tiles and coordinates in the specified row
		 */
		void traverseRow(int y, void (with*)(&Tile,&Point));
		/**
		 * The given function pointer will receive all the tiles and coordinates in the specified collumn
		 */
		void traverseCollumn(int x, void (with*)(&Tile,&Point));
		/**
		 * The given function pointer will receive all the tiles in the grid and the cordiantes of them.
		 */
		void traverseTiles(void (with*)(&Tile,&Point));
	};
}


#endif	/* GRID_H */

