#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "stage.h"

class Level {
public:
	Level();
	~Level();

	/* 스테이지 추가, 접근, 제거 */
	void appendStage(Stage& stage);
	void appendStage(std::string& filename);
	void deleteStage(int index);
	std::string* getStage(int i);

	void stageWin(); //스테이지를 클리어한 경우
	void stageDeath();  //체력을 잃는 경우

	void gameStartScene(); //프로그램 시작시
	void gameOverScene(); //체력이 0까지 떨어질 경우

private:
	std::vector<std::string> stages;//스테이지 이름만 저장.
	Stage currentStage;//현재 스테이지를 저장.
	int level;
	int life;

};
#endif