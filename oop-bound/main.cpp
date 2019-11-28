#include <SFML/Graphics.hpp>
#include "base_block.h"

int main()
{

	//block size = 30px * 30px
	// create the window
	sf::RenderWindow window(sf::VideoMode(900, 600), "My window");

	BaseBlock b[10];
	for (int i = 0; i < 10; i++) {
		b[i].setPosition(i, 0);
	}
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
			b[i].draw(window);
		}
		// end the current frame
		window.display();
	}

	return 0;

}