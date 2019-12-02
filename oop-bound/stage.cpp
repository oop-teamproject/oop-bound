#include "stage.h"

Stage::Stage() {
	map = new BaseBlock * [width];
	for (int i = 0; i < height; i++) {
		map[i] = new BaseBlock;
	}
}

Stage::Stage(const std::string& filename): Stage(){
	loadFromFile(filename);
}

Stage::~Stage() {
	for (int i = 0; i < height; i++) {
		delete[] map[i];
	}
	delete[] map;
	map = NULL;
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
	map[a][b] = AirBlock();
	return true;
}

bool Stage::SetAt(int a, int b, BaseBlock* block) {
	if (block == NULL)
		return false;
	map[a][b] = *block;
	return true;
}
