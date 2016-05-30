#pragma once
#include <SFML\Graphics.hpp>
class BaseObject
{
public:
	virtual void update(sf::Event::EventType& type) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
};
