#include "Ball.h"
Ball::Ball() :
	ballPosition({BALL_X, BALL_Y}),
  ballSpeed({-SPEED, -SPEED}),
	ballRadius(BALL_RADIUS), 
	ballActive(false),
	ballDisposablePaddle(false),
	ballSticking(0)
{
	rect = std::make_shared<sf::RectangleShape>(sf::Vector2f((float)2.0 * ballRadius, (float)2.0 * ballRadius));
	ball.setRadius(ballRadius);
	ball.setFillColor(sf::Color::White);
}

std::shared_ptr<sf::RectangleShape> Ball::GetRectangle()
  const
{
	return rect;
}

void Ball::Draw(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(ball);
}
void Ball::SetSpeed()
{
	if (ballSpeed.vx <= 2.0 && ballSpeed.vy <= 2) {
		ballSpeed.vx += ((2.0 / 10.0) * fabs(ballSpeed.vx) / ballSpeed.vx);
		ballSpeed.vy += ((1.0 / 10.0) * fabs(ballSpeed.vy) / ballSpeed.vy);
	}
}

void Ball::SetPosition(float x, float y)
{
	ballPosition.x = x;
	ballPosition.y = y;
	ball.setPosition(ballPosition);
}

sf::Vector2f Ball::GetPosition() const
{
	return ballPosition;
}

void Ball::SetColor(sf::Color & color)
{
	ball.setFillColor(color);
}
bool Ball::MovingBall()
{
	return ballActive;
}
void Ball::ActivateBall()
{
	ballActive = true;
}
void Ball::DeactivateBall()
{
	ballSpeed.vx = SPEED; 
	ballSpeed.vy = -SPEED;
	ballActive = false;
}
void Ball::UpdatePosition()
{
	ballPosition.x += ballSpeed.vx;
	ballPosition.y += ballSpeed.vy;
  if (ballPosition.x < 2 * BALL_RADIUS)
	{
		ballPosition.x -= ballSpeed.vx;
		ballSpeed.vx = fabs(ballSpeed.vx);
	}
	else if (ballPosition.x > WIDTH_WINDOW - 4 * BALL_RADIUS)
	{
		ballPosition.x -= ballSpeed.vx;
		ballSpeed.vx = -fabs(ballSpeed.vx);
	}
	else if (ballPosition.y < 2 * BALL_RADIUS)
	{
		ballPosition.y -= ballSpeed.vy;
		ballSpeed.vy = fabs(ballSpeed.vy);
	}
	ball.setPosition(ballPosition.x, ballPosition.y);
}
void Ball::ChangeSpeed(COLLISION_TYPE type)
{
	switch (type)
	{
	case COLLISION_TYPE::ANGLES:
		ballSpeed.vx *= -1;
		ballSpeed.vy *= -1;
		break;
	case COLLISION_TYPE::ANGLES0:
		ballSpeed.vx *= -1;
		ballSpeed.vy *= -1;
		break;
	case COLLISION_TYPE::SIDES0:
		ballSpeed.vy = -fabs(ballSpeed.vy);
		break;
	case COLLISION_TYPE::SIDES1:
		ballSpeed.vy = fabs(ballSpeed.vy);
		break;
	case COLLISION_TYPE::SIDES2:
		ballSpeed.vx = -fabs(ballSpeed.vx);
		break;
	case COLLISION_TYPE::SIDES3:
		ballSpeed.vx = fabs(ballSpeed.vx);
		break;
	case COLLISION_TYPE::PADDLE:
		ballSpeed.vy *= -1;
		break;
	case COLLISION_TYPE::BALL:
		ballSpeed.vx *= -1;
		ballSpeed.vy *= -1;
	break;
	default:
		break;
	}
}
void Ball::UpdateSticking()
{
	ballSticking--;
}
bool Ball::GetDisposablePaddle()
{
	return ballDisposablePaddle;
}
int Ball::GetSticking()
{
	return ballSticking;
}
void Ball::SetSticking()
{
	ballSticking = 3;
}
void Ball::SetDisposablePaddle(bool param)
{
	ballDisposablePaddle = param;
}
sf::FloatRect Ball::GetGlobalBounds()
{
	return ball.getGlobalBounds();
}

