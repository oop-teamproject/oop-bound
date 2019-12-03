#include <SFML/Graphics.hpp>
#include "main.h"
#include "block.h"
#include "stage.h"
#include <iostream>

int main()
{

	//block size = 30px * 30px
	// create the window
	sf::Image icon;
	icon.loadFromFile("image/ball.png");
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Catch the flag!!");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	
	Stage stage;
	Ball ball;

	for (int i = 0; i < stage.getSize().y; i++) {
		stage.setAt(i, 15, new BreakBlock());
	}


	ball.setPosition(20 , WINDOW_HEIGHT / 2);
	//ball.setSpeed(1.0f / 1800, 0);
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			ball.setLkPressed(true);
			ball.setRkPressed(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			ball.setLkPressed(false);
			ball.setRkPressed(true);
		}
		else {
			ball.setLkPressed(false);
			ball.setRkPressed(false);
		}
		//collision between ball and blocks
		int ballGridX = ball.getPosition().x / BLOCK_SIZE;
		int ballGridY = ball.getPosition().y / BLOCK_SIZE;

		for (int i = ballGridX - 1; i < ballGridX + 1; i++) {
			for (int j = ballGridY - 1; j < ballGridY + 1; j++) {
				if (i >= 0 && i < NUM_BLOCK_WIDTH)
					if (j >= 0 && j < NUM_BLOCK_HEIGHT)
						stage.getAt(i, j)->collision_check(ball);
			}
		}
		// clear the window with black color
		window.clear(sf::Color::Black);
		ball.draw(window);
		ball.update();
		// end the current frame
		stage.draw(window);
		window.display();
		window.setFramerateLimit(60);
	}

	return 0;
}