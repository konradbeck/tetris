#include "Tile.h"

Tile::Tile() {}

Point& Tile::getPosition()
{
	return position;
}

void Tile::setPosition(int x, int y)
{
	position = Point(x, y);
}