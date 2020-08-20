#include "Brick.h"

Brick::Brick(int brickLevel, int x, int y, int _spaceX, int _spaceY) :
	brickSize({ WIDTH_BRICK, HEIGHT_BRICK }),
	destroyed(false), 
	brickSpeed(false),
	brickBonus(false),
	speed(fabs(SPEED)),
	shiftBrick(false)
{
	place.x = x * (WIDTH_BRICK + 2 * WIDTH) + WIDTH_ / 2.0;
	place.y = y * (HEIGHT_BRICK + 2 * WIDTH) + WIDTH_ / 2.0 + 40;
	this->brickLevel = brickLevel;
	brick.setSize(brickSize);

	corner[0].setSize(sf::Vector2f(WIDTH, WIDTH));
	corner[1].setSize(sf::Vector2f(WIDTH, WIDTH));
	corner[2].setSize(sf::Vector2f(WIDTH, WIDTH));
	corner[3].setSize(sf::Vector2f(WIDTH, WIDTH));

	lines[0].setSize(sf::Vector2f(WIDTH_BRICK, WIDTH));
	lines[1].setSize(sf::Vector2f(WIDTH_BRICK, WIDTH));
	lines[2].setSize(sf::Vector2f(WIDTH, HEIGHT_BRICK));
	lines[3].setSize(sf::Vector2f(WIDTH, HEIGHT_BRICK));

	frame[0].setSize(sf::Vector2f(WIDTH_BRICK + 2 * WIDTH, WIDTH_));
	frame[1].setSize(sf::Vector2f(WIDTH_BRICK + 2 * WIDTH, WIDTH_));
	frame[2].setSize(sf::Vector2f(WIDTH_, HEIGHT_BRICK + 2 * WIDTH));
	frame[3].setSize(sf::Vector2f(WIDTH_, HEIGHT_BRICK + 2 * WIDTH));

  lines[0].setPosition(x * (WIDTH_BRICK - WIDTH) + (x + 2) * WIDTH + 2 * _spaceX + WIDTH_ / 2.0, y * (HEIGHT_BRICK + WIDTH) + _spaceY + WIDTH_  + 40);
	lines[1].setPosition(x * (WIDTH_BRICK - WIDTH) + (x + 2) * WIDTH + 2 * _spaceX + WIDTH_  / 2.0, (y + 1) * ((HEIGHT_BRICK + WIDTH)) + _spaceY + 40);
	lines[2].setPosition(x * (WIDTH_BRICK + WIDTH) + _spaceX + WIDTH_, y * (HEIGHT_BRICK + WIDTH) + WIDTH + _spaceY + WIDTH_  / 2.0 + 40);
	lines[3].setPosition((x + 1) * (WIDTH_BRICK + WIDTH) + _spaceX, y * (HEIGHT_BRICK + WIDTH) + WIDTH + _spaceY + WIDTH_  / 2.0 + 40);

	corner[0].setPosition(x * (WIDTH_BRICK + WIDTH) + _spaceX + WIDTH_, (y + 1) * (HEIGHT_BRICK + WIDTH) + _spaceY + 40);
	corner[1].setPosition((x + 1) * (WIDTH_BRICK + WIDTH) + _spaceX, (y + 1) * (HEIGHT_BRICK + WIDTH) + _spaceY + 40);
	corner[2].setPosition((x + 1) * (WIDTH_BRICK + WIDTH) + _spaceX, y * (HEIGHT_BRICK + WIDTH) + _spaceY + WIDTH_  + 40);
	corner[3].setPosition(x * (WIDTH_BRICK + WIDTH) + _spaceX + WIDTH_, y * (HEIGHT_BRICK + WIDTH) + _spaceY + WIDTH_  + 40);

	frame[0].setPosition(x * (WIDTH_BRICK + WIDTH) + _spaceX, y * (HEIGHT_BRICK + WIDTH) + _spaceY + 40);
	frame[1].setPosition(x * (WIDTH_BRICK + WIDTH) + _spaceX, (y + 1) * (HEIGHT_BRICK + WIDTH) + WIDTH + _spaceY + 40);
	frame[2].setPosition(x * (WIDTH_BRICK + WIDTH) + _spaceX, y * (HEIGHT_BRICK + WIDTH) + _spaceY + 40);
	frame[3].setPosition((x + 1) * (WIDTH_BRICK + WIDTH) + WIDTH + _spaceX, y * (HEIGHT_BRICK + WIDTH) + _spaceY + 40);

	sf::FloatRect c0 = corner[0].getGlobalBounds();
	sf::FloatRect c1 = corner[1].getGlobalBounds();
	sf::FloatRect c2 = corner[2].getGlobalBounds();
	sf::FloatRect c3 = corner[3].getGlobalBounds();

	sf::FloatRect l0 = lines[0].getGlobalBounds();
	sf::FloatRect l1 = lines[1].getGlobalBounds();
	sf::FloatRect l2 = lines[2].getGlobalBounds();
	sf::FloatRect l3 = lines[3].getGlobalBounds();

	brick.setPosition(place);
}
TYPE_BRICK Brick::GetType()
{
	if (brickBonus)
		return TYPE_BRICK::BONUS;
	return TYPE_BRICK::MOVING;
}

