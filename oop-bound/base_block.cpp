#include "base_block.h"

BaseBlock::BaseBlock()
{

	position.x = position.y = 0;
	if (!setTexture("image/base.png")) {
		//error
	}
	sprite.setPosition((float)BLOCK_SIZE * position.x, (float)BLOCK_SIZE * position.y);
}

BaseBlock::~BaseBlock()
{
}

gamestate BaseBlock::collision_top(Ball& b) {
	b.setSpeed(b.getSpeed().x, -.4f);
	return gamestate::NO_TOKEN_ADD;
}

gamestate BaseBlock::collision_left(Ball& b) {
	b.setSpeed(-b.getSpeed().x, b.getSpeed().y);
	if (b.getLkPressed() == true)
	{
		b.setSpeed(BALL_MIN_SPEED_X, BALL_MIN_SPEED_Y*2/3);
	
	}
	return gamestate::NO_TOKEN_ADD;
}
gamestate BaseBlock::collision_right(Ball& b) {
	b.setSpeed(-b.getSpeed().x, b.getSpeed().y);
	if (b.getRkPressed() == true)
	{
		b.setSpeed(BALL_MAX_SPEED_X, BALL_MIN_SPEED_Y*2/3);
	
	}
	return gamestate::NO_TOKEN_ADD;
}

gamestate BaseBlock::collision_bottom(Ball& b) {
	b.setSpeed(b.getSpeed().x, -b.getSpeed().y*2/3);
	return gamestate::NO_TOKEN_ADD;
}


gamestate BaseBlock::collision_check(Ball& b)
{

	float blockx = getPosition().x-b.getSpeed().x;
	float blocky = getPosition().y-b.getSpeed().y;
	float ballx = b.getPosition().x;
	float bally = b.getPosition().y;
	float diffx = ballx - blockx;
	float diffy = bally - blocky;
	float nearx;
	float neary;
	
	if (diffx >= 15)       nearx = blockx + 15;
	else if (diffx <= -15) nearx = blockx - 15;
	else                   nearx = b.getPosition().x;

	if (diffy >= 15)       neary = blocky + 15;
	else if (diffy <= -15) neary = blocky - 15;
	else                   neary = b.getPosition().y;
	
	float ndiffx = ballx- nearx;
	float ndiffy = bally- neary;

	float dist = ndiffx * ndiffx + ndiffy * ndiffy;

	

	if (dist <= BALL_RAD * BALL_RAD)
	{
		
		if (ndiffx == 0 && ndiffy == 0)//안쪽에겹친파트
		{
			if (diffx <= diffy && abs(diffy) >= abs(diffx))
			{
			//안쪽아래쪽겹친파트
				b.setPosition(ballx, blocky + (BLOCK_SIZE / 2 + BALL_RAD) );
				return collision_bottom(b);
			}
			else if (diffx >= diffy && abs(diffy) >= abs(diffx))
			{
			//안쪽위쪽겹친파트
				b.setPosition(ballx , blocky  - (BLOCK_SIZE/2 + BALL_RAD ));
				return collision_top(b);
			}
			else if (diffx > diffy && abs(diffx)>= abs(diffy))
			{
				//안쪽 오른쪽겹친파트
				b.setPosition(blockx   + (BLOCK_SIZE / 2 + BALL_RAD), bally );
				return collision_right(b);
			}
			else if (diffx < diffy && abs(diffx) >= abs(diffy))
			{
				//안쪽왼쪽겹친파트
				b.setPosition(blockx   - (BLOCK_SIZE / 2 + BALL_RAD ), bally );
				return collision_left(b);
			}
			else
			{
				//검출되지않은부분?? 오류
				return gamestate::NO_TOKEN_ADD;
			}
		
		}
		else
		{ 
			if (ndiffy>0&&( ndiffx==0 || ndiffy>0 ) )
			{
			 //위쪽충돌
				b.setPosition(ballx , blocky  + (BLOCK_SIZE / 2 + BALL_RAD));
				return collision_bottom(b);
			}
			else if (ndiffy < 0 && (ndiffx == 0 || ndiffy<0)  )
			{
			//아래충돌
				b.setPosition(ballx , blocky  - (BLOCK_SIZE / 2 + BALL_RAD));
				return collision_top(b);
			}
			else if (ndiffx >= 0 && (ndiffy == 0 ))
			{
			//우측충돌
				b.setPosition(blockx + (BLOCK_SIZE / 2 + BALL_RAD), bally );
				return collision_right(b);
			}
			else if (ndiffx <=0 && (ndiffy == 0 ))
			{
			//좌측충돌
				b.setPosition(blockx  - (BLOCK_SIZE / 2 + BALL_RAD), bally);
				return collision_left(b);
			}
			else
			{
				//검출되지않은부분??
				return gamestate::NO_TOKEN_ADD;
			}
		}
	}
	return gamestate::NO_TOKEN_ADD;
}

bool BaseBlock::setTexture(std::string filename, float scale)
{
	if (!texture.loadFromFile(filename))
		return false;
	sprite.setTexture(texture, true);
	sprite.setScale(scale, scale);
	sprite.setPosition((float)position.x - (texture.getSize().x / 2) * sprite.getScale().x, (float)position.y - texture.getSize().y / 2 * sprite.getScale().y);
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
