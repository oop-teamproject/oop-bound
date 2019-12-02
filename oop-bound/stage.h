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
	sf::Vector2<int> getSize();
	const BaseBlock** getConstMap() { return (const BaseBlock**)map; }
};

#endif