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
	for (int i = 10; i < 20; i++)
	{
		stage.setAt(3, i, new BombBlock());
	}
	for (int i = 0; i < 16; i++)
	{
		stage.setAt(10, i, new DefaultBlock());
	}
	for (int i = 10; i < 20; i = i + 2)
	{
		stage.setAt(4, i ,new DefaultBlock());
	}
	for (int i = 10; i < 20; i++)
	{
		stage.setAt(6, i, new BombBlock());
	}
	for (int i = 1; i < 20; i++)
	{
		stage.setAt(i, 19, new DefaultBlock());
	}
	stage.setAt(10, 16, new BombBlock());
	
	stage.setAt(12, 16, new BombBlock());
	stage.setAt(10, 16, new BombBlock());
	stage.setAt(0, 16, new BombBlock());
	stage.setAt(20, 18, new BombBlock());
	for (int i = 17; i > 6; i--)
	{

		stage.setAt(13, i, new DefaultBlock());
	}
	for (int i = 17; i > 6; i--) {
	stage.setAt(15, i, new DefaultBlock());
}
	stage.setAt(29, 14, new FlagBlock());
	


	ball.setPosition(5*BLOCK_SIZE, 18 * BLOCK_SIZE);
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