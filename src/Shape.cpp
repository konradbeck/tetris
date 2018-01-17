#include "Shape.h"
#include "Board.h"

Shape::Shape(Board* board) 
{
	this->board = board;
	this->board->addChild(this);

	isRotating = false;

	setActive(true);
	
	spBlock block1 = new Block(this);
	spBlock block2 = new Block(this);
	spBlock block3 = new Block(this);
	//spBlock block4 = new Block(this);

	blocks.push_back(block1);
	blocks.push_back(block2);
	blocks.push_back(block3);
	//blocks.push_back(block4);

	//setSize(blockSize * 3);

	//top();

	setTouchChildrenEnabled(false);
	setAnchorInPixels(getSize() / 2);
	addEventListener(TouchEvent::TOUCH_DOWN, CLOSURE(this, &Shape::rotate));
}

bool Shape::getActive()
{
	return isActive;
}

void Shape::setActive(bool isActive)
{
	this->isActive = isActive;
}

void Shape::empty()
{
	this->detach();
}

std::vector<spBlock>* Shape::getBlocks()
{
	return &blocks;
}

void Shape::moveUp(const int &speed)
{
	Vector2 position = getPosition();
	//setPosition(position -= UP * speed);
}

void Shape::moveDown(const int &speed)
{
	//Vector2 position = getPosition();
	//setPosition(position -= DOWN * speed);

	for (spBlock block : blocks)
	{
		//block-> += DOWN;
	}
}

void Shape::moveLeft()
{
	if (!isRotating)
	{
		
	}
}

void Shape::moveRight()
{
	if (!isRotating)
	{
		
	}
}

void Shape::rotate(Event* event)
{
	isRotating = true;
	spTween tween = addTween(Actor::TweenRotationDegrees(getRotationDegrees() + 90), 100);
	tween->setDoneCallback(CLOSURE(this, &Shape::rotated));
}

void Shape::rotated(Event* event)
{
	isRotating = false;
}

void Shape::top()
{
	setPosition(board->getSize().x / 2, 0);
}

bool Shape::canMoveDown()
{
	for (spBlock block : blocks)
	{
		//for (spSpace space : board->spaces)
		//{
			//if ()
		//}
	}

	return true;
}