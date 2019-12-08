#ifndef __LEVEL_H__
#define __LEVEL_H__
#include <vector>
#include <list>
#include <tuple>
#include "stage.h"
#include "gamestate.h"

class Level {
	std::vector<std::string> stages;//�������� �̸��� ����.
	std::list<std::pair<gamestate, int>> nextActs;
	//������ �� �ൿ��--�׾ �ٽ� �����ϰų�, onoff���� �ǵ帮�ų�, ������ Ŭ�����ؼ� ���� ������ ���ų� ���.
	//queueó�� �� �ڿ� �־ �� �ո� ����������, ���� �ð�(.second)�� �� ������ �����ϴ� ������ �ϴ� �� �ڵ��� ���ؼ� queue ��� list�� ����ߴ�.
	Stage currentStage;//���� ���������� ����.
	Ball ball;
	int level;//���� �� ��° ��������
	int life; //���� ���� ����� �� ������
	bool isRunning; // ���� ������ ��� ������ �ϴ���

	sf::Texture texture;
	sf::Sprite sprite;
	std::list<std::pair<std::string, int>> sceneQueue; //<�̹��� �ּ�, ��� ������.>���� ����, ���� ����, �������� ���� ���� ���� ����Ѵ�. ���� �������� ������ ������ �� ����� �켱����.
	sf::Font font; //�������� ������ �� ü���� ǥ���ϱ� ���� ��Ʈ.
	sf::Text text; //�������� ������ �� ü���� ǥ���ϱ� ���� �ؽ�Ʈ Ŭ����.
public:
	Level();
	Level(const std::string& filename);
	Level(std::vector<std::string>& levelList);
	~Level();

	/* �������� �߰�, ����, ���� */
	void appendStage(const std::string& filename);
	void deleteStage(int index);
	
	/* ���� ����*/
	void update();
	void draw(sf::RenderWindow& window);
	bool running() { return isRunning; }

	/* ���� �帧 ���� */
	void start();
	void gameStartScene(); //���α׷� ���۽�

private:
	void restartStage();
	void stageWin(); //���������� Ŭ������ ���
	void stageDeath();  //ü���� �Ҵ� ���

	void pushToken(gamestate, int = -1); // int������ �Ŀ� gamestate�� �´� �ൿ�� �Ѵ�. gamestate�� int�� queue�� �ִ� ����.
	void tokenUpdate(); //queue�� �����ϰ� ���� �ൿ�� �� �������� �Ǹ� �׿� �´� �ൿ�� �ϰ� queue�� ������Ʈ�Ѵ�.

	/*�̹��� �� ����*/
	void pushScene(std::string filename, int duration);
	void quitScene();
	void sceneUpdate();
	bool sceneRunning();

	/*�̹��� �� ȣ��*/
	void stageStartScene(); //���� �������� ���۽�
	void gameOverScene(); //ü���� 0���� ������ ���
	void gameClearScene(); //���� Ŭ����
};
#endif