#include "Grid.h"
using namespace std;
namespace isgp{
	void Grid::traverse(unsigned x, unsigned y, IGridTraveller* traveller){
		traveller->receiveTile(getTileAt(x, y), new Point(x, y));
	}
	unsigned Grid::getTileIndex(unsigned x, unsigned y){
		return x + y * _size->GetWidth();
	}
	void Grid::init(unsigned width, unsigned height){
		_size = new Size(width, height);
		_tilesLength = (unsigned)(width*height);
		_tiles = new vector<Tile*>();
		_tiles->assign(_tilesLength, new Tile(0,0));
		
		// bind tiles to each other
		for(unsigned x = 0; x < width; x++){
			for(unsigned y = 0; y < height; y++){
				try
				{
					_tiles->at(getTileIndex(x, y))->SetPosition(new Point(x, y));
					if(y < height -2 ){
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

					if(x < width -2){
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
				}catch(const out_of_range& oor){
					
					// the default exception is just crap
					cout << "binding failed at point:" 
							<< " x:" << StrConverter::intToString(x) 
							<< " y:" << StrConverter::intToString(y) 
							<< endl << "message: "
							<< oor.what()
							<< endl;					
				}
			}
		}
	}
	Grid::Grid(){
		init(C_default_w, C_default_h);
	}
	Grid::Grid(unsigned width, unsigned height){
		init(width, height);
	}
	Grid::~Grid(){
		delete _tiles;
		delete _size;
	}

	void sizeMessage(unsigned x, unsigned y){
		
		// I used to just log this, but usualy when this happens the aplication crashed anyways,
		// so this will do fine
		throw "Unable to find tile at "
				"x: " + StrConverter::intToString(x) 
				+ "y: " + StrConverter::intToString(y) ;
	};

	Tile* Grid::getTileAt(unsigned x, unsigned y){
		unsigned desiredIndex = getTileIndex(x, y);
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

	void Grid::traverseRow(unsigned y, IGridTraveller* traveller){
		for(unsigned x = 0; x < _size->GetWidth(); x++){
			traverse(x, y, traveller);
		}
	}
	void Grid::traverseCollumn(unsigned x, IGridTraveller* traveller){
		for(unsigned y = 0; y < _size->GetHeight(); y++){
			traverse(x, y, traveller);
		}
	}
	void Grid::traverseTiles(IGridTraveller* traveller){
		for(unsigned x = 0; x < _size->GetWidth(); x++){
			traverseCollumn(x, traveller);
		}
	}

	Size* Grid::getSize() const {
		return _size;
	}
}
