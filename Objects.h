#pragma once
#include "Project.h"
class Objects : sf::RectangleShape
{
protected:
  sf::Color color;
  sf::Vector2f place;
  std::shared_ptr<sf::Shape> shape;
public:
  Objects();
  virtual ~Objects() {};
  sf::Vector2f GetPosition() const;
  virtual sf::FloatRect GetGlobalBounds() const;
  virtual void UpdatePosition(float x, float y) = 0;
  virtual void Draw(std::shared_ptr<sf::RenderWindow> window) = 0;
};
