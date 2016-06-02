#include "ActionButton.h"

void ActionButton::setPosition(sf::Vector2f & pos)
{
	action_button_menu.setPosition(pos);
}

void ActionButton::setPosition(float x, float y)
{
	action_button_menu.setPosition(x, y);
}

const sf::Vector2f & ActionButton::getSize()
{
}

void ActionButton::update(sf::Event::EventType & type)
{
}

void ActionButton::render(sf::RenderWindow & window)
{
}

std::string ActionButton::getName()
{
	return std::string();
}
