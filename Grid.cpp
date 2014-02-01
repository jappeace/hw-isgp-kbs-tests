#include "Grid.h"
using namespace isgp;
void Grid::traverse(int x, int y, IGridTraveller& traveller){
	traveller.receiveTile(_tiles[x][y], new Point(x, y));
}
int Grid::getTileIndex(int x, int y){
	return x + y * _size->GetWidth();
}
void Grid::init(int width, int height){
	_size = new Size(width, height);
	_tilesLength = width*height-1;
	_tiles = new Tile[_tilesLength];
	
	for(int x = 0; x < height; x++){
		for(int y = 0; y < width; y++){
			_tiles[getTileIndex(x, y)] = new Tile();
		}
	}
	for(int x = 0; x < height; x++){
		for(int y = 0; y < width; y++){
			_tiles[getTileIndex(x, y)]->SetTop		(_tiles[x][(y + 1) % height]);
			_tiles[getTileIndex(x, y)]->SetBottom	(_tiles[x][(y - 1 + height) % height]);
			_tiles[getTileIndex(x, y)]->SetLeft		(_tiles[(x - 1 + width) % width][y]);
			_tiles[getTileIndex(x, y)]->SetRight	(_tiles[(x + 1 %) width][y]);
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

void sizeMessage(int x, int y){
	// I used to just log this, but usualy when this happens the aplication crashed anyways,
	// so this will do fine
	throw "Unable to find tile at x: " + x + " y: " + y;
};

Tile* Grid::getTileAt(int x, int y){
	int desiredIndex = getTileIndex(x, y);
	if(desiredIndex < 0){
		sizeMessage(x, y);
	}
	if(desiredIndex >= _tilesLength){
		sizeMessage(x, y);
	}
	return _tiles[desiredIndex];
}
Tile* Grid::getTileAt(Point& p){
	return getTileAt(p.GetX(), p.GetY());
}

void Grid::traverseRow(int y, IGridTraveller* traveller){
	for(int x = 0; x < _size->GetWidth(); x++){
		traverse(x, y, traveller);
	}
}
void Grid::traverseCollumn(int x, IGridTraveller* traveller){
	for(int y = 0; y < _size->GetHeight(); y++){
		traverse(x, y, traveller);
	}
}
void Grid::traverseTiles(IGridTraveller* traveller){
	for(int x = 0; x < _size->GetWidth(); x++){
		traverseCollumn(x, traveller);
	}
}

Size* Grid::getSize() const {
	return _size;
}
