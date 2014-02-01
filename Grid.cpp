#include "Grid.h"
using namespace isgp;
void Grid::traverse(int x, int y, IGridTraveller& traveller){
}

void Grid::init(int width, int height){
	_size = new Size(width, height);
	_tiles = new unordered_map<int, unordered_map<int, Tile*>>(width);
	for(int x = 0; x < height; x++){
		_tiles[x] = new unordered_map<int, Tile*>(height);
		for(int y = 0; y < width; y++){
			_tiles[x][y] = new Tile();
		}
	}
	for(int x = 0; x < height; x++){
		for(int y = 0; y < width; y++){
			_tiles[x][y]->SetTop	(_tiles[x][(y + 1) % height]);
			_tiles[x][y]->SetBottom	(_tiles[x][(y - 1 + height) % height]);
			_tiles[x][y]->SetLeft	(_tiles[(x - 1 + width) % width][y]);
			_tiles[x][y]->SetRight	(_tiles[(x + 1 %) width][y]);
		}
	}
}
Grid::Grid(){
	init(C_default_size->GetWidth(), C_default_size->GetHeight());
}
Grid::Grid(int width, int height){
	init(width, height);
}
Grid::~Grid(){
	delete _tiles;
	delete C_default_size;
	delete _size;
}

Tile* Grid::getTileAt(int x, int y){
	return _tiles[x][y];
}
Tile* Grid::getTileAt(Point& p){
	return getTileAt(p.GetX(), p.GetY());
}

void Grid::traverseRow(int y, IGridTraveller& traveller){
	for(int x = 0; x < _size->GetWidth(); x++){
		traveller.receiveTile(_tiles[x][y], new Point(x, y));
	}
}
void Grid::traverseCollumn(int x, IGridTraveller& traveller){
	for(int y = 0; y < _size->GetHeight(); y++){
		traveller.receiveTile(_tiles[x][y], new Point(x, y));
	}
}
void Grid::traverseTiles(IGridTraveller& traveller){
	for(int x = 0; x < _size->GetWidth(); x++){
		traverseCollumn(x, travveler);
	}
}

Size* Grid::getSize() const {
	return _size;
}
