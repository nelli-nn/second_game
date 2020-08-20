#include "Field.h"
Field::Field() : isBonus(false)
{
	float _spaceX = 0;
	for (int i = 1; i <= X; i++)
	{
		float _spaceY = 0;
		for (int j = 1; j <= Y; j++)
		{
			grid.push_back(std::make_shared<Brick>(/*rand() % 3*/0, i, j, _spaceX, _spaceY));
			_spaceY += WIDTH;
			int index = i * j - 1;
			if (rand() % 20 > 17)
			{
				grid[index]->SetType(TYPE_BRICK::MOVING);
			}
			else if (rand() % 20 < 11)
			{
				grid[index]->SetType(TYPE_BRICK::BONUS);
			}
			else if (rand() % 20 < 1)
			{
				grid[index]->SetLevel(3);
			}
		}
		_spaceX += WIDTH;
	}
}
void Field::IsNotBonus()
{
	isBonus = false;
}
bool Field::IsBonus()
{
	return isBonus;
}
void Field::DrawBricks(std::shared_ptr<sf::RenderWindow> window)
{
	for (auto& it : grid)
	{
		it->Draw(window);
		if (it->GetSpeed() && !it->Destroyed())
		{
			MoveBrick(it);
		}
	}
}
void Field::MoveBrick(std::shared_ptr<Brick> brick)
{
	brick->UpdatePosition();
	this->CollisionBricks(brick);
}
COLLISION_TYPE Field::IsCollision(std::shared_ptr<Brick> brick, std::shared_ptr<Ball> ball)
{
	return brick->TypeCollision(ball);
}

void Field::CreateShiftingBrick()
{
	int x = rand() % 8 + 1;
	grid.push_back(std::make_shared<Brick>(rand() % 3, x, 7, x * WIDTH, 6 * WIDTH));
	auto it = grid.end() - 1;
	(*it)->SetSpeed();
}
bool Field::CheckAll()
{
	for (auto& it : grid)
	{
		if (it->GetLevel() != 3 && !it->Destroyed())
		{
			return false;
		}
	}
	return true;
}
void Field::CollisionDetected(std::shared_ptr<Ball> ball, int* totalScore, std::shared_ptr< Paddle> paddle, std::shared_ptr<Brick>* currentBrick)
{
	int count = 0;
	for (auto it = grid.begin(); it != grid.end(); it++, count++)
	{
		COLLISION_TYPE type = IsCollision(*it, ball);
		if (type != COLLISION_TYPE::NO_COLLISION)
		{
			if (type == COLLISION_TYPE::ANGLES)
			{
				(*(it + 5))->Destroy();
				(*(it + 1))->Destroy();
			}
			else
			{
				(*it)->Destroy();
			}
			if ((*it)->IncreaseSpeed())
			{
				ball->SetSpeed();
			}
			ball->ChangeSpeed(type);
			(*totalScore)++;
			if ((*it)->Destroyed() && (*it)->GetType() == TYPE_BRICK::BONUS)
			{
				(*currentBrick) = (*it);
				isBonus = true;
			}
			if ((*it)->GetSpeed())
				ball->UpdatePosition();
			return;
		}
	}
}
void Field::CollisionBricks(std::shared_ptr<Brick> brick)
{
	for (auto& it : grid)
	{
		if (it != brick) {
			if (brick->GetGlobalBounds().intersects(it->GetGlobalBounds()))
			{

				brick->SetDirection();
				while (brick->GetGlobalBounds().intersects(it->GetGlobalBounds()))
				{
					brick->UpdatePosition();
				}
			}
		}
	}
}