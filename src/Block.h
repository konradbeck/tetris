#pragma once

#include "oxygine-framework.h"

using namespace oxygine;

const Vector2 blockSize(50, 50);//(getStage()->getSize() / 100);

DECLARE_SMART(Block, spBlock);

class Block : public Sprite
{
	Vector2 pos; // A block has a position, a position doesn't really have a block - Beter is a block can only be in one space at a time, but how do I stop two blocks sharing the same space

public:
	int type;
	Block(spSprite shape);
};