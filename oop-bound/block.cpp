#include "block.h"

DefaultBlock::DefaultBlock() {
	BaseBlock();
	if (setTexture("image/default.png")) {
		//error
	}
}

DefaultBlock::~DefaultBlock() {

}

BreakBlock::BreakBlock() {
	BaseBlock();
	if (setTexture("image/break.png")) {
		//error
	}
	broken = false;
}

BreakBlock::~BreakBlock() {

}

void BreakBlock::collision_top(Ball& b) {
	BaseBlock::collision_top(b);
	breakSelf();
}

bool BreakBlock::collision_check(Ball& b) {
	if (!broken) return BaseBlock::collision_check(b);
	return false;
}

void BreakBlock::draw(sf::RenderWindow& window) {
	if (!broken) BaseBlock::draw(window);
}

void BreakBlock::breakSelf() {
	broken = true;
}

FlagBlock::FlagBlock()
{
	BaseBlock();
	if (setTexture("image/flag.png")) {
		//error
	}
}

FlagBlock::~FlagBlock()
{
}

void FlagBlock::collision_top(Ball& b) {
	return BaseBlock::collision_top(b);
}
void FlagBlock::collision_lr(Ball& b) {

}
void FlagBlock::collision_bottom(Ball& b) {

}

BombBlock::BombBlock()
{
	BaseBlock();
	if (setTexture("image/bomb.png")) {
		//error
	}
}

void BombBlock::collision_top(Ball& b) {
	b.setSpeed(b.getSpeed().x, -.4f);
}

BombBlock::~BombBlock()
{
}
