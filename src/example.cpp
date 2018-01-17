#include "Board.h"
#include "res.h"

void example_preinit()
{

}

spBoard board;

void example_init()
{
	res::load();

    spSprite bg = new Sprite;
    bg->setResAnim(res::ui.getResAnim("bg"));
	bg->setSize(getStage()->getSize());

	board = new Board(9, 9);
	board->attachTo(getStage());
}

void example_destroy()
{
    board->free();
	res::free();
}
void example_update()
{

}

/*
#include "Board.h"
#include "res.h"

void example_preinit()
{

}

spBoard board;

void example_init()
{
res::load();

spSprite bg = new Sprite;
bg->setResAnim(res::ui.getResAnim("bg"));
bg->setSize(getStage()->getSize());
//bg->attachTo(getStage());

//spHttp http = new TestHttp();

board = new Board(9, 9);
board->attachTo(getStage());
}

void example_destroy()
{
board->free();
res::free();
//HttpRequestTask::release();
}
void example_update()
{

}
*/