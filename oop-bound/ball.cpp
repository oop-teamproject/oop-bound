#include "ball.h"
#define BLOCK_SIZE 30
Ball::Ball()
{
	if (!texture.loadFromFile("image/ball.png")) {
		//error
	}
	sprite.setTexture(texture, true);
	setPosition(0, 0);
	speed.x = speed.y = 0;
}

Ball::~Ball()
{
}

void Ball::setPosition(float x, float y)
{
	center.x = x;
	center.y = y;
	sprite.setPosition(center.x - BALL_RAD,
		               center.y - BALL_RAD);
}

void Ball::setPosition(sf::Vector2<float> pos)
{
	setPosition(pos.x, pos.y);
}

sf::Vector2<float> Ball::getPosition() const {
	return center;
}

void Ball::setSpeed(float x, float y)
{
	speed.x = x;
	speed.y = y;
}

void Ball::setSpeed(sf::Vector2<float> spd)
{
	setSpeed(spd.x, spd.y);
}

sf::Vector2<float> Ball::getSpeed() const {
	return speed;
}

void Ball::update()
{
	setPosition(getPosition() + sf::Vector2<float>(BLOCK_SIZE * getSpeed().x, BLOCK_SIZE * getSpeed().y));
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

