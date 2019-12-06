#include <crtdbg.h>

#include <SFML/Graphics.hpp>
#include "main.h"
#include "block.h"
#include "stage.h"
#include "level.h"
#include <iostream>

int main()
{
	sf::Image icon;
	icon.loadFromFile("image/ball.png");
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Catch the flag!!");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	Level level("stage/stage2.txt");
	level.appendStage("stage/stage1.txt");
	Stage& stage = level.getStage();
	Ball& ball = level.getBall();
	ball.setPosition(stage.getStartPoint().x * BLOCK_SIZE + BLOCK_SIZE / 2, stage.getStartPoint().y * BLOCK_SIZE + BLOCK_SIZE / 2);
	
	
	level.start();
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

		for (int i = ballGridX - 1; i <= ballGridX + 1 ; i++) {
			for (int j = ballGridY - 1; j <= ballGridY + 1; j++) {
				if(i >= 0 && i < stage.getSize().x)
					if(j >= 0 && j < stage.getSize().y)
						stage.getAt(i, j)->collision_check(ball);
			}
		}
		// clear the window with black color
		window.clear(sf::Color::Black);
		// end the current frame
		ball.draw(window);
		ball.update();
		stage.draw(window);
		window.display();
		window.setFramerateLimit(60);
	}

	_CrtDumpMemoryLeaks();
	return 0;
}