#ifndef __BASE_BLOCK_H__
#define __BASE_BLOCK_H__

#include "SFML/Graphics.hpp"
#include "main.h"
#include <tuple>
#include "Ball.h"
#include "blocktoken.h"
#include "gamestate.h"

class BaseBlock {
private:
	sf::Vector2<int> position; //���� ��ǥ. �� ���� ���� (0,0)���� 1�� Ŀ�� ������ BLOCK_SIZE��ŭ �ȼ��� �����δ�.
	sf::Texture texture; //�� �̹���
	sf::Sprite sprite; //���� �׸��� ���� �簢�� ��������Ʈ Ŭ����
	//int Seffect;// effect������ ������� �� �浹ó���� �� ���� � ������ ���� ������°�

	//BlockType case�� ���⼭�� 5�������� �⺻���, �μ����� ���, ��ġ���, ��ġ���ϴ� ���,
	//������� �����̵� ��� 
	//�����̴� ����̳� �ü� �ﰢ���� ���������ؾߵɰŰ��� baseblock�̾ƴ϶�
public:
	BaseBlock();
	virtual ~BaseBlock();
	virtual gamestate collision_top(Ball& b);
	virtual gamestate collision_left(Ball& b);
	virtual gamestate collision_right(Ball& b);
	virtual gamestate collision_bottom(Ball& b);
	
	virtual gamestate collision_check(Ball& b);

	bool setTexture(std::string filename, float scale = 1.f);
	virtual void draw(sf::RenderWindow& window);
	void setPosition(int x, int y);
	void setPositionToGrid(int x, int y);
	sf::Vector2<int> getPosition();

	virtual char getFileToken() = 0;
	virtual BaseBlock* clonePtr() const = 0;
};

class AirBlock: public BaseBlock{
public:
	AirBlock() {}
	~AirBlock() {}
	virtual gamestate collision_check(Ball& b) { return gamestate::NO_TOKEN_ADD; /*Do Nothing*/ }
	void draw(sf::RenderWindow& window) { /*Do Nothing*/ }
	
	char getFileToken() { return TOKEN_AIRBLOCK; }
	BaseBlock* clonePtr() const { return new AirBlock(*this); };
};
#endif