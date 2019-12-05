#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "base_block.h"

class DefaultBlock: public BaseBlock {
public:
	DefaultBlock();
	~DefaultBlock();
	char getFileToken() { return TOKEN_DEFAULTBLOCK; }
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
	char getFileToken() { return TOKEN_BREAKBLOCK; }

};

class FlagBlock : public BaseBlock {
public:
	FlagBlock();
	~FlagBlock();
	void collision_top(Ball& b);
	char getFileToken() { return TOKEN_FLAGBLOCK; }
};

class BombBlock : public BaseBlock {
	bool exploded;
	float explodeScale;
public:
	BombBlock();
	void collision_top(Ball& b);
	bool collision_check(Ball& b);
	~BombBlock();
	void draw(sf::RenderWindow& window);
	char getFileToken() { return TOKEN_BOMBBLOCK; }
};

class JumpBlock : public BaseBlock {
public:
	JumpBlock();
	~JumpBlock();
	void collision_top(Ball& b);
	char getFileToken() { return TOKEN_JUMPBLOCK; }
};
#endif