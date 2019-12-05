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

	for (int i = 0; i < stage.getSize().x; i++) {
		if (i % 2)
			stage.setAt(i, 15, new BreakBlock());
		else stage.setAt(i, 15, new JumpBlock());
		stage.setAt(i + 2, 16, new DefaultBlock());
	}
	for (int i = 5; i < stage.getSize().y - 7; i++) {
		stage.setAt(22, i, new DefaultBlock());
		stage.setAt(29, i, new DefaultBlock());
	}
	stage.setAt(29, 15, new BombBlock());
	stage.deleteAt(0, 15);
	stage.deleteAt(1, 15);
	stage.deleteAt(2, 15);
	stage.deleteAt(3, 15);
	stage.deleteAt(4, 15);

	ball.setPosition(60.8800087f, 270.f);
	ball.setSpeed(0.f, -.4f);
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
		int ballGridX = int(ball.getPosition().x) / BLOCK_SIZE;
		int ballGridY = int(ball.getPosition().y) / BLOCK_SIZE;

		for (int i = ballGridX - 2; i <= ballGridX +2 ; i++) {
			for (int j = ballGridY - 2; j <= ballGridY + 2; j++) {
				if(i >= 0 && i < stage.getSize().x)
					if(j >= 0 && j < stage.getSize().y)
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