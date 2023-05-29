#include "PlayerField.h"
#include "Defines.cpp"

PlayerField::PlayerField(std::shared_ptr<sf::RenderWindow> window, sf::Vector2f position, sf::Vector2f size)
	: AcDrawable(window), position(position), size(size), background(size)
{
	init();
}

void PlayerField::draw()
{
	window->draw(background);

	for (auto& card : cards)
	{
		card.draw();
	}
}

void PlayerField::update()
{
	for (auto& card : cards)
	{
		card.update();
	}
}

void PlayerField::setCards(std::vector<Card> newCards)
{
	cards = newCards;

	for (int i = 0; i < cards.size(); i++)
	{
		cards[i].setPosition(sf::Vector2f(position.x + size.x / cards.size() * i + size.x / cards.size(), position.y + size.y / 2));
	}

	for (int i = 0; i < cards.size(); i++)
	{
		auto& card = cards[i];
		card.reloadTexture();
		card.setOnCardPressed([&card, this]()
		{
			card.setPosition(sf::Vector2f(sf::Mouse::getPosition(*window)));
			gameField->drawPossibleDirections();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				if (card.getRotation() == 0)
				{
					card.setRotation(270);
				}
				else
				{
					card.setRotation(card.getRotation() - 90);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				if (card.getRotation() == 360)
				{
					card.setRotation(90);
				}
				else
				{
					card.setRotation(card.getRotation() + 90);
				}
			}
		});
		card.setOnCardReleased([&card, this, &i]()
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*window));
			auto possible = gameField->getPossiblePositions();
			if (possible.empty())
			{
				card.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
				gameField->addCard(card);
			}
			else
			{
				for (auto& direction : possible)
				{
					bool isInPossible = mousePosition.x <= direction.x + CARDX && mousePosition.x >= direction.x && mousePosition.y <= direction.y + CARDY && mousePosition.y >= direction.y;
					if (isInPossible)
					{
						card.setPosition(sf::Vector2f(direction.x + CARDX / 2, direction.y + CARDY / 2));
						gameField->addCard(card);
					}
				}
			}
		});
	}
}

void PlayerField::init()
{
	background.setPosition(position);
	background.setFillColor({ 200, 200, 200 });
}

void PlayerField::refreshCards()
{
	for (int i = 0; i < cards.size(); i++)
	{
		auto& card = cards[i];
		card.setPosition(sf::Vector2f(
			position.x + size.x / cards.size() * i + cards.size(), position.y + size.y / 2
		));
	}
}

PlayerField::~PlayerField() = default;
