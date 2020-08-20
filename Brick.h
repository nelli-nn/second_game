#pragma once

#include "Project.h"
#include "Objects.h"
#include "Ball.h"
class Brick : public Objects
{
private:
	int speed;
	bool destroyed;
	int brickLevel;
	bool brickSpeed;
	bool shiftBrick;
	bool brickBonus;
	sf::Vector2f brickSize;
	sf::RectangleShape brick;
	sf::Vector2f brickPosition;
	sf::RectangleShape lines[4];
	sf::RectangleShape frame[4];
	sf::RectangleShape corner[4];
public:
	Brick(int brickLevel, int x, int y, int _spaceX, int _spaceY);
	Brick() : brickLevel(0), destroyed(false), brickSpeed(false), brickBonus(false), speed(fabs(SPEED)), shiftBrick(false) {};
	virtual ~Brick() {};

	void Destroy();
	int GetLevel();
	bool GetSpeed();
	void SetSpeed();
	bool Destroyed();
	void SetDirection();
	bool IncreaseSpeed();
	TYPE_BRICK GetType();
	void UpdatePosition();
	void SetType(TYPE_BRICK type);
	void SetLevel(int brickLevel);
	void UpdatePosition(float x, float y) override;
	sf::FloatRect GetGlobalBounds() const override;
	COLLISION_TYPE TypeCollision(std::shared_ptr<Ball> ball);
	void Draw(std::shared_ptr<sf::RenderWindow> window) override;
};

