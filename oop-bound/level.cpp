#include "level.h"
#include <iostream>

Level::Level() {
	level = 0;
	life = 10;
}
Level::Level(const std ::string& filename): Level() {
	stages.push_back(filename);
	currentStage.loadFromFile(filename);
}
Level::~Level() {
}

void Level::appendStage(const std::string& filename) {
	stages.push_back(filename);
}

void Level::deleteStage(int index) {
	auto iterator = stages.begin();
	for (int i = 0; i < index - 1;i++)
		iterator++;
	stages.erase(iterator);
}

Stage& Level::getStage() {
	return currentStage;
}

Ball& Level::getBall()
{
	return ball;
}

void Level::start() {
	stageStartScene();
}

void Level::restartStage()
{
	currentStage.loadFromFile(stages[level]);
}

void Level::stageWin() {
	level++;
	if (level >= stages.size())
		gameClearScene();
	else {
		stageStartScene();
		restartStage();
	}
}

void Level::stageDeath() {
	life--;
	if (life > 0) {
		stageStartScene();
		restartStage();
	}
	else gameOverScene();
}

void Level::stageStartScene() {
	std::cout << "Stage Begin" << std::endl;
}
void Level::gameStartScene() {
	std::cout << "YOU BEGIN!" << std::endl;
}

void Level::gameOverScene() {
	std::cout << "YOU LOSEr!" << std::endl;
}

void Level::gameClearScene() {
	std::cout << "YOU WIN!" << std::endl;
}