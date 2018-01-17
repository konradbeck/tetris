#pragma once

#include "oxygine-framework.h"
#include "Block.h"

using namespace oxygine;

DECLARE_SMART(Space, spSpace);
struct Space : public Actor
{
	Vector2 pos;
};