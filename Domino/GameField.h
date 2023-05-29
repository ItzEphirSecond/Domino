#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "AcDrawable.h"
#include "Card.h"
#include <thread>

class GameField : public AcDrawable
{
public:
	GameField(std::shared_ptr<sf::RenderWindow> window, sf::Vector2f position, sf::Vector2f size);

	virtual void update() override;

	virtual void draw() override;

	virtual std::vector<sf::Vector2f> getPossiblePositions();

	virtual void drawPossibleDirections();

	virtual void addCard(Card card);

	virtual void refreshCards();

	virtual ~GameField() override;

private:

	void init();

	sf::Vector2f position;
	sf::Vector2f size;

	sf::RectangleShape background;

	std::vector<Card> cards = std::vector<Card>();

};

