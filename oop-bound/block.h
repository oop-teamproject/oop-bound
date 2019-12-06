#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "base_block.h"

class DefaultBlock: public BaseBlock {
public:
	DefaultBlock();
	~DefaultBlock();
	char getFileToken() { return TOKEN_DEFAULTBLOCK; }
	BaseBlock* clonePtr() const { return new DefaultBlock(*this); }
};

class SwitchBlock : public BaseBlock {
	bool switchpressed;
public:
	SwitchBlock(bool b = true);
	~SwitchBlock();
	void collision_top(Ball& b);
	void collision_right(Ball& b);
	void collision_left(Ball& b);
	void collision_bottom(Ball& b);
	void hitswitch();
	bool getState();
	
	char getFileToken() { return TOKEN_DEFAULTBLOCK; }
	BaseBlock* clonePtr() const { return new SwitchBlock(*this); }
};

class OnoffBlock : public BaseBlock {
bool switchpressed;


public:
	OnoffBlock(bool b = true);
	~OnoffBlock();
	
	bool collision_check(Ball& b);
	char getFileToken() { return TOKEN_DEFAULTBLOCK; }
	BaseBlock* clonePtr() const { return new OnoffBlock(*this); }
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
	BaseBlock* clonePtr() const { return new BreakBlock(*this); }
};

class FlagBlock : public BaseBlock {
public:
	FlagBlock();
	~FlagBlock();
	void collision_top(Ball& b);
	char getFileToken() { return TOKEN_FLAGBLOCK; }
	BaseBlock* clonePtr() const { return new FlagBlock(*this); }
};

class BombBlock : public BaseBlock {
	bool exploded;
	float explodeScale;
public:
	BombBlock();
	~BombBlock();
	void collision_top(Ball& b);
	void collision_right(Ball& b);
	void collision_left(Ball& b);
	void collision_bottom(Ball& b);
	bool collision_check(Ball& b);
	void draw(sf::RenderWindow& window);
	char getFileToken() { return TOKEN_BOMBBLOCK; }
	BaseBlock* clonePtr() const { return new BombBlock(*this); }
};

class JumpBlock : public BaseBlock {
public:
	JumpBlock();
	~JumpBlock();
	void collision_top(Ball& b);
	char getFileToken() { return TOKEN_JUMPBLOCK; }
	BaseBlock* clonePtr() const { return new JumpBlock(*this); }
};
#endif