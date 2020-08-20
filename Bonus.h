#pragma once
#include "Project.h"
#include "Objects.h"
#include "Paddle.h"
#include "Field.h"
#include "Ball.h"
class Bonus : public Objects
{
protected:
	bool activate;
	sf::Vector2f position;
	sf::RectangleShape shape;
public:
	Bonus() : activate(false) {};
	virtual ~Bonus() {};

	bool GetState();
	void SetPosition();
	void BonusActivate();
	void BonusDeactivate();
	sf::Vector2f GetPosition();
	sf::FloatRect GetGlobalBounds() const override;
	void UpdatePosition(float x, float y) override {};
	void Draw(std::shared_ptr<sf::RenderWindow> window) override;
	virtual void Create(std::shared_ptr< Paddle> paddle, std::shared_ptr<Ball> ball, std::shared_ptr<Field> field) = 0;
};

