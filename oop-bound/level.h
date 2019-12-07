#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "stage.h"

class Level {
	std::vector<std::string> stages;//�������� �̸��� ����.
	Ball ball;
	Stage currentStage;//���� ���������� ����.
	int level;
	int life;

public:
	Level();
	Level(const std::string& filename);
	Level(std::vector<std::string>& levelList);
	~Level();

	/* �������� �߰�, ����, ���� */
	void appendStage(const std::string& filename);
	void deleteStage(int index);
	Stage& getStage();
	Ball& getBall();

	void update();
	void draw(sf::RenderWindow& window);

	void start();
	void restartStage();
	void stageWin(); //���������� Ŭ������ ���
	void stageDeath();  //ü���� �Ҵ� ���

	void gameStartScene(); //���α׷� ���۽�
	void stageStartScene(); //���� �������� ���۽�
	void gameOverScene(); //ü���� 0���� ������ ���
	void gameClearScene(); //���� Ŭ����

};
#endif