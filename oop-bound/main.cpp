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
	block[6] = new FlagBlock();
	block[6]->setPositionToGrid(5, 15);
	for (int i = 7; i < 10; i++) {
		block[i] = new BombBlock();
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