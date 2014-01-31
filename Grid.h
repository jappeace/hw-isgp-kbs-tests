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
using namespace std;
namespace isgp {
	class Grid{
	private:
		unordered_map<int, unordered_map<int, Tile>*>* tiles;
	};
}


#endif	/* GRID_H */

