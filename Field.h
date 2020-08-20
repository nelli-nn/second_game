#pragma once
#include "Project.h"
#include "Brick.h"
#include "Paddle.h"
class Field
{
	bool isBonus;
	std::vector<std::shared_ptr<Brick>> grid;
public:
	Field();
	~Field() {};
	void CollisionBricks(std::shared_ptr<Brick> brick);

	bool IsBonus();	
	bool CheckAll();
	void IsNotBonus();
	void CreateShiftingBrick();
	void MoveBrick(std::shared_ptr<Brick> brick);
	void DrawBricks(std::shared_ptr<sf::RenderWindow> window);
	COLLISION_TYPE IsCollision(std::shared_ptr<Brick> brick, std::shared_ptr<Ball> ball);
	void CollisionDetected(std::shared_ptr<Ball> ball, int* totalScore, std::shared_ptr< Paddle> paddle, std::shared_ptr<Brick>* currentBrick);
};

