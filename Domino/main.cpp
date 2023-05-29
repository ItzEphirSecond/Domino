#include <iostream>

#include "Application.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

int main()
{
	std::setlocale(LC_ALL, "Russian");

	auto video_mode = sf::VideoMode(1920, 1080);
	auto window = std::make_shared<sf::RenderWindow>();
	window->create(video_mode, "Domino", sf::Style::Default);

	auto application = Application(window);

	window->setFramerateLimit(60);

	application.start();

	while(window->isOpen())
	{
		sf::Event _event;
		while (window->pollEvent(_event))
		{
			if(_event.type == sf::Event::Closed)
			{
				window->close();
			}
		}

		application.update();

		window->clear();

		application.draw();

		window->display();
	}
}