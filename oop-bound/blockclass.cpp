#ifndef __BASE_BLOCK_H__
#define __BASE_BLOCK_H__

#include <tuple>



class Cblock {
private:
	std::pair<int, int> position;//2d
		
		int Seffect; // effect종류를 적어놔서 볼충돌처리할떄 볼에 어떤 영향을 줄지 적어놓는것
		bool Visivle; // 장치블록 이나 부서지는 블록 충돌처리했을 떄 block에 영향을 주는것
		int BlockColor;//블록색깔

		//BlockType case는 여기서는 5가지정도 기본블록, 부서지는 블록, 장치블록, 장치당하는 블록,
		//점프블록 순간이동 블록 
		//움직이는 블록이나 시소 삼각형은 따로정의해야될거같음 baseblock이아니라



public:
		
	Cblock(void);
	~Cblock(void);

	bool hasIntersected(Cblock& ball);
	void hitBy(Cblock& ball);
	void setCenter(float x, float y);
	

	void draw();


	

};