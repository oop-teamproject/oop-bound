#ifndef __BALL_H__
#define __BALL_H__

#include <tuple>

class Ball() {
private:
	std::pair<float, float> center;
	std::pair<float, float> speed;
public:
	Ball();
	virtual ~Ball();
	void setCenter(float, float);
	void setSpeed(float, float);
	void update();
	void draw();
}


#endif