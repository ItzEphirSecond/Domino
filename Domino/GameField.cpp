#include "GameField.h"
#include "Defines.cpp"
#include "Card.h"
#include <iostream>

GameField::GameField(std::shared_ptr<sf::RenderWindow> window, sf::Vector2f position, sf::Vector2f size) : AcDrawable(window), position(position), size(size), background(this->size)
{
	init();
}

void GameField::update()
{
	// for (auto& card : cards)
	// {
	// 	card.update();
	// }
}

void GameField::draw()
{
	window->draw(background);

	for (auto& card : cards)
	{
		card.draw();
	}
}

std::vector<sf::Vector2f> GameField::getPossiblePositions()
{
	auto result = std::vector<sf::Vector2f>();
	for (auto& card : cards)
	{
		if (!card.up)
		{
			result.push_back(sf::Vector2f(card.getPosition().x, card.getPosition().y - CARDY));
		}
		if (!card.down)
		{
			result.push_back(sf::Vector2f(card.getPosition().x, card.getPosition().y + CARDY));
		}
		if (!card.left)
		{
			result.push_back(sf::Vector2f(card.getPosition().x - CARDX, card.getPosition().y));
		}
		if (!card.right)
		{
			result.push_back(sf::Vector2f(card.getPosition().x + CARDX, card.getPosition().y));
		}
	}
	return result;
}

void GameField::drawPossibleDirections()
{
	for (auto direction : getPossiblePositions())
	{
		auto shape = sf::RectangleShape(sf::Vector2f(CARDX, CARDY));
		shape.setPosition(direction);
		shape.setFillColor(sf::Color(255, 255, 255, 50));
		window->draw(shape);
	}
}

void GameField::init()
{
	background.setPosition(position);
	background.setFillColor({ 150, 150, 150 });
	background.setSize(size);
}

void GameField::addCard(Card card)
{
	cards.push_back(card);
}

void GameField::refreshCards()
{
}

GameField::~GameField() = default;
