#include "DefaultObject.h"

void DefaultObject::update(sf::Event::EventType& type)
{
	if (isEnable && isAwake)
		this->updateChildren(type);
}

void DefaultObject::render(sf::RenderWindow & window)
{
	if (isAwake)
		this->renderChildren(window);
}

void DefaultObject::receiveMessage(Package * package)
{
}

std::string DefaultObject::getName()
{
	return "Default Object";
}
