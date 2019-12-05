#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "stage.h"

class Level {
private:
	std::vector<Stage> stages;
	int level;
	int life;
public:
	Level();
	~Level();

	void appendStage(Stage& stage);
	void appendStage(std::string& filename);
	void deleteStage(int index);
	void getStage(int i);
	void reset();

	void gameStartScene();
	void gameOverScene();
};
#endif