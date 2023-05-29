#include "Card.h"
#include "Defines.cpp"

Card::Card(const std::shared_ptr<sf::RenderWindow>& window, sf::Vector2f position, std::pair<int, int> numbers)
	: AcDrawable(window), position(position), numbers(numbers)
{
	init();
}

void Card::update()
{
	sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*window));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		bool isInCard = mousePosition.x <= position.x + size.x && mousePosition.x >= position.x && mousePosition.y <= position.y + size.y && mousePosition.y >= position.y;
		if (isInCard)
		{
			if (alreadyPressed)
			{
				onCardPressed();
			}
			else
			{
				alreadyPressed = true;
			}
		}
	}
	else
	{
		if (alreadyPressed)
		{
			alreadyPressed = false;
			onCardReleased();
		}
	}
}

void Card::draw()
{
	window->draw(sprite);
	window->draw(numbers_sprite);
	window->draw(numbers2_sprite);
}

void Card::init()
{
	texture.loadFromFile("res/card.png");
	sprite.setTexture(texture);
	size = sf::Vector2f(texture.getSize());
	sprite.setPosition(position);
	std::string path1 = "res/" + std::to_string(numbers.first) + ".png";
	std::string path2 = "res/" + std::to_string(numbers.second) + ".png";
	numbers_texture.loadFromFile(path1);
	numbers2_texture.loadFromFile(path2);
	numbers_sprite.setTexture(numbers_texture);
	numbers2_sprite.setTexture(numbers2_texture);
}

void Card::refreshRotation()
{
	switch (rotation)
	{
	case 0:
	case 360:
		size = sf::Vector2f(CARDX, CARDY);
		numbers_sprite.setPosition(position);
		numbers_sprite.setRotation(rotation);
		numbers2_sprite.setPosition(sf::Vector2f(position.x, position.y + size.y / 2));
		numbers2_sprite.setRotation(rotation);
		break;
	case 90:
		size = sf::Vector2f(CARDY, CARDX);
		numbers_sprite.setPosition(sf::Vector2f(sprite.getPosition().x - CARDY / 2, sprite.getPosition().y));
		numbers2_sprite.setPosition(sf::Vector2f(sprite.getPosition().x - CARDY, sprite.getPosition().y));
		break;
	case 180:
		size = sf::Vector2f(CARDX, CARDY);
		numbers_sprite.setPosition(sf::Vector2f(sprite.getPosition().x - CARDX, sprite.getPosition().y - CARDY / 2));
		numbers2_sprite.setPosition(sf::Vector2f(sprite.getPosition().x - CARDX, sprite.getPosition().y - CARDY));
		break;
	case 270:
		size = sf::Vector2f(CARDY, CARDX);
		numbers_sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - CARDX));
		numbers2_sprite.setPosition(sf::Vector2f(sprite.getPosition().x + CARDY / 2, sprite.getPosition().y - CARDX));
		break;
	}
}


void Card::setPosition(sf::Vector2f newPosition)
{
	position = sf::Vector2f(newPosition.x - size.x / 2, newPosition.y - size.y / 2);
	sprite.setPosition(position);
	refreshRotation();
}

void Card::reloadTexture()
{
	texture.loadFromFile("res/card.png");
	sprite.setTexture(texture);
	size = sf::Vector2f(texture.getSize());
	sprite.setPosition(position);
	std::string path1 = "res/" + std::to_string(numbers.first) + ".png";
	std::string path2 = "res/" + std::to_string(numbers.second) + ".png";
	numbers_texture.loadFromFile(path1);
	numbers2_texture.loadFromFile(path2);
	numbers_sprite.setTexture(numbers_texture);
	numbers2_sprite.setTexture(numbers2_texture);

	
}

Card::~Card() = default;
