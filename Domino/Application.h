#pragma once
#include <memory>
#include "AcDrawable.h"
#include "SFML/Graphics.hpp"
#include <utility>
#include "GameField.h"
#include "PlayerField.h"
#include <vector>


class Application
{
public:

	Application(std::shared_ptr<sf::RenderWindow> window);

	void init();

	void draw();

	void update();

	void start();

private:

	std::shared_ptr<sf::RenderWindow> window;

	std::vector<std::shared_ptr<AcDrawable>> drawables;

	std::shared_ptr<PlayerField> playerField;

	std::shared_ptr<GameField> gameField;

	static std::vector<std::pair<int, int>> posibles;

};

