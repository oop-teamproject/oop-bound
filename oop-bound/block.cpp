#include "block.h"

DefaultBlock::DefaultBlock() {
	setTexture("image/default.png");
}

DefaultBlock::~DefaultBlock() {

}

SwitchBlock::SwitchBlock(bool on) {
	switchpressed = on;
	setTexture("image/onswitch.png");
}
SwitchBlock::~SwitchBlock() {

}

void SwitchBlock::toggleSwitch() {
	setState(!getState());
}

void SwitchBlock::setState(bool b)
{
	switchpressed = b;
	if (b) setTexture("image/onswitch.png");
	else setTexture("image/offswitch.png");
}


bool SwitchBlock::getState() {
	return switchpressed;
}

gamestate SwitchBlock::collision_top(Ball& b) {
	b.setSpeed(b.getSpeed().x, -.4f);
	return gamestate::ONOFF_UPDATE;
}
gamestate SwitchBlock::collision_right(Ball& b) {
	b.setSpeed(-b.getSpeed().x, b.getSpeed().y);
	return gamestate::ONOFF_UPDATE;
}
gamestate SwitchBlock::collision_left(Ball& b) {
	b.setSpeed(-b.getSpeed().x, b.getSpeed().y);
	return gamestate::ONOFF_UPDATE;
}
gamestate SwitchBlock::collision_bottom(Ball& b) {
	b.setSpeed(b.getSpeed().x, -b.getSpeed().y*2/3);
	return gamestate::ONOFF_UPDATE;
}

OnoffBlock::OnoffBlock(bool on) {
	setState(on);
}
OnoffBlock::~OnoffBlock() {
}
void OnoffBlock::setState(bool b) {
	switchpressed = b;
	if (b) setTexture("image/on.png");
	else setTexture("image/off.png");
}
bool OnoffBlock::getState() {
	return switchpressed;
}

void OnoffBlock::toggleSwitch() {
	setState(!getState());
}
gamestate OnoffBlock::collision_check(Ball& b)
{
	if (getState()) BaseBlock::collision_check(b);
	return gamestate::NO_TOKEN_ADD;
}


BreakBlock::BreakBlock() {
	setTexture("image/break.png");
	broken = false;
}

BreakBlock::~BreakBlock() {

}

gamestate BreakBlock::collision_top(Ball& b) {
	BaseBlock::collision_top(b);
	breakSelf();
	return gamestate::NO_TOKEN_ADD;
}

gamestate BreakBlock::collision_check(Ball& b) {
	if (!broken) return BaseBlock::collision_check(b);
	return gamestate::NO_TOKEN_ADD;
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

gamestate FlagBlock::collision_top(Ball& b) {
	return gamestate::WIN;
}
gamestate FlagBlock::collision_right(Ball& b) {
	return gamestate::WIN;
}
gamestate FlagBlock::collision_left(Ball& b) {
	return gamestate::WIN;
}
gamestate FlagBlock::collision_bottom(Ball& b) {
	return gamestate::WIN;
}

BombBlock::BombBlock()
{
	exploded = false;
	explodeScale = 1.f;
	setTexture("image/bomb.png");
}

gamestate BombBlock::collision_top(Ball& b) {
	exploded = true;
	b.setSpeed(b.getSpeed().x, -.4f);
	setTexture("image/explosion.png");
	return gamestate::DEAD;
}
gamestate BombBlock::collision_right(Ball& b) {
	exploded = true;
	b.setSpeed(-b.getSpeed().x, b.getSpeed().y);
	setTexture("image/explosion.png");
	return gamestate::DEAD;
}
gamestate BombBlock::collision_left(Ball& b) {
	exploded = true;
	b.setSpeed(-b.getSpeed().x, b.getSpeed().y);
	setTexture("image/explosion.png");
	return gamestate::DEAD;
}
gamestate BombBlock::collision_bottom(Ball& b) {
	exploded = true;
	b.setSpeed(b.getSpeed().x, -b.getSpeed().y);
	setTexture("image/explosion.png");
	return gamestate::DEAD;
}

gamestate BombBlock::collision_check(Ball& b) {
	if (!exploded)
		return BaseBlock::collision_check(b);
	else return gamestate::NO_TOKEN_ADD;
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

gamestate JumpBlock::collision_top(Ball& b) {
	b.setSpeed(b.getSpeed().x, -.6f);
	return gamestate::NO_TOKEN_ADD;
}
