#include <SFML/Graphics.hpp>
#include "base_block.h"
#include <iostream>

#define NUM_BLOCK_HEIGHT 20
#define NUM_BLOCK_WIDTH 30

#define WINDOW_HEIGHT NUM_BLOCK_HEIGHT * BLOCK_SIZE
#define WINDOW_WIDTH NUM_BLOCK_WIDTH * BLOCK_SIZE

int main()
{

	//block size = 30px * 30px
	// create the window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");
	BaseBlock b[10];
	Ball ball;
	for (int i = 0; i < 10; i++) {
		b[i].setPositionToGrid(i - 1, 1);
	}
	b[0].setPositionToGrid(0, 0);
	ball.setPosition(0, 0);
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
		window.clear(sf::Color::White);
		for (int i = 0; i < 10; i++) {
			b[i].draw(window);
		}
		ball.draw(window);

		ball.update();
		// end the current frame
		window.display();
		window.setFramerateLimit(60);
	}

	return 0;

}