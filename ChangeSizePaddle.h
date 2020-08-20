#pragma once
#include "Project.h"
#include "Bonus.h"
class ChangeSizePaddle : public Bonus
{
public:
	ChangeSizePaddle() {}
	ChangeSizePaddle(sf::Vector2f position);
	void Create(std::shared_ptr< Paddle> paddle, std::shared_ptr<Ball> ball, std::shared_ptr<Field> field) override;
	virtual ~ChangeSizePaddle() {}
};

