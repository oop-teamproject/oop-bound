#ifndef __INTERACT__BLOCK_H__
#define __INTERACT__BLOCK_H__

#include "base_block.h"
#include <list>

class InteractBlock : public BaseBlock {
private:
	std::list<InteractBlock*> interactList;
public:
	virtual void interact() = 0;
	virtual void get_interact(InteractBlock* by_whom) = 0;
};

#endif
