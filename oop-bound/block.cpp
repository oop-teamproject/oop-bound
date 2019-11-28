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