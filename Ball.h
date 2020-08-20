#pragma once
#include "Project.h"
#include "Objects.h"
class Ball 
{
private:
	bool ballActive;
	int ballSticking;
	float ballRadius;
	speed_t ballSpeed;
	sf::CircleShape ball;
	bool ballDisposablePaddle;
	sf::Vector2f ballPosition;
	std::shared_ptr<sf::RectangleShape> rect;
public:
	Ball();
	~Ball() {};

	void SetSpeed();
	bool MovingBall();
	int GetSticking();
	void SetSticking();
	void ActivateBall();
	void DeactivateBall();
	void UpdatePosition();
	void UpdateSticking();
	bool GetDisposablePaddle();
	void SetColor(sf::Color& color);
	sf::FloatRect GetGlobalBounds();
	sf::Vector2f GetPosition() const;
	void SetPosition(float x, float y);
	void SetDisposablePaddle(bool param);
	void ChangeSpeed(COLLISION_TYPE type);
	void Draw(std::shared_ptr<sf::RenderWindow> window);
	std::shared_ptr<sf::RectangleShape> GetRectangle() const;
};

