#include "StatisticBox.h"
#include "Definition.h"

StatisticBox::StatisticBox(sf::Vector2f size, sf::Vector2f position) : size(size)
{
	font.loadFromFile("./fonts/Krumkake.ttf");
	text.setPosition(position);
	text.setFont(font);
	text.setCharacterSize(size.y);
}
StatisticBox::~StatisticBox()
{
}

void StatisticBox::setString(char * text)
{
	this->text.setString(text);
}

void StatisticBox::setColor(sf::Color color)
{
	this->text.setColor(color);
}

const sf::Vector2f & StatisticBox::getPosition()
{
	return text.getPosition();
}

const sf::Vector2f & StatisticBox::getSize()
{
	return size;
}



void StatisticBox::update(sf::Event::EventType & type)
{
}

void StatisticBox::render(sf::RenderWindow & window)
{
	window.draw(text);
}

void StatisticBox::receiveMessage(Package * package)
{
}

std::string StatisticBox::getName()
{
	return std::string();
}
