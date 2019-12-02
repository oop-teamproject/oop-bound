#ifndef __STAGE_H__
#define __STAGE_H__

#include "block.h"
#include "main.h"

class Stage {
	BaseBlock** map;
	int width = NUM_BLOCK_WIDTH;
	int height = NUM_BLOCK_HEIGHT;

public:
	Stage();
	Stage(const std::string& filename); // Stage() + loadFromFile()���.
	virtual ~Stage();

	bool loadFromFile(const std::string& filename); //���Ͽ��� ���������� �о�´�. ���� ���θ� ��ȯ
	bool writeToFile(const std::string& filename); //���Ͽ� ���������� ����. ���� ���θ� ��ȯ
	sf::Vector2<int> getSize();
	const BaseBlock** getConstMap() { return (const BaseBlock**)map; }
};

#endif