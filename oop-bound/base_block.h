#ifndef __BASE_BLOCK_H__
#define __BASE_BLOCK_H__

#include "SFML/Graphics.hpp"
#include "main.h"
#include <tuple>
#include "Ball.h"

class BaseBlock {
private:
	sf::Vector2<int> position; //블럭의 좌표. 맨 왼쪽 위를 (0,0)으로 1씩 커질 때마다 BLOCK_SIZE만큼 픽셀이 움직인다.
	sf::Texture texture; //블럭 이미지
	sf::Sprite sprite; //블럭을 그리기 위한 사각형 스프라이트 클래스
	//bool Visivle; // 장치블록 이나 부서지는 블록 충돌처리했을 떄 block에 영향을 주는것
	//int Seffect;// effect종류를 적어놔서 볼 충돌처리할 때 볼에 어떤 영향을 줄지 적어놓는것

	//BlockType case는 여기서는 5가지정도 기본블록, 부서지는 블록, 장치블록, 장치당하는 블록,
	//점프블록 순간이동 블록 
	//움직이는 블록이나 시소 삼각형은 따로정의해야될거같음 baseblock이아니라
public:
	BaseBlock();
	virtual ~BaseBlock();
	virtual void collision_top(Ball& b);
	virtual void collision_left(Ball& b);
	virtual void collision_right(Ball& b);
	virtual void collision_bottom(Ball& b);
	
	virtual bool collision_check(Ball& b);
	bool setTexture(std::string filename, float scale = 1.f);
	virtual void draw(sf::RenderWindow& window);
	void setPosition(int x, int y);
	void setPositionToGrid(int x, int y);
	sf::Vector2<int> getPosition();
};

class AirBlock: public BaseBlock{
public:
	AirBlock() {}
	~AirBlock() {}
	virtual bool collision_check(Ball& b) { return false; /*Do Nothing*/ }
	void draw(sf::RenderWindow& window) { /*Do Nothing*/ }
};
#endif