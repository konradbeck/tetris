#pragma once

#include "Block.h"

using namespace oxygine;

class Tile
{
	Point position;
	//Block block;
public:
	Tile();
	Point& getPosition();
	void setPosition(int x, int y);
};

DECLARE_SMART(Tile, spTile);