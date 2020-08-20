#include "Bonus.h"
void Bonus::Draw(std::shared_ptr<sf::RenderWindow> window) 
{
	shape.setPosition(position);
	window->draw(shape);
}
sf::FloatRect Bonus::GetGlobalBounds() const 
{
	return shape.getGlobalBounds();
}
void Bonus::SetPosition()
{
	position.y += 3;
}
void Bonus::BonusActivate()
{
	activate = true;
}
void Bonus::BonusDeactivate()
{
	activate = false;
}
bool Bonus::GetState()
{
	return activate;
}
sf::Vector2f Bonus::GetPosition()
{
	sf::Vector2f position = shape.getPosition();
	return position;
}