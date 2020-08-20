#include "ProcessingGame.h"

ProcessingGame::ProcessingGame() : field(std::make_shared<Field>()), currentBrick(std::make_shared<Brick>()) {}
void ProcessingGame::Initialize()
{
	ball = std::make_shared<Ball>();
	paddle = std::make_shared<Paddle>();
}
void ProcessingGame::DrawBonuses(std::shared_ptr<sf::RenderWindow> window)
{
	for (auto it = bonusArray.begin(); it != bonusArray.end(); it++)
	{
		(*it)->Draw(window);
		(*it)->SetPosition();
		if ((*it)->GetGlobalBounds().intersects(paddle->GetGlobalBounds()))
		{
			(*it)->Create(paddle, ball, field);
			bonusArray.erase(it);
			if (bonusArray.empty())
				return;
			else
				it = bonusArray.begin();
		}
		else if ((*it)->GetPosition().y > HEIGHT_WINDOW - 2 * BALL_RADIUS - 70)
		{
			bonusArray.erase(it);
			if (bonusArray.empty())
				return;
			else
				it = bonusArray.begin();
		}
	}
}

void ProcessingGame::IsActive(std::shared_ptr< Ball> ball, std::shared_ptr< Paddle> paddle, int* totalScore)
{
	ball->UpdatePosition();
	field->CollisionDetected(ball, totalScore, paddle, &currentBrick);
	this->PaddleCollide(ball, paddle);
	if (field->IsBonus())
	{
 		this->CreateBonus(currentBrick);
		field->IsNotBonus();
	}
	ball->UpdatePosition();
}

void ProcessingGame::CreateBonus(std::shared_ptr<Brick> brick)
{
	TYPE_BONUS type = TYPE_BONUS(rand() % 6);
	switch (type)
	{
	case TYPE_BONUS::PADDLE:
	  bonusArray.push_back(std::make_shared<ChangeSizePaddle>(brick->GetPosition()));
		break;
	case TYPE_BONUS::BRICK:
		bonusArray.push_back(std::make_shared<ShiftingBrick>(brick->GetPosition())); 
		break;
	case TYPE_BONUS::DIRECTION:
		bonusArray.push_back(std::make_shared<ChangeDirection>(brick->GetPosition())); 
		break;
	case TYPE_BONUS::KEY_PRESS:
		bonusArray.push_back(std::make_shared<BallSticking>(brick->GetPosition()));
		break;
	case TYPE_BONUS::SECOND_PADDLE:
		bonusArray.push_back(std::make_shared<DisposablePaddle>(brick->GetPosition()));
		break;
	case TYPE_BONUS::SPEED:
		bonusArray.push_back(std::make_shared<ChangeSpeedBall>(brick->GetPosition()));
		break;
	default:
		break;
	}
}
bool ProcessingGame::DestroyedBricks()
{
	return field->CheckAll();
}
void ProcessingGame::GameProcess(int* scoreTotal)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		ball->ActivateBall();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		paddle->UpdatePosition(4 * abs(SPEED), 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		paddle->UpdatePosition(-4 * abs(SPEED), 0);
	if (ball->MovingBall())
		this->IsActive(ball, paddle, scoreTotal);
	else
		ball->SetPosition(paddle->GetPosition().x + 35, paddle->GetPosition().y - 3 * BALL_RADIUS + 2);
	if (ball->GetDisposablePaddle() && ball->GetPosition().x != (paddle->GetPosition().x + 35) && ball->GetPosition().y > (HEIGHT_WINDOW - 2 * BALL_RADIUS - 90))
	{
		ball->ActivateBall();
		ball->ChangeSpeed(COLLISION_TYPE::PADDLE);
		ball->SetDisposablePaddle(false);
	}
	else if (ball->GetPosition().y > HEIGHT_WINDOW - 2 * BALL_RADIUS - 90)
	{
		ball->DeactivateBall();
		paddle->Update();
		scoreTotal--;
	}
}
void ProcessingGame::Draw(std::shared_ptr<sf::RenderWindow> window)
{
	field->DrawBricks(window);
	paddle->Draw(window);
	ball->Draw(window);
}
void ProcessingGame::PaddleCollide(std::shared_ptr<Ball> ball, std::shared_ptr<Paddle> paddle)
{
	if (ball->GetGlobalBounds().intersects(paddle->GetGlobalBounds()))
	{
		ball->ChangeSpeed(COLLISION_TYPE::PADDLE); 
		if (ball->GetSticking())
		{
			ball->UpdateSticking();
			ball->DeactivateBall();
		}
	}
}