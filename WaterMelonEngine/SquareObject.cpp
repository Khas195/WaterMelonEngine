#include "SquareObject.h"

SquareObject::SquareObject(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f scale, float degree, sf::Color color)
{
	rect.setPosition(pos);
	rect.setScale(scale);
	rect.setSize(size);
	rect.rotate(degree);
	rect.setFillColor(color);
}

SquareObject::~SquareObject()
{
}

void SquareObject::update(sf::Clock & gameTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(-3, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0, 3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(3, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0, -3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		rect.rotate(-5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		rect.rotate(5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
	{
		rect.scale(10, 10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		rect.scale(.1, .1);
	}
}

void SquareObject::render(sf::RenderWindow & window)
{
	window.draw(rect);
}

void SquareObject::receiveMessage(Package * package)
{
}

std::string SquareObject::getName()
{
	return "SquareObject";
}
