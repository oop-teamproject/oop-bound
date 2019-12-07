#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include <list>
#include <tuple>
#include "stage.h"
#include "gamestate.h"

class Level {
	std::vector<std::string> stages;//스테이지 이름만 저장.
	std::list<std::pair<gamestate, int>> nextActs;
	//앞으로 할 행동들--죽어서 다시 시작하거나, onoff블럭을 건드리거나, 게임을 클리어해서 다음 레벨로 가거나 등등.
	//queue처럼 맨 뒤에 넣어서 맨 앞만 접근하지만, 남은 시간(.second)을 매 프레임 변경하는 식으로 하는 게 코딩이 편해서 queue 대신 list를 사용했다.
	Stage currentStage;//현재 스테이지를 저장.
	Ball ball;
	int level;//지금 몇 번째 레벨인지
	int life; //지금 남은 목숨은 몇 개인지
	bool isRunning; // 게임 루프를 계속 돌려야 하는지
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

	void pushToken(gamestate, int = -1); // int프레임 후에 gamestate에 맞는 행동을 한다. gamestate와 int를 queue에 넣는 역할.
	void tokenUpdate(); //queue를 감시하고 다음 행동을 할 프레임이 되면 그에 맞는 행동을 하고 queue를 업데이트한다.

	void update();
	void draw(sf::RenderWindow& window);
	bool running() { return isRunning; }

	void start();
	void restartStage();
	void stageWin(); //스테이지를 클리어한 경우
	void stageDeath();  //체력을 잃는 경우

	//아래는 게임에 어떠한 영향도 끼치지 않는다. 이미지를 출력하고 끝.
	void gameStartScene(); //프로그램 시작시
	void stageStartScene(); //새로 스테이지 시작시
	void gameOverScene(); //체력이 0까지 떨어질 경우
	void gameClearScene(); //게임 클리어

};
#endif