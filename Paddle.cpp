#include "Paddle.h"
Paddle::Paddle() :
	paddleSpeed(SPEED),
	width(PADDLE_WIDTH),
	height(PADDLE_HEIGHT)
{
	paddle.setSize(sf::Vector2f(width, height));
	paddle.setOutlineThickness(PADDLE_FRAME);
	paddle.setOutlineColor(sf::Color::Red);
	this->color = sf::Color::White;
	this->place.x = PADDLE_X;
	this->place.y = PADDLE_Y;
}
void Paddle::Update()
{
	paddle.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
}
void Paddle::SetSize()
{
	sf::Vector2f vec_size(120, 6);
	paddle.setSize(vec_size);
}
void Paddle::Draw(std::shared_ptr<sf::RenderWindow> window)
{
	paddle.setPosition(Objects::place);
	paddle.setFillColor(color);
	window->draw(paddle);
}
void Paddle::UpdatePosition(float x, float y)
{
	place.x += x;
	place.y += y;
	if (place.x < 0)
	{
		place.x = 0;
		place.y = PADDLE_Y;
	}
	else if (place.x > WIDTH_WINDOW - PADDLE_WIDTH)
	{
		place.x = WIDTH_WINDOW - PADDLE_WIDTH;
		place.y = PADDLE_Y;
	}
}
sf::FloatRect Paddle::GetGlobalBounds() const
{
	return paddle.getGlobalBounds();
}

