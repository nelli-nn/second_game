#pragma once
#include "Project.h"
#include "Bonus.h"
class ChangeDirection : public Bonus
{
public:
	ChangeDirection() {};
	ChangeDirection(sf::Vector2f position);
	virtual ~ChangeDirection() {};

	void Create(std::shared_ptr< Paddle> paddle, std::shared_ptr<Ball> ball, std::shared_ptr<Field> field);
};

