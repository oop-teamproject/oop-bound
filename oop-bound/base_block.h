#ifndef __BASE_BLOCK_H__
#define __BASE_BLOCK_H__

#include <tuple>

class BaseBlock {
private:
	std::pair<int, int> position;
public:
	virtual void collision_top(Ball& b) = 0;
	virtual void collision_lr(Ball& b) = 0;
	virtual void collision_bottom(Ball& b) = 0;
	
	virtual bool collision_check(const Ball& b);
	void draw();
};
#endif