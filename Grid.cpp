#include "Grid.h"

using namespace isgp;
void Grid::traverse(int x, int y, IGridTraveller* traveller){
	traveller->receiveTile(getTileAt(x, y), new Point(x, y));
}
int Grid::getTileIndex(int x, int y){
	return x + y * _size->GetWidth();
}
void Grid::init(int width, int height){
	_size = new Size(width, height);
	_tilesLength = (int)(width*height);
	_tiles = new vector<Tile*>();
	
	// initilize tiles
	for(int x = 0; x < height; x++){
		for(int y = 0; y < width; y++){
			_tiles->assign(getTileIndex(x, y), new Tile());
		}
	}
	
	// bind tiles to each other
	for(int x = 0; x < height; x++){
		for(int y = 0; y < width; y++){
			std::cout << "binding" 
					<< " x:" << StrConverter::intToString(x) 
					<< " y:" << StrConverter::intToString(y) 
					<< std::endl;
			if(y != height -1 ){
				_tiles->at(getTileIndex(x, y))->SetTop(
					_tiles->at(
						getTileIndex(x,y +1)
					)
				);
			}
			
			if(y != 0){
				_tiles->at(getTileIndex(x, y))->SetBottom(
					_tiles->at(
						getTileIndex(x, y -1)
					)
				);
			}
			
			if(x != width -1){
				_tiles->at(getTileIndex(x, y))->SetRight(
					_tiles->at(
						getTileIndex(x + 1, y)
					)
				);
			}
				
			if(x != 0){
				_tiles->at(getTileIndex(x, y))->SetLeft(
					_tiles->at(
						getTileIndex(x - 1, y)
					)
				);
			}
			
		}
	}
}
Grid::Grid(){
	init(C_default_w, C_default_h);
}
Grid::Grid(int width, int height){
	init(width, height);
}
Grid::~Grid(){
	delete _tiles;
	delete _size;
}

void sizeMessage(int x, int y){
	
	// I used to just log this, but usualy when this happens the aplication crashed anyways,
	// so this will do fine
	throw "Unable to find tile at "
			  "x: " + StrConverter::intToString(x) 
			+ "y: " + StrConverter::intToString(y) ;
};

Tile* Grid::getTileAt(int x, int y){
	int desiredIndex = getTileIndex(x, y);
	if(desiredIndex < 0){
		sizeMessage(x, y);
	}
	if(desiredIndex >= _tilesLength){
		sizeMessage(x, y);
	}
	return _tiles->at(desiredIndex);
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
