#ifndef __BASE_BLOCK_H__
#define __BASE_BLOCK_H__

#include <tuple>



class Cblock {
private:
	std::pair<int, int> position;//2d
		
		int Seffect; // effect������ ������� ���浹ó���ҋ� ���� � ������ ���� ������°�
		bool Visivle; // ��ġ��� �̳� �μ����� ��� �浹ó������ �� block�� ������ �ִ°�
		int BlockColor;//��ϻ���

		//BlockType case�� ���⼭�� 5�������� �⺻���, �μ����� ���, ��ġ���, ��ġ���ϴ� ���,
		//������� �����̵� ��� 
		//�����̴� ����̳� �ü� �ﰢ���� ���������ؾߵɰŰ��� baseblock�̾ƴ϶�



public:
		
	Cblock(void);
	~Cblock(void);

	bool hasIntersected(Cblock& ball);
	void hitBy(Cblock& ball);
	void setCenter(float x, float y);
	

	void draw();


	

};