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
	bool collision_check(Ball& b);
	void draw(sf::RenderWindow& window);
	void breakSelf();

};

class FlagBlock : public BaseBlock {
public:
	FlagBlock();
	~FlagBlock();
	void collision_top(Ball& b);
};

class BombBlock : public BaseBlock {
public:
	BombBlock();
	void collision_top(Ball& b);
	~BombBlock();
};
#endif