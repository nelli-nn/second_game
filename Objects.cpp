#include "Objects.h"
Objects::Objects()
{
  shape = std::make_shared<sf::RectangleShape>();
}
sf::FloatRect Objects::GetGlobalBounds() const
{
  return shape->getGlobalBounds();
}
sf::Vector2f Objects::GetPosition() const
{
  return place;
}


