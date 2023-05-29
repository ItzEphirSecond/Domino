#include "Application.h"
#include "Defines.cpp"

std::vector<std::pair<int, int>> Application::posibles = std::vector<std::pair<int, int>>();

Application::Application(std::shared_ptr<sf::RenderWindow> window) : window(window)
{
	gameField = std::make_shared<GameField>(window, sf::Vector2f(0, 0), sf::Vector2f(window->getSize().x, window->getSize().y - CARDY));
	playerField = std::make_shared<PlayerField>(window, sf::Vector2f(0, window->getSize().y - CARDY), sf::Vector2f(window->getSize().x, CARDY));
	playerField->connect(gameField);
	init();
}

void Application::init()
{
	drawables = std::vector<std::shared_ptr<AcDrawable>>();
	drawables.push_back(gameField);
	drawables.push_back(playerField);

	for (int i = 0; i <= 6; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			posibles.push_back(std::pair<int, int>(i, j));
		}
	}
}


void Application::draw()
{
	for (auto& drawable : drawables)
	{
		drawable->draw();
	} 
}

void Application::update()
{
	for (auto& drawable : drawables)
	{
		drawable->update();
	}
}

void Application::start()
{
	srand(time(0));

	auto start = std::vector<Card>();

	for (int i = 0; i < 7; i++)
	{
		auto random = rand() % posibles.size();

		start.push_back(Card(window, sf::Vector2f(0, 0), posibles[random]));
	}

	playerField->setCards(start);
}



