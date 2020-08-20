#pragma once

#include "Ball.h"
#include "Paddle.h"
#include "ProcessingGame.h"
#include "Project.h"
#include "Bonus.h"
class Game
{
	sf::Font font;
	sf::Text text;
	int scoreTotal;
	std::string string;
	STATE_GAME gameState;
	sf::Vector2f windowSize;
	std::shared_ptr <sf::RenderWindow> window;
	std::shared_ptr<ProcessingGame> initActions;
	std::vector<std::shared_ptr<Bonus>> bonusArray;
public:
	Game();
	~Game() {};
	void Run();
	void Draw();
	bool IsRunning();
	void DrawScore();
	STATE_GAME EndGame();
	void DrawBackground();
};
