#ifndef __BALL_H__
#define __BALL_H__

#include <tuple>
#include "SFML/Graphics.hpp"

#define BALL_RAD 10
#define BALL_MAX_SPEED_X 0.3f
#define BALL_MIN_SPEED_X -0.3f
#define BALL_MAX_SPEED_Y 0.4f
#define BALL_MIN_SPEED_Y -0.4f

class Ball {
private:
	sf::Vector2<float> center;
	sf::Vector2<float> speed;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Ball();
	virtual ~Ball();
	void setPosition(float, float);
	void setPosition(sf::Vector2<float>);
	sf::Vector2<float> getPosition() const;
	void setSpeed(float, float);
	void setSpeed(sf::Vector2<float>);
	sf::Vector2<float> getSpeed() const;
	void update(); //�����Ӵ��� ������Ʈ
	void draw(sf::RenderWindow& window);
};

#endif