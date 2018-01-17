#pragma once

#include <list>
#include "Block.h"
#include "Position.h"

const int totalBlocks = 4;

const int HORIZONTAL_SPEED = 50;
const int VERTICTAL_SPEED = 100;

class Board;

DECLARE_SMART(Shape, spShape);
class Shape : public Sprite
{
	bool isRotating;
	bool isActive;
public:
	std::vector<spBlock> blocks;

	Shape(Board* board);

	bool getActive();
	void setActive(bool isActive);

	std::vector<spBlock>* getBlocks();

	void moveRight();
	void moveLeft();
	void moveUp(const int &speed = 1);
	void moveDown(const int &speed = 1);

	bool canMoveDown();

	void top();
	void empty();
	void rotate(Event* event);

	void rotated(Event* event);
protected:
	Board* board;
};