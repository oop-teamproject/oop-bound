#include "base_block.h"

BaseBlock::BaseBlock()
{

	position.x = position.y = 0;
	if (!texture.loadFromFile("image/base.png")) {
		//error
	}
	sprite.setTexture(texture, true);
	sprite.setPosition((float)BLOCK_SIZE * position.x, (float)BLOCK_SIZE * position.y);
}

BaseBlock::~BaseBlock()
{
}

bool BaseBlock::collision_check(const Ball& b)
{
	float dx = getPosition().x % 30;
	float sx = getPosition().x / 30;
	float dy = getPosition().y % 30;
	float sy = getPosition().y / 30;
	int caseX = 0;
	int caseY = 0;
	if (dx <= 10)
	{
		caseX = 1;
	}
	else if (dx <= 20)
	{
		caseX = 2;
	}
	else
	{
		caseX = 3;
	}
	if (dy <= 10)
	{
		caseY = 1;
	}
	else if (dy <= 20)
	{
		caseY = 2;
	}
	else
	{
		caseY = 3;
	}
	if (caseX == 1 && caseY == 1)
	{
		if (dx >= dy)
		{
			setPosition(getPosition.x, 10+30*sy);
			//y의속도 반대로


		}
		else
		{
			setPosition(10 + 30 * sx, getPosition.y);
			//x의 속도반대로
		}
	}
	if (caseX == 2 && caseY == 1)
	{
		setPosition(getPosition.x, 10 + 30 * sy);
		//y의 속도 반대로
	
	}
	if (caseX == 3 && caseY == 1)
	{
		if (30-dx >= dy)
		{
			setPosition(getPosition().x, 10 + 30 * sy);
			//y의 속도반대로
		}
		else
		{
			setPosition(20 + 30 * sx, getPosition().y);
			//x의 속도반대로
		}
	
	}
	if (caseX == 1 && caseY == 2)
	{
		setPosition(30 * sx + 10, getPosition().y);
		//x의속도 반대로
	
	}
	if (caseX == 2 && caseY == 2)
	{
	//아무일도없다.
	}
	if (caseX == 3 && caseY == 2)
	{
		setPosition(30 * sx + 20, getPosition().y);
		//x의속도반대로

	
	}
	if (caseX == 1 && caseY == 3)
	{
		if (dx >= 30 - dy)
		{
			setPosition(30 * sx + 20, getPosition().y);
			//x속도반대로
		}
		else
		{
			setPosition(getPosition().x, 30 * sy + 20);
			//y속도반대로
		}
	}
	if (caseX == 2 && caseY == 3)
	{
		setPosition(getPosition().x, 30 * sy + 20);
		//y속도반대로
	
	}
	if (caseX == 3 && caseY == 3)
	{
		if (30 - dx >= 30 - dy)
		{
			setPosition(getPosition().x, 30 * sy + 20);
			//y속반대로
		}
		else
		{
			setPosition(30 * sx + 20, getPosition().y);
			//x의속도반대로
		}
		
	
	}
	return false;
}

void BaseBlock::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void BaseBlock::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
	sprite.setPosition((float)position.x - BLOCK_SIZE / 2, (float)position.y - BLOCK_SIZE / 2);
}

void BaseBlock::setPositionToGrid(int x, int y)
{
	position.x = BLOCK_SIZE * x + BLOCK_SIZE / 2;
	position.y = BLOCK_SIZE * y + BLOCK_SIZE / 2;
	sprite.setPosition((float)BLOCK_SIZE * x, (float)BLOCK_SIZE * y);
}

sf::Vector2<int> BaseBlock::getPosition()
{
	return position;
}
