#include "Block.h"
#include "res.h"

Block::Block(spSprite shape) 
{
	type = rand() % 4 + 1;

	char name[255];
	safe_sprintf(name, "lego%d", type);

	log::messageln("Type : %i", type);

	//setScale(3);

	setResAnim(res::ui.getResAnim(name));
	setSize(blockSize);
	//setPosition(*position *= getSize());
	//setX(position->x * blockSize.x);
	//setY(position->y * blockSize.y);
	
	attachTo(shape);
}