#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "AcDrawable.h"
#include "Card.h"
#include "GameField.h"

class PlayerField :
    public AcDrawable
{
public:
    PlayerField(std::shared_ptr<sf::RenderWindow> window, sf::Vector2f position, sf::Vector2f size);

    virtual void draw() override;

    virtual void update() override;

    virtual void setCards(std::vector<Card> newCards);

    virtual void connect(std::shared_ptr<GameField> gameField)
    {
        this->gameField = gameField;
    }

    virtual void refreshCards();

    virtual ~PlayerField() override;

private:

    void init();

    std::vector<Card> cards = std::vector<Card>();

    sf::Vector2f position;
    sf::Vector2f size;

    sf::RectangleShape background;

    std::shared_ptr<GameField> gameField;

};

