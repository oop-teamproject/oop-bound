#include "stage.h"

Stage::Stage() {
	map = new BaseBlock * [width];
	for (int i = 0; i < height; i++) {
		map[i] = new BaseBlock;
	}
}

Stage::~Stage() {
	for (int i = 0; i < height; i++) {
		delete[] map[i];
	}
	delete[] map;
	map = NULL;
}

void Stage::setBlock(int i, int j)
{
	this 

}