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
	Stage(const std::string& filename); // Stage() + loadFromFile()기능.
	virtual ~Stage();

	bool loadFromFile(const std::string& filename); //파일에서 스테이지를 읽어온다. 성공 여부를 반환
	bool writeToFile(const std::string& filename); //파일에 스테이지를 쓴다. 성공 여부를 반환
	sf::Vector2<int> getSize() { return sf::Vector2<int>(width, height); }
	const BaseBlock** getConstMap() { return (const BaseBlock**)map; }
	bool deleteAt(int a, int b);
	bool SetAt(int a, int b, BaseBlock* block); //block의 해제는 책임지지 않는다. 내부에서 복사해서 사용한다.
	const BaseBlock getAt(int a, int b) { return map[a][b]; } //복사. 느리지만, 최소한 map[a][b]가 해제돼도 안전하다.
};

#endif
