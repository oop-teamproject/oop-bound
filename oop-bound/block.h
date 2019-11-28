#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "base_block.h"

class DefaultBlock: public BaseBlock {
public:
	DefaultBlock();
	~DefaultBlock();
};

class BreakBlock : public BaseBlock {
bool broken;

public:
	BreakBlock();
	~BreakBlock();
	void collision_top(Ball& b);
	bool collision_check(const Ball& b);
	void draw(sf::RenderWindow& window);
	void breakSelf();

};

#endif