#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "stage.h"

class Level {
	std::vector<std::string> stages;//스테이지 이름만 저장.
	Ball ball;
	Stage currentStage;//현재 스테이지를 저장.
	int level;
	int life;

public:
	Level();
	Level(const std::string& filename);
	Level(std::vector<std::string>& levelList);
	~Level();

	/* 스테이지 추가, 접근, 제거 */
	void appendStage(const std::string& filename);
	void deleteStage(int index);
	Stage& getStage();
	Ball& getBall();

	void update();
	void draw(sf::RenderWindow& window);

	void start();
	void restartStage();
	void stageWin(); //스테이지를 클리어한 경우
	void stageDeath();  //체력을 잃는 경우

	void gameStartScene(); //프로그램 시작시
	void stageStartScene(); //새로 스테이지 시작시
	void gameOverScene(); //체력이 0까지 떨어질 경우
	void gameClearScene(); //게임 클리어

};
#endif