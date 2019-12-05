#ifndef __STAGE_H__
#define __STAGE_H__

#include "block.h"
#include "main.h"
#include "blocktoken.h"

class Stage {
	sf::Vector2<int> startpoint;
	BaseBlock* map[NUM_BLOCK_WIDTH][NUM_BLOCK_HEIGHT];
	int width = NUM_BLOCK_WIDTH;
	int height = NUM_BLOCK_HEIGHT;

public:
	Stage();
	Stage(const std::string& filename); // Stage() + loadFromFile()���.
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
