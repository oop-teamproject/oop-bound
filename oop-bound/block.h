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

class BreakBlock : public BaseBlock {
bool broken;

public:
	BreakBlock();
	~BreakBlock();

	void draw(sf::RenderWindow& window);
	void breakSelf();
	char getFileToken() { return TOKEN_BREAKBLOCK; }
	BaseBlock* clonePtr() const { return new BreakBlock(*this); }

private:
	gamestate collision_top(Ball& b);
	gamestate collision_check(Ball& b);
};

class FlagBlock : public BaseBlock {
public:
	FlagBlock();
	~FlagBlock();

	char getFileToken() { return TOKEN_FLAGBLOCK; }
	BaseBlock* clonePtr() const { return new FlagBlock(*this); }

private:
	gamestate collision_top(Ball& b);
	gamestate collision_right(Ball& b);
	gamestate collision_left(Ball& b);
	gamestate collision_bottom(Ball& b);
};

class BombBlock : public BaseBlock {
	bool exploded;
	float explodeScale;
public:
	BombBlock();
	~BombBlock();

	gamestate collision_check(Ball& b);
	void draw(sf::RenderWindow& window);
	char getFileToken() { return TOKEN_BOMBBLOCK; }
	BaseBlock* clonePtr() const { return new BombBlock(*this); }
private:
	gamestate collision_top(Ball& b);
	gamestate collision_right(Ball& b);
	gamestate collision_left(Ball& b);
	gamestate collision_bottom(Ball& b);
};

class JumpBlock : public BaseBlock {
public:
	JumpBlock();
	~JumpBlock();

	char getFileToken() { return TOKEN_JUMPBLOCK; }
	BaseBlock* clonePtr() const { return new JumpBlock(*this); }

private:
	gamestate collision_top(Ball& b);
};

class SwitchBlock : public BaseBlock {
	bool switchpressed;
public:
	SwitchBlock(bool b = true);
	~SwitchBlock();

	void toggleSwitch();
	void setState(bool);
	bool getState();

	char getFileToken() { return TOKEN_SWITCHBLOCK; }
	BaseBlock* clonePtr() const { return new SwitchBlock(*this); }

private:
	gamestate collision_top(Ball& b);
	gamestate collision_right(Ball& b);
	gamestate collision_left(Ball& b);
	gamestate collision_bottom(Ball& b);
};

class OnoffBlock : public BaseBlock {
	bool switchpressed;
public:
	OnoffBlock(bool b = true);
	~OnoffBlock();

	void toggleSwitch();
	void setState(bool);
	bool getState();
	gamestate collision_check(Ball& b);
	char getFileToken() { return getState() ? TOKEN_ONOFFBLOCK_ON : TOKEN_ONOFFBLOCK_OFF; }
	BaseBlock* clonePtr() const { return new OnoffBlock(*this); }
};

#endif