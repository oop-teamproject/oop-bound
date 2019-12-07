#ifndef __STAGE_H__
#define __STAGE_H__

#include "main.h"
#include "blocktoken.h"
#include <list>
#include "ball.h"
class BaseBlock;

class Stage {
	sf::Vector2<int> startpoint;
	BaseBlock* map[NUM_BLOCK_WIDTH][NUM_BLOCK_HEIGHT] = {NULL,};
	int width = NUM_BLOCK_WIDTH;
	int height = NUM_BLOCK_HEIGHT;
	std::list<BaseBlock*> drawlist;

public:
	Stage();
	Stage(const std::string& filename); // Stage() + loadFromFile()���.
	Stage(Stage&);
	Stage& operator=(Stage&);

	virtual ~Stage();
	
	bool deleteAt(int a, int b);
	bool setAt(int a, int b, BaseBlock* block);
	BaseBlock* getAt(int a, int b) { return map[a][b]; }
	sf::Vector2<int> getStartPoint();
	bool setStartPoint(int, int);
	bool setStartPoint(sf::Vector2<int>& pt);

	bool loadFromFile(const std::string& filename); //���Ͽ��� ���������� �о�´�. ���� ���θ� ��ȯ
	bool writeToFile(const std::string& filename); //���Ͽ� ���������� ����. ���� ���θ� ��ȯ
	sf::Vector2<int> getSize() { return sf::Vector2<int>(width, height); }
	void draw(sf::RenderWindow& window);
};

#endif
