#include "stage.h"
#include <assert.h>
#include <fstream>

Stage::Stage() {
	for (int i = 0; i < NUM_BLOCK_WIDTH; i++) {
		for (int j = 0; j < NUM_BLOCK_HEIGHT; j++) {
			map[i][j] = new AirBlock();
			map[i][j]->setPositionToGrid(i, j);
			drawlist.clear();
		}
	}
}

Stage::Stage(const std::string& filename): Stage(){
	loadFromFile(filename);
}

Stage::Stage(Stage& stage) {
	*this = stage;
}
Stage& Stage::operator=(Stage& stage)
{
	startpoint = stage.getStartPoint();
	for (int i = 0;i < NUM_BLOCK_WIDTH;i++) {
		for (int j = 0;j < NUM_BLOCK_HEIGHT;j++) {
			delete map[i][j];
			map[i][j] = stage.getAt(i, j) ->clonePtr();
			if (map[i][j]->getFileToken() != '0') //airblock이 아닌 경우
				drawlist.push_back(map[i][j]);
		}
	}
	return *this;
}

Stage::~Stage() {
	for (int i = 0; i < NUM_BLOCK_WIDTH; i++) {
		for (int j = 0; j < NUM_BLOCK_HEIGHT; j++) {
			delete map[i][j];
			map[i][j] = NULL;
		}
	}
}

bool Stage::loadFromFile(const std::string& filename)
{
	std::ifstream infile(filename);
	char token;
	for (int j = 0;j < NUM_BLOCK_HEIGHT; j++) {
		for (int i = 0;i < NUM_BLOCK_WIDTH;i++) {
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
			case TOKEN_ONOFFBLOCK_ON:
				setAt(i, j, new OnoffBlock(true));
				break;
			case TOKEN_ONOFFBLOCK_OFF:
				setAt(i, j, new OnoffBlock(false));
				break;
			case TOKEN_SWITCHBLOCK:
				setAt(i, j, new SwitchBlock(true));
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
	for (int j = 0; j < NUM_BLOCK_HEIGHT;j++) {
		for (int i = 0;i < NUM_BLOCK_WIDTH;i++) {
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
	if (a >= NUM_BLOCK_WIDTH || a < 0) return false;
	if (b >= NUM_BLOCK_HEIGHT || b < 0) return false;
	if (map[a][b] == NULL) return false;
	drawlist.remove(map[a][b]);
	delete map[a][b];
	map[a][b] = new AirBlock();
	map[a][b]->setPositionToGrid(a, b);
	return true;
}

bool Stage::setAt(int a, int b, BaseBlock* block) {
	deleteAt(a, b);
	map[a][b] = block;
	map[a][b]->setPositionToGrid(a, b);
	if(block->getFileToken() != '0')
		drawlist.push_back(map[a][b]);
	return true;
}

BaseBlock* Stage::getAt(int a, int b)
{
	if (a >= NUM_BLOCK_WIDTH || a < 0) return NULL;
	if (b >= NUM_BLOCK_HEIGHT || b < 0) return NULL;
	if (map[a][b] == NULL) return NULL;
	return map[a][b];
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

void Stage::ToggleOnoff()
{
	for (int i = 0; i < NUM_BLOCK_WIDTH; i++) {
		for (int j = 0; j < NUM_BLOCK_HEIGHT; j++) {
			int token = getAt(i, j)->getFileToken();
			if (token == TOKEN_SWITCHBLOCK) ((SwitchBlock*)getAt(i, j))->toggleSwitch();
			if(token == TOKEN_ONOFFBLOCK_OFF || token == TOKEN_ONOFFBLOCK_ON) ((OnoffBlock*)getAt(i, j))->toggleSwitch();
		}
	}
}


void Stage::draw(sf::RenderWindow& window) {
	for (auto& i : drawlist)
		i->draw(window);
}
