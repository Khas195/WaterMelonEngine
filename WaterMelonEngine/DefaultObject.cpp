#include "DefaultObject.h"

void DefaultObject::update(sf::Clock & gameTime)
{
	if (isEnable && isAwake)
		this->updateChildren(gameTime);
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
