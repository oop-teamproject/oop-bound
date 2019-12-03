#include "stage.h"
#include <assert.h>

Stage::Stage() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map[i][j] = new AirBlock();
			map[i][j]->setPositionToGrid(i, j);
		}
	}
}

Stage::Stage(const std::string& filename): Stage(){
	assert(false); //지금은 여기를 쓸 수 없다.
	loadFromFile(filename);
}

Stage::~Stage() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			delete map[i][j];
			map[i][j] = NULL;
		}
	}
}

bool Stage::loadFromFile(const std::string& filename)
{
	return false;
}

bool Stage::writeToFile(const std::string& filename)
{
	return false;
}

bool Stage::deleteAt(int a, int b)
{
	delete map[a][b];
	map[a][b] = new AirBlock();
	map[a][b]->setPositionToGrid(a, b);
	return true;
}

bool Stage::setAt(int a, int b, const BaseBlock* block) {
	delete map[a][b];
	map[a][b] = new BaseBlock(*block);
	map[a][b]->setPositionToGrid(a, b);
	return true;
}

void Stage::draw(sf::RenderWindow& window) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
				map[i][j]->draw(window);
		}
	}
}
