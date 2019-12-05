#ifndef __BASE_BLOCK_H__
#define __BASE_BLOCK_H__

#include "SFML/Graphics.hpp"
#include "main.h"
#include <tuple>
#include "Ball.h"

class BaseBlock {
private:
	sf::Vector2<int> position; //���� ��ǥ. �� ���� ���� (0,0)���� 1�� Ŀ�� ������ BLOCK_SIZE��ŭ �ȼ��� �����δ�.
	sf::Texture texture; //�� �̹���
	sf::Sprite sprite; //���� �׸��� ���� �簢�� ��������Ʈ Ŭ����
	//bool Visivle; // ��ġ��� �̳� �μ����� ��� �浹ó������ �� block�� ������ �ִ°�
	//int Seffect;// effect������ ������� �� �浹ó���� �� ���� � ������ ���� ������°�

	//BlockType case�� ���⼭�� 5�������� �⺻���, �μ����� ���, ��ġ���, ��ġ���ϴ� ���,
	//������� �����̵� ��� 
	//�����̴� ����̳� �ü� �ﰢ���� ���������ؾߵɰŰ��� baseblock�̾ƴ϶�
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