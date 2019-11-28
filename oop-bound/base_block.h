#ifndef __BASE_BLOCK_H__
#define __BASE_BLOCK_H__

#include "SFML/Graphics.hpp"
#include <tuple>
#include "Ball.h"

#define BLOCK_SIZE 30

class BaseBlock {
private:
	sf::Vector2<int> position;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	BaseBlock();
	virtual ~BaseBlock();
	virtual void collision_top(Ball& b) {};
	virtual void collision_lr(Ball& b) {};
	virtual void collision_bottom(Ball& b) {};
	
	virtual bool collision_check(const Ball& b);
	void draw(sf::RenderWindow& window);
	void setPosition(int x, int y);
};
#endif