#include "base_block.h"

BaseBlock::BaseBlock()
{
	position.x = position.y = 0;
	if (!texture.loadFromFile("image/base.png")) {
		//error
	}
	sprite.setTexture(texture, true);
	sprite.setPosition(BLOCK_SIZE * position.x, BLOCK_SIZE * position.y);
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
	sprite.setPosition(BLOCK_SIZE * x, BLOCK_SIZE * y);
}