COLLISION_TYPE Brick::TypeCollision(std::shared_ptr<Ball> ball)
{
	sf::FloatRect ball_ = ball->GetGlobalBounds();

	sf::FloatRect c0 = corner[0].getGlobalBounds();
	sf::FloatRect c1 = corner[1].getGlobalBounds();
	sf::FloatRect c2 = corner[2].getGlobalBounds();
	sf::FloatRect c3 = corner[3].getGlobalBounds();

	bool angles0 = c0.intersects(ball_);
	bool angles1 = c1.intersects(ball_);
	bool angles2 = c2.intersects(ball_);
	bool angles3 = c3.intersects(ball_);

	sf::FloatRect l0 = lines[0].getGlobalBounds();
	sf::FloatRect l1 = lines[1].getGlobalBounds();
	sf::FloatRect l2 = lines[2].getGlobalBounds();
	sf::FloatRect l3 = lines[3].getGlobalBounds();

	bool sides0 = l0.intersects(ball_);
	bool sides1 = l1.intersects(ball_);
	bool sides2 = l2.intersects(ball_);
	bool sides3 = l3.intersects(ball_);
	if (angles0 || angles1 || angles2 || angles3 || sides0 || sides1 || sides2 || sides3)
	{
		if (angles1 && angles2 && angles0)
			return COLLISION_TYPE::ANGLES;
		if (angles0 || angles1 || angles2 || angles3)
			return COLLISION_TYPE::ANGLES0;
		else if(sides0)
			return COLLISION_TYPE::SIDES0;
		else if (sides1)
			return COLLISION_TYPE::SIDES1;
		else if (sides2)
			return COLLISION_TYPE::SIDES2;
		else if (sides3)
			return COLLISION_TYPE::SIDES3;
	}
	else 
	{
		return COLLISION_TYPE::NO_COLLISION;
	}
}
void Brick::UpdatePosition()
{
	place.x += speed;
	for (int i = 0; i < 4; i++)
	{
		frame[i].setPosition(frame[i].getPosition().x + speed, frame[i].getPosition().y);
		lines[i].setPosition(lines[i].getPosition().x + speed, lines[i].getPosition().y);
		corner[i].setPosition(corner[i].getPosition().x + speed, corner[i].getPosition().y);
	}
	if (place.x < 2 * BALL_RADIUS)
	{
		for (int i = 0; i < 4; i++)
		{
			frame[i].setPosition(frame[i].getPosition().x - speed, frame[i].getPosition().y);
			lines[i].setPosition(lines[i].getPosition().x - speed, lines[i].getPosition().y);
			corner[i].setPosition(corner[i].getPosition().x - speed, corner[i].getPosition().y);
		}
		place.x -= speed;
		speed = fabs(speed);
	}
	else if (place.x > WIDTH_WINDOW - 20 * BALL_RADIUS)
	{
		for (int i = 0; i < 4; i++)
		{
			frame[i].setPosition(frame[i].getPosition().x - speed, frame[i].getPosition().y);
			lines[i].setPosition(lines[i].getPosition().x - speed, lines[i].getPosition().y);
			corner[i].setPosition(corner[i].getPosition().x - speed, corner[i].getPosition().y);
		}
		place.x -= speed;
		speed = -fabs(speed);
	}
	brick.setPosition(place.x, place.y);
}
void Brick::SetDirection()
{
	speed *= -1;
}
bool Brick::Destroyed()
{
	return destroyed;
}
bool Brick::GetSpeed()
{
	return shiftBrick;
}
void Brick::SetSpeed()
{
	shiftBrick = true;
}
int Brick::GetLevel() {
	return brickLevel;
}
void Brick::Destroy()
{
	if (brickLevel == 0)
	{
		destroyed = true;
		for (int i = 0; i < 4; i++)
		{
			frame[i].setPosition(-1000, 0);
			lines[i].setPosition(-1000, 0);
			corner[i].setPosition(-1000, 0);
		}
		brick.setPosition(-1000, 0);
	}
	else if (brickLevel != 3)
	{
		brickLevel--;
	}
}
void Brick::Draw(std::shared_ptr<sf::RenderWindow> window) 
{
	switch (brickLevel)
	{
	case COLOR::YELLOW:
		color = sf::Color::Yellow;
		break;
	case COLOR::BLACK:
		color = sf::Color::Black;
		break;
	case COLOR::BLUE:
		color = sf::Color::Blue;
		break;
	case COLOR::CYAN:
		color = sf::Color::Cyan;
		break;
	case COLOR::GREEN:
		color = sf::Color::Green;
		break;
	case COLOR::MAGENTA:
		color = sf::Color::Magenta;
		break;
	case COLOR::RED:
		color = sf::Color::Red;
		break;
	case COLOR::WHITE:
		color = sf::Color::White;
		break;
	default:
		color = sf::Color::Green;
	};
	brick.setFillColor(color);
	for (int i = 0; i < 4; i++)
	{
		frame[i].setFillColor(sf::Color::Black);
		lines[i].setFillColor(color);
		corner[i].setFillColor(color);
		window->draw(corner[i]);
		window->draw(lines[i]);
		window->draw(frame[i]);
	}
	window->draw(brick); 
}


void Brick::UpdatePosition(float x, float y)
{
	
}
void Brick::SetLevel(int brickLevel)
{
	this->brickLevel = brickLevel;
}

sf::FloatRect Brick::GetGlobalBounds() const
{
	return brick.getGlobalBounds();
}

bool Brick::IncreaseSpeed()
{
	return brickSpeed;
}
void Brick::SetType(TYPE_BRICK type)
{
	if (type == TYPE_BRICK::MOVING)
		brickSpeed = true;
	else if (type == TYPE_BRICK::BONUS)
		brickBonus = true;
}