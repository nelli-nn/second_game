#include "ChangeSpeedBall.h"
ChangeSpeedBall::ChangeSpeedBall(sf::Vector2f position)
{
	sf::Vector2f size_bonus(10, 10);
	this->shape.setSize(size_bonus);
	this->shape.setOutlineColor(sf::Color::Green);
	this->shape.setOutlineThickness(1.0);
	this->position.x = position.x + WIDTH_BRICK / 2.0 - WIDTH_ - WIDTH;
	this->position.y = position.y + HEIGHT_BRICK / 2.0 - WIDTH_ - WIDTH;
	this->shape.setPosition(this->position);
	this->shape.setFillColor(sf::Color::White);
	this->activate = true;
}
void ChangeSpeedBall::Create(std::shared_ptr< Paddle> paddle, std::shared_ptr<Ball> ball, std::shared_ptr<Field> field)
{
	ball->SetSpeed();
}