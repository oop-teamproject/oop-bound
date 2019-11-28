#include <SFML/Graphics.hpp>
#include "base_block.h"
#include "block.h"
#include <iostream>

#define NUM_BLOCK_HEIGHT 20
#define NUM_BLOCK_WIDTH 30

#define WINDOW_HEIGHT NUM_BLOCK_HEIGHT * BLOCK_SIZE
#define WINDOW_WIDTH NUM_BLOCK_WIDTH * BLOCK_SIZE

int main()
{

	//block size = 30px * 30px
	// create the window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Catch the flag!!");
	BaseBlock* block[10];
	Ball ball;
	for (int i = 0; i < 3; i++) {
		block[i] = new DefaultBlock();
		block[i]->setPositionToGrid(i - 1, 15);
	}
	for (int i = 3; i < 6; i++) {
		block[i] = new BreakBlock();
		block[i]->setPositionToGrid(i - 1, 15);
	}
	for (int i = 6; i < 10; i++) {
		block[i] = new DefaultBlock();
		block[i]->setPositionToGrid(i - 1, 15);
	}
	block[0]->setPositionToGrid(0, 0);
	ball.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	//ball.setSpeed(1.0f / 1800, 0);
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);
		for (int i = 0; i < 10; i++) {
			block[i]->draw(window);
		}
		ball.draw(window);
		((BreakBlock*)block[5])->breakSelf();
		ball.update();
		// end the current frame
		window.display();
		window.setFramerateLimit(60);
	}

	for (int i = 0; i < 10; i++) {
		delete block[i];
		block[i] = NULL;
	}
	return 0;

}