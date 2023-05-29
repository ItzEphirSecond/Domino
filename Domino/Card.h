#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "SFML/Graphics.hpp"
#include "AcDrawable.h"
#include <functional>
#include <iostream>
#include "Defines.cpp"

class Card : public AcDrawable
{
public:

    Card(const std::shared_ptr<sf::RenderWindow>& window, sf::Vector2f position, std::pair<int, int> numbers);

    virtual void update() override;

    virtual void draw() override;

    virtual void setOnCardPressed(std::function<void()> onCardPressed)
    {
        this->onCardPressed = onCardPressed;
    }

    virtual void setOnCardReleased(std::function<void()> onCardReleased)
    {
        this->onCardReleased = onCardReleased;
    }

    sf::Vector2f getPosition()
    {
        switch (rotation)
        {
        case 0:
        case 360:
            return position;
        case 90:
            return sf::Vector2f(position.x - CARDY, position.y);
        case 180:
            return sf::Vector2f(position.x - CARDX, position.y - CARDY);
        case 270:
            return sf::Vector2f(position.x + CARDY / 2, position.y - CARDX);
        }
    }

    virtual void setPosition(sf::Vector2f newPosition);

    virtual void reloadTexture();

    virtual void setRotation(int angle)
    {
        rotation = angle;
        sprite.setRotation(rotation);
        refreshRotation();
        
    }

    virtual int getRotation()
    {
        return rotation;
    }

    virtual ~Card() override;

    std::shared_ptr<Card> up = nullptr;
    std::shared_ptr<Card> down = nullptr;
    std::shared_ptr<Card> right = nullptr;
    std::shared_ptr<Card> left = nullptr;

private:

    void init();

    void refreshRotation();

    sf::Texture texture = sf::Texture();
    sf::Sprite sprite = sf::Sprite();
    sf::Texture numbers_texture = sf::Texture();
    sf::Sprite numbers_sprite = sf::Sprite();
    sf::Texture numbers2_texture = sf::Texture();
    sf::Sprite numbers2_sprite = sf::Sprite();

    sf::Vector2f position = sf::Vector2f();
    sf::Vector2f size = sf::Vector2f();

    std::pair<int, int> numbers;

    std::function<void()> onCardPressed;
    std::function<void()> onCardReleased;

    bool alreadyPressed = false;
    int rotation = 0;
};

