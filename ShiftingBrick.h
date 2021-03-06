#pragma once
#include "Project.h"
#include "Bonus.h"
class ShiftingBrick : public Bonus
{
public:
	ShiftingBrick() {}
	ShiftingBrick(sf::Vector2f position);
	virtual ~ShiftingBrick() {}
	void Create(std::shared_ptr< Paddle> paddle, std::shared_ptr<Ball> ball, std::shared_ptr<Field> field) override;
};

