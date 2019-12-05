#include "main.h"
#include "ball.h"

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
	if (speed.x > BALL_MAX_SPEED_X) speed.x = BALL_MAX_SPEED_X;
	if (speed.x < BALL_MIN_SPEED_X) speed.x = BALL_MIN_SPEED_X;
	if (speed.y > BALL_MAX_SPEED_Y) speed.y = BALL_MAX_SPEED_Y;
	if (speed.y < BALL_MIN_SPEED_Y) speed.y = BALL_MIN_SPEED_Y;
}

void Ball::setSpeed(sf::Vector2<float> spd)
{
	setSpeed(spd.x, spd.y);
}

void Ball::setLkPressed(bool b) {
	lKeyPressed = b;
}

void Ball::setRkPressed(bool b) {
	rKeyPressed = b;
}

bool Ball::getLkPressed() {
	return lKeyPressed;
}

bool Ball::getRkPressed() {
	return rKeyPressed;
}

sf::Vector2<float> Ball::getSpeed() const {
	return speed;
}

void Ball::update()
{
	if (lKeyPressed) {
		if (getSpeed().x > 0) {
			setSpeed(getSpeed() - sf::Vector2f(0.03f, 0.f));
		}
		else setSpeed(getSpeed() - sf::Vector2f(0.015f, 0.f));
	}
	else if (rKeyPressed) {
		if (getSpeed().x < 0) {
			setSpeed(getSpeed() + sf::Vector2f(0.03f, 0.f));
		}
		else setSpeed(getSpeed() + sf::Vector2f(0.015f, 0.f));
	}
	else setSpeed(getSpeed().x * 0.1f, getSpeed().y);
	setSpeed(getSpeed().x, getSpeed().y + 0.02f);
	setPosition(getPosition() + sf::Vector2<float>(BLOCK_SIZE * getSpeed().x, BLOCK_SIZE * getSpeed().y));

}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

