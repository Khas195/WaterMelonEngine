#include "Tile.h"

Tile::Tile(Sprite& tileTexture)
{
	this->tileTexture = tileTexture;
	this->tileTexture.setScale(0.5, 0.5);
	rect.setSize(sf::Vector2f(32, 32));
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::Green);
	rect.setOutlineThickness(1);
}

void Tile::setBorderColor(sf::Color color)
{
	rect.setOutlineColor(color);
}

void Tile::setFillColor(sf::Color color)
{
	rect.setFillColor(color);
}

void Tile::setPosition(sf::Vector2f position)
{
	tileTexture.setPosition(position.x, position.y);
	rect.setPosition(position);
}

sf::Vector2f Tile::getPosition()
{
	return sf::Vector2f();
}

void Tile::setSize(sf::Vector2f size)
{
	rect.setSize(size);
}

void Tile::update(sf::Clock & gameTime)
{
}

void Tile::render(sf::RenderWindow & window)
{
	tileTexture.render(window);
	window.draw(rect);
}

void Tile::receiveMessage(Package * package)
{
}

std::string Tile::getName()
{
	return std::string();
}
