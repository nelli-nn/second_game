#pragma once
#include "Project.h"
#include "Bonus.h"
class ChangeSpeedBall : public Bonus
{
public:
	ChangeSpeedBall() {};
	ChangeSpeedBall(sf::Vector2f position);
	virtual ~ChangeSpeedBall() {};
	void Create(std::shared_ptr< Paddle> paddle, std::shared_ptr<Ball> ball, std::shared_ptr<Field> field) override;
};

