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
	virtual void collision_top(Ball& b) { b.setSpeed(b.getSpeed().x, -b.getSpeed().y); };
	virtual void collision_lr(Ball& b) { b.setSpeed(-b.getSpeed().x, b.getSpeed().y); };
	virtual void collision_bottom(Ball& b) { b.setSpeed(b.getSpeed().x, -b.getSpeed().y); };
	
	virtual bool collision_check(const Ball& b);
	bool setTexture(std::string filename);
	virtual void draw(sf::RenderWindow& window);
	void setPosition(int x, int y);
	void setPositionToGrid(int x, int y);
	sf::Vector2<int> getPosition();
};
#endif