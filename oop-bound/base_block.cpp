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
