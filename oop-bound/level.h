#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include "stage.h"

class Level {
public:
	Level();
	~Level();

	/* �������� �߰�, ����, ���� */
	void appendStage(Stage& stage);
	void appendStage(std::string& filename);
	void deleteStage(int index);
	std::string* getStage(int i);

	void stageWin(); //���������� Ŭ������ ���
	void stageDeath();  //ü���� �Ҵ� ���

	void gameStartScene(); //���α׷� ���۽�
	void gameOverScene(); //ü���� 0���� ������ ���

private:
	std::vector<std::string> stages;//�������� �̸��� ����.
	Stage currentStage;//���� ���������� ����.
	int level;
	int life;

};
#endif