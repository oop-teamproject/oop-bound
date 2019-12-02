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
	sf::Vector2<int> getSize() { return sf::Vector2<int>(width, height); }
	const BaseBlock** getConstMap() { return (const BaseBlock**)map; }
	bool deleteAt(int a, int b);
	bool SetAt(int a, int b, BaseBlock* block); //block�� ������ å������ �ʴ´�. ���ο��� �����ؼ� ����Ѵ�.
	const BaseBlock getAt(int a, int b) { return map[a][b]; } //����. ��������, �ּ��� map[a][b]�� �����ŵ� �����ϴ�.
};

#endif
