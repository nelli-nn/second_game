#include "Game.h"

Game::Game() :
	gameState(STATE_GAME::CONTINUING_GAME),
	windowSize({ WIDTH_WINDOW, HEIGHT_WINDOW }),
	scoreTotal(0),
	initActions(std::make_shared<ProcessingGame>())
{
	this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode((unsigned int)WIDTH_WINDOW, (unsigned int)HEIGHT_WINDOW), "Arcanoid");
	this->window->setFramerateLimit(FRAMERATE_LIMIT);
	this->font.loadFromFile("FONT/TimesNewRoman.ttf");
}
STATE_GAME Game::EndGame()
{
	if (initActions->DestroyedBricks())
		return STATE_GAME::GAME_OVER;
	return STATE_GAME::CONTINUING_GAME;
}
void Game::Run()
{
	initActions->Initialize();
	while (IsRunning() && gameState != STATE_GAME::GAME_OVER)
	{
		sf::Event event;
		if (window->pollEvent(event))
			if (event.type == sf::Event::Closed)
				window->close();
		initActions->GameProcess(&scoreTotal);
		if (this->EndGame() == STATE_GAME::GAME_OVER)
		{
			this->DrawBackground();
			std::string textScore = "GAME OVER. The total number of points : " + std::to_string(scoreTotal);
			sf::Text text;
			text.setString(textScore);
			text.setFont(font);
			text.setCharacterSize(SIZE_FONT);
			text.setPosition(WIDTH_WINDOW / 6.0, HEIGHT_WINDOW / 2.0 - 40.0);
			window->draw(text);
			window->display();
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
			window->close();
		}
		this->Draw();
	}
}

bool Game::IsRunning()
{
	if (window->isOpen())
		return true;
	return false;
}

void Game::DrawBackground()
{
	window->clear();
	sf::Vector2f size_back(WIDTH_WINDOW, HEIGHT_WINDOW);
	sf::RectangleShape background;
	background.setSize(size_back);
	background.setPosition(0.0, 0.0);
	background.setFillColor(sf::Color::Black);
	window->draw(background);
}
void Game::DrawScore()
{
	std::string textScore = "The total number of points : " + std::to_string(scoreTotal);
	sf::Text text;
	text.setString(textScore);
	text.setFont(font);
	text.setCharacterSize(SIZE_FONT);
	text.setPosition(TEXT_X, TEXT_Y);
	window->draw(text);
}

void Game::Draw()
{
	window->clear();
	this->DrawBackground();
	this->DrawScore();
	initActions->Draw(window); 
	initActions->DrawBonuses(window);
	window->display();
}