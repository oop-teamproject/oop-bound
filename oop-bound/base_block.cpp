#include "base_block.h"

BaseBlock::BaseBlock()
{

	position.x = position.y = 0;
	if (setTexture("image/base.png")) {
		//error
	}
	sprite.setPosition((float)BLOCK_SIZE * position.x, (float)BLOCK_SIZE * position.y);
}

BaseBlock::~BaseBlock()
{
}

bool BaseBlock::collision_check(Ball& b)
{

	float blockx = getPosition().x;
	float blocky = getPosition().y;
	float ballx = b.getPosition().x;
	float bally = b.getPosition().y;
	float diffx = ballx - blockx;
	float diffy = bally - blocky;
	float nearx;
	float neary;
	
	if (diffx >= 15)
	{
		nearx = blockx + 15;
	}
	else if (diffx <= -15)
	{
		nearx = blockx - 15;
	}
	else
	{
		nearx = b.getPosition().x;
	}
	if (diffy >= 15)
	{
		neary = blocky + 15;
	}
	else if (diffy <= -15)
	{
		neary = blocky - 15;
	}
	else
	{
		neary = b.getPosition().y;
	}
	

	float ndiffx = ballx - nearx;
	float ndiffy = bally - neary;

	float dist = sqrt(ndiffx * ndiffx + ndiffy * ndiffy);

	if (dist < 10)
	{
		if (ndiffx == 0 && ndiffy == 0)//���ʿ���ģ��Ʈ
		{
			if (diffx <= diffy && abs(diffy) >= abs(diffx))
			{
			//�������ʰ�ģ��Ʈ
				b.setPosition(ballx, blocky + 15);
				collision_top(b);
			
			}
			else if (diffx >= diffy && abs(diffy) >= abs(diffx))
			{
			//���ʾƷ��ʰ�ģ��Ʈ
				b.setPosition(ballx, blocky - 15);
				collision_bottom(b);
			}
			else if (diffx >= diffy && abs(diffx) >= abs(diffy))
			{
				//���� �����ʰ�ģ��Ʈ
				b.setPosition(blockx+15, bally);
				collision_lr(b);
			}
			else if (diffx >= diffy && abs(diffx) >= abs(diffy))
			{
				//���ʿ��ʰ�ģ��Ʈ
				b.setPosition(blockx - 15, bally);
				collision_lr(b);
			}
			else
			{
				//������������κ�?? ����
			}
		
		}
		else
		{
			if (ndiffy>=0&&( ndiffx==0 || (abs(ndiffy)>=abs(ndiffx)) ) )
			{
			 //�����浹
				collision_top(b);
			
			}
			else if (ndiffy <= 0 && (ndiffx == 0 || (abs(ndiffy) >= abs(ndiffx)) ) )
			{
			
			//�Ʒ��浹
				collision_bottom(b);
			
			}
			else if (ndiffx >= 0 && (ndiffy == 0 || (abs(ndiffx) >= abs(ndiffy))))
			{
			//�����浹
				collision_lr(b);
			
			}
			else if (ndiffx <= 0 && (ndiffy == 0 || (abs(ndiffx) >= abs(ndiffy))))
			{
				collision_lr(b);
			//�����浹
			}
			else
			{
			//������������κ�??
			}
		
		
		
		
		}
	
	
	
	
	
	
	}











	return false;
}

bool BaseBlock::setTexture(std::string filename)
{
	if (!texture.loadFromFile(filename))
		return false;
	sprite.setTexture(texture, true);
	return true;
}

void BaseBlock::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void BaseBlock::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
	sprite.setPosition((float)position.x - BLOCK_SIZE / 2, (float)position.y - BLOCK_SIZE / 2);
}

void BaseBlock::setPositionToGrid(int x, int y)
{
	position.x = BLOCK_SIZE * x + BLOCK_SIZE / 2;
	position.y = BLOCK_SIZE * y + BLOCK_SIZE / 2;
	sprite.setPosition((float)BLOCK_SIZE * x, (float)BLOCK_SIZE * y);
}

sf::Vector2<int> BaseBlock::getPosition()
{
	return position;
}
