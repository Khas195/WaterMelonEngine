#include "Square.h"
#include <stdio.h>


Square::Square(sf::Color color, sf::Vector2f pos, sf::Vector2f size)
{
	this->rectangle.setFillColor(color);
	this->rectangle.setPosition(pos);
	this->rectangle.setSize(size);
}
Square::~Square()
{
}

void Square::init()
{
}

void Square::update(sf::Clock& gameTime)
{
	if (!isEnable || !isAwake)
		return;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rectangle.move(sf::Vector2f(0.0, -1.0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rectangle.move(sf::Vector2f(-1.0, 0.0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rectangle.move(sf::Vector2f(1.0, 0.0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rectangle.move(sf::Vector2f(0.0, 1.0));
	}
	this->updateChildren(gameTime);
}

void Square::render(sf::RenderWindow & window)
{
	if (!isEnable)
		return;

	window.draw(rectangle);
	this->renderChildren(window);
}

std::string Square::getName()
{
	return "Square";
}

void Square::onAwake()
{
}

void Square::onSleep()
{
}

void Square::onEnable()
{
}

void Square::onDisable()
{
}


