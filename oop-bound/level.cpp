#include "level.h"
#include <fstream>
#include <iostream>

Level::Level() {
	level = 0;
	life = 10;
}
Level::Level(const std ::string& listfile): Level() {
	std::ifstream ifs;
	std::string filename;
	ifs.open(listfile);
	while (!ifs.eof()) {
		ifs >> filename;
		stages.push_back("stage/" + filename + ".txt");
	}
	currentStage.loadFromFile(stages[0]);
	ifs.close();
}
Level::Level(std::vector<std::string>& levelList) : Level() {
	for (auto& i : levelList) {
		stages.push_back(i);
	}
	currentStage.loadFromFile(levelList[0]);
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

void Level::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		ball.setLkPressed(true);
		ball.setRkPressed(false);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		ball.setLkPressed(false);
		ball.setRkPressed(true);
	}
	else {
		ball.setLkPressed(false);
		ball.setRkPressed(false);
	}
	//collision between ball and blocks
	int ballGridX = int(ball.getPosition().x) / BLOCK_SIZE;
	int ballGridY = int(ball.getPosition().y) / BLOCK_SIZE;

	for (int i = ballGridX - 1; i <= ballGridX + 1; i++) {
		for (int j = ballGridY - 1; j <= ballGridY + 1; j++) {
			if (i >= 0 && i < currentStage.getSize().x)
				if (j >= 0 && j < currentStage.getSize().y)
					currentStage.getAt(i, j)->collision_check(ball);
		}
	}
	ball.update();
}

void Level::draw(sf::RenderWindow& window)
{
	currentStage.draw(window);
	ball.draw(window);
}

void Level::start() {
	stageStartScene();
	ball.setPosition(float(currentStage.getStartPoint().x * BLOCK_SIZE + BLOCK_SIZE / 2), float(currentStage.getStartPoint().y * BLOCK_SIZE + BLOCK_SIZE / 2));
}

void Level::restartStage()
{
	currentStage.loadFromFile(stages[level]);
	start();
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