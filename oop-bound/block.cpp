#include "block.h"

DefaultBlock::DefaultBlock() {
	setTexture("image/default.png");
}

DefaultBlock::~DefaultBlock() {

}

BreakBlock::BreakBlock() {
	setTexture("image/break.png");
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
	setTexture("image/flag.png");
}

FlagBlock::~FlagBlock()
{
}

void FlagBlock::collision_top(Ball& b) {
	return BaseBlock::collision_top(b);
}

BombBlock::BombBlock()
{
	exploded = false;
	explodeScale = 1.f;
	setTexture("image/bomb.png");
}

void BombBlock::collision_top(Ball& b) {
	exploded = true;
	b.setSpeed(b.getSpeed().x, -.4f);
	setTexture("image/explosion.png");
}
void BombBlock::collision_right(Ball& b) {
	exploded = true;
	b.setSpeed(b.getSpeed().x, -.4f);
	setTexture("image/explosion.png");
}
void BombBlock::collision_left(Ball& b) {
	exploded = true;
	b.setSpeed(b.getSpeed().x, -.4f);
	setTexture("image/explosion.png");
}
void BombBlock::collision_bottom(Ball& b) {
	exploded = true;
	b.setSpeed(b.getSpeed().x, -.4f);
	setTexture("image/explosion.png");
}

bool BombBlock::collision_check(Ball& b) {
	if (!exploded)
		return BaseBlock::collision_check(b);
	else return false;
}

BombBlock::~BombBlock()
{
}

void BombBlock::draw(sf::RenderWindow& window)
{
	if (exploded) {
		explodeScale *= 1.05f;
		setTexture("image/explosion.png", explodeScale);
	}
	BaseBlock::draw(window);
}

JumpBlock::JumpBlock()
{
	setTexture("image/jump.png");
}

JumpBlock::~JumpBlock() { }

void JumpBlock::collision_top(Ball& b) {
	b.setSpeed(b.getSpeed().x, -.6f);
}
