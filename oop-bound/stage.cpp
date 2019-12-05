#include "stage.h"
#include <assert.h>
#include <fstream>

Stage::Stage() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map[i][j] = new AirBlock();
			map[i][j]->setPositionToGrid(i, j);
		}
	}
}

Stage::Stage(const std::string& filename): Stage(){
	Stage();
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
	std::ifstream infile(filename);
	char token;
	for (int j = 0;j < height; j++) {
		for (int i = 0;i < width;i++) {
			infile >> token;
			switch (token) {
			case TOKEN_AIRBLOCK:
				setAt(i, j, new AirBlock());
				break;
			case TOKEN_DEFAULTBLOCK:
				setAt(i, j, new DefaultBlock());
				break;
			case TOKEN_BREAKBLOCK:
				setAt(i, j, new BreakBlock());
				break;
			case TOKEN_FLAGBLOCK:
				setAt(i, j, new FlagBlock());
				break;
			case TOKEN_BOMBBLOCK:
				setAt(i, j, new BombBlock());
				break;
			case TOKEN_JUMPBLOCK:
				setAt(i, j, new JumpBlock());
				break;
			case TOKEN_STARTPOINT:
				startpoint = sf::Vector2<int>(i, j);
				setAt(i, j, new AirBlock());
				break;
			default:
				setAt(i, j, new AirBlock());
				break;
			}
		}
	}
	return false;
}

bool Stage::writeToFile(const std::string& filename)
{
	std::ofstream outfile(filename);
	for (int j = 0; j < height;j++) {
		for (int i = 0;i < width;i++) {
			if (i == startpoint.x && j == startpoint.y)
				outfile << TOKEN_STARTPOINT;
			else outfile << getAt(i, j)->getFileToken();
		}
		outfile << std::endl;
	}
	outfile.close();
	return false;
}

bool Stage::deleteAt(int a, int b)
{
	if (a >= width || a < 0) return false;
	if (b >= height || b < 0) return false;
	delete map[a][b];
	map[a][b] = new AirBlock();
	map[a][b]->setPositionToGrid(a, b);
	return true;
}

bool Stage::setAt(int a, int b, BaseBlock* block) {
	if (a >= width || a < 0) return false;
	if (b >= height || b < 0) return false;
	delete map[a][b];
	map[a][b] = block;
	map[a][b]->setPositionToGrid(a, b);
	return true;
}

sf::Vector2<int> Stage::getStartPoint()
{
	return startpoint;
}

bool Stage::setStartPoint(int i, int j)
{
	if (getAt(i, j)->getFileToken() == TOKEN_AIRBLOCK) {
		startpoint = sf::Vector2<int>(i, j);
		return true;
	}
	else return false;
}

bool Stage::setStartPoint(sf::Vector2<int>& pt)
{
	if (getAt(pt.x, pt.y)->getFileToken() == TOKEN_AIRBLOCK) {
		startpoint = sf::Vector2<int>(pt.x, pt.y);
		return true;
	}
	else return false;
}


void Stage::draw(sf::RenderWindow& window) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
				map[i][j]->draw(window);
		}
	}
}
