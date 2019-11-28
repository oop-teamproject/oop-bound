#ifndef __BASE_BLOCK_H__
#define __BASE_BLOCK_H__

#include "SFML/Graphics.hpp"
#include <tuple>
#include "Ball.h"

#define BLOCK_SIZE 30

class BaseBlock {
private:
	sf::Vector2<int> position; //���� ��ǥ. �� ���� ���� (0,0)���� 1�� Ŀ�� ������ BLOCK_SIZE��ŭ �ȼ��� �����δ�.
	sf::Texture texture; //�� �̹���
	sf::Sprite sprite; //���� �׸��� ���� �簢�� ��������Ʈ Ŭ����
	//bool Visivle; // ��ġ��� �̳� �μ����� ��� �浹ó������ �� block�� ������ �ִ°�
	//int Seffect;// effect������ ������� ���浹ó���ҋ� ���� � ������ ���� ������°�

	//BlockType case�� ���⼭�� 5�������� �⺻���, �μ����� ���, ��ġ���, ��ġ���ϴ� ���,
	//������� �����̵� ��� 
	//�����̴� ����̳� �ü� �ﰢ���� ���������ؾߵɰŰ��� baseblock�̾ƴ϶�
public:
	BaseBlock();
	virtual ~BaseBlock();
	virtual void collision_top(Ball& b) {};
	virtual void collision_lr(Ball& b) {};
	virtual void collision_bottom(Ball& b) {};
	
	virtual bool collision_check(const Ball& b);
	void draw(sf::RenderWindow& window);
	void setPosition(int x, int y);
};
#endif