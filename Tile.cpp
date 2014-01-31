#include "Tile.h"
using namespace isgp;
void Tile::SetBottom(Tile* bottom) {
	this->bottom = bottom;
}

Tile* Tile::GetBottom() const {
	return bottom;
}

void Tile::SetRight(Tile* right) {
	this->right = right;
}

Tile* Tile::GetRight() const {
	return right;
}

void Tile::SetLeft(Tile* left) {
	this->left = left;
}

Tile* Tile::GetLeft() const {
	return left;
}

void Tile::SetTop(Tile* top) {
	this->top = top;
}

Tile* Tile::GetTop() const {
	return top;
}
