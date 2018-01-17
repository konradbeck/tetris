#pragma once

#include <list>
#include "oxygine-framework.h"
#include "Shape.h"
#include "Position.h"
#include "res.h"

using namespace oxygine;

DECLARE_SMART(Board, spBoard);
class Board : public Sprite
{
	int counter;
	Vector2 size;
	
	std::list<spShape> shapes;	
	
public:
	Board(int w, int h);

	std::vector<std::vector<spPosition>> positions;
	spShape activeShape;

	void touched(Event* event);

	void doUpdate(const UpdateState& us);
	void free();

	spPosition getPosition(const spBlock block);

	spPosition getLeft(const spBlock block);
	spPosition getRight(const spBlock block);

	spPosition getDown(const spBlock block);
};