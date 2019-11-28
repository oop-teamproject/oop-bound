#ifndef __BALL_H__
#define __BALL_H__

#include <tuple>

class Ball {
private:
	sf::Vector2<float> center;
	sf::Vector2<float> speed;
public:
	Ball();
	virtual ~Ball();
	void setCenter(float, float);
	void setSpeed(float, float);
	void update();
	void draw();
};

#endif