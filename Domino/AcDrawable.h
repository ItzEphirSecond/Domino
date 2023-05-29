#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

class AcDrawable
{
public:

	virtual void draw() = 0;

	virtual void update() = 0;

	virtual ~AcDrawable()
	{
		window = nullptr;
	}

protected:

	AcDrawable(const std::shared_ptr<sf::RenderWindow>& window): window(window)
	{
		
	}

	std::shared_ptr<sf::RenderWindow> window;

};

