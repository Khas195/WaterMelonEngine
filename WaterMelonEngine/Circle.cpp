#include "Circle.h"
#include <iostream>


Circle::Circle()
{
	std::cout << "Circle Contructor " << std::endl;
}


Circle::~Circle()
{
	std::cout << "Circle Destructor " << std::endl;
}

void Circle::onAwake()
{
}

void Circle::onSleep()
{
}

void Circle::onEnable()
{
}

void Circle::onDisable()
{
}

void Circle::init()
{
	circle.setFillColor(sf::Color::Magenta);
	circle.setRadius(25.0f);
	circle.setPosition(25.0f, 25.0f);
}

void Circle::update()
{
	if (!enabled || !awake)
		return;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		circle.move(sf::Vector2f(1.0, 0.0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		circle.move(sf::Vector2f(-1.0, 0.0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		circle.move(sf::Vector2f(0.0, -1.0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		circle.move(sf::Vector2f(0.0, 1.0));
	}
}

void Circle::render(sf::RenderWindow& window)
{
	if (!enabled)
		return;
	window.draw(this->circle);
}

