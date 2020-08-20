#pragma once
#include "Project.h"
#include "Bonus.h"
class DisposablePaddle : public Bonus
{
public:
	DisposablePaddle() {};
	DisposablePaddle(sf::Vector2f position);
	virtual ~DisposablePaddle() {};
	void Create(std::shared_ptr< Paddle> paddle, std::shared_ptr<Ball> ball, std::shared_ptr<Field> field);
};

