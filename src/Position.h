#pragma once

#include "oxygine-framework.h"
#include "Block.h"

using namespace oxygine;

DECLARE_SMART(Position, spPosition);
struct Position : public Actor
{
	Vector2 pos;
	spBlock block;

	//spPosition getPosition(const spBlock block);
};