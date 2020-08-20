#pragma once

#include "Project.h"
#include "Objects.h"

class Paddle : public Objects
{
private:
	float width;
	float height;
	float paddleSpeed;
	sf::RectangleShape paddle;
public:
	Paddle();
	virtual ~Paddle() {};

	void Update();
	void SetSize();
	void UpdatePosition(float x, float y) override;
	sf::FloatRect GetGlobalBounds() const override;
	void Draw(std::shared_ptr<sf::RenderWindow> window) override;
};

