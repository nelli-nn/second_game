#pragma once
#include "Project.h"
#include "Bonus.h"
class BallSticking : public Bonus
{
public:
	BallSticking() {};
	BallSticking(sf::Vector2f position);
	virtual ~BallSticking() {};
	void Create(std::shared_ptr< Paddle> paddle, std::shared_ptr<Ball> ball, std::shared_ptr<Field> field);
};

