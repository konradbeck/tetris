#include "Board.h"

using namespace oxygine;

const Point UP(0, 1);
const Point DOWN(0, -1);
const Point LEFT(-1, 0);
const Point RIGHT(1, 0);

const Point dirUp(0, -1);
const Point dirDown(0, 1);
const Point dirLeft(-1, 0);
const Point dirRight(1, 0);

Board::Board(int w, int h) : counter(0)
{
	size.x = w;
	size.y = h;

	setClock(new Clock);

	setResAnim(res::ui.getResAnim("bg"));
	setSize(size.x * blockSize.x, size.y * blockSize.y);
	//setSize(getStage()->getSize() / 2);
	//setPosition(getStage()->getPosition());

	//spaces.resize(size.x * size.y);

	// Gonna loop through rows and not columns - from the bottom up, so we handle multiple rows shifting down
	for (int y = 0; y < size.y; y++)
	{
		std::vector<spPosition> positionRows;

		for (int x = 0; x < size.x; x++)
		{
			spPosition position = new Position;
			position->pos = Vector2(x, y);
			positionRows.push_back(position);
		}
		positions.push_back(positionRows);
	}

	//setAnchor(Vector2(0.5f, 0.5f));
	//setPosition(getStage()->getSize() / 2);
	
	setPosition(getStage()->getSize() / 2 - getSize() / 2);
	shapes.push_back(activeShape = new Shape(this));
	
	for (int i = 0; i < activeShape->blocks.size(); i++)
	{
		positions[i][0]->block = activeShape->blocks[i];
	}

	addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &Board::touched));
}

void Board::doUpdate(const UpdateState& state)
{
	counter++;

	if (counter > 50)
	{
		counter = 0;
		int blockSize = activeShape->blocks.size();
		blockSize--;

		for (int i = blockSize; i >= 0; i--)
		{
			spPosition currentPosition = getPosition(activeShape->blocks[i]);
			spPosition downPosition = getDown(activeShape->blocks[i]);

			if (currentPosition && downPosition && !downPosition->block)
			{
				currentPosition->block = nullptr;
				downPosition->block = activeShape->blocks[i];
			}
		}
	}

	// Move Blocks according to their position
	for (std::vector<spPosition> positionRows : positions)
	{
		for (spPosition position : positionRows)
		{
			if (position->block)
			{
				position->block->setPosition(position->pos * blockSize.x);
			}
		}
	}
}

spPosition Board::getPosition(const spBlock block)
{	
	for (std::vector<spPosition> positionRows : positions)
	{
		for (spPosition position : positionRows)
		{
			if (position->block == block)
			{
				return position;
			}
		}
	}

	return nullptr;
}

spPosition Board::getRight(const spBlock block)
{
	for (std::vector<spPosition> positionRows : positions)
	{
		for (int x = 0; x < positionRows.size(); x++)
		{
			if (positionRows[x]->block == block)
			{
				int index = x;
				int size = positionRows.size();
				index++;
				size--;

				if (size < index)
				{
					return nullptr;
				}
				else
					return positionRows[++x];
			}
		}
	}

	return nullptr;
}

spPosition Board::getLeft(const spBlock block)
{
	for (std::vector<spPosition> positionRows : positions)
	{
		for (int x = 0; x < positionRows.size(); x++)
		{
			if (positionRows[x]->block == block)
			{
				int index = x;
				int size = positionRows.size();
				index++;
				size--;

				if (size < index)
				{
					return nullptr;
				}
				else
					return positionRows[--x];
			}
		}
	}

	return nullptr;
}

spPosition Board::getDown(const spBlock block)
{
	for (int y = 0; y < positions.size(); y++)
	{
		for (int x = 0; x < positions[y].size(); x++)
		{
			if (positions[y][x]->block == block)
			{
				int index = y;
				int positionSize = positions.size();
				positionSize--;
				index++;
				
				if (positionSize < index)
				{
					return nullptr;
				}
				else
					return positions[index][x];
			}
		}
	}

	return nullptr;
}

void Board::touched(Event* event)
{
	TouchEvent* te = safeCast<TouchEvent*>(event);
	Vector2 pos = te->localPosition;

	int column = 0;

	for (spBlock block : activeShape->blocks)
	{
		spPosition currentPosition = getPosition(block);

		if (currentPosition)
		{
			column = currentPosition->pos.x;
		}
	}

	if ((pos.x /= blockSize.x) < column)
	{
		for (spBlock block : activeShape->blocks)
		{
			spPosition currentPosition = getPosition(block);
			spPosition leftPosition = getLeft(block);

			if (currentPosition && leftPosition && !leftPosition->block)
			{
				currentPosition->block = nullptr;
				leftPosition->block = block;
			}
		}
	}
	else
	{
		for (spBlock block : activeShape->blocks)
		{
			spPosition currentPosition = getPosition(block);
			spPosition rightPosition = getRight(block);

			if (currentPosition && rightPosition && !rightPosition->block)
			{
				currentPosition->block = nullptr;
				rightPosition->block = block;
			}
		}
	}
}

void Board::free()
{
	this->detach();
}