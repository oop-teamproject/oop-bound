#include <crtdbg.h>

#include <SFML/Graphics.hpp>
#include "main.h"
#include "block.h"
#include "stage.h"
#include "level.h"
#include <vector>

int main()
{
	sf::Image icon;
	icon.loadFromFile("image/ball.png");
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Catch the flag!!");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	Level level("stage/playlist.txt");
	level.gameStartScene();
	level.start();

	while (window.isOpen() && level.running())
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
		// clear the window with black color
		window.clear(sf::Color::Black);

		level.update();
		level.draw(window);


		window.display();
		window.setFramerateLimit(60);
	}

	_CrtDumpMemoryLeaks();
	return 0;
}