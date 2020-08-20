#pragma once
#include "Project.h"
#include "Brick.h"
#include "Paddle.h"
#include "Ball.h"
#include "Field.h"
#include "Bonus.h"
#include "ShiftingBrick.h"
#include "ChangeDirection.h"
#include "ChangeSpeedBall.h"
#include "ChangeSizePaddle.h"
#include "DisposablePaddle.h"
#include "BallSticking.h"
class ProcessingGame
{
	std::shared_ptr<Ball> ball;
	std::shared_ptr<Field> field;
	std::shared_ptr<Paddle> paddle;
	std::shared_ptr<Brick> currentBrick;
	std::vector<std::shared_ptr<Bonus>> bonusArray;
public:
	ProcessingGame();
	~ProcessingGame() {};

	void Initialize();
	bool DestroyedBricks();
	void GameProcess(int* scoreTotal);
	void CreateBonus(std::shared_ptr<Brick> brick);
	void Draw(std::shared_ptr<sf::RenderWindow> window);
	void DrawBonuses(std::shared_ptr<sf::RenderWindow> window);
	void PaddleCollide(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle);
	void IsActive(std::shared_ptr<Ball> ball, std::shared_ptr< Paddle> paddle, int* totalScore);
};