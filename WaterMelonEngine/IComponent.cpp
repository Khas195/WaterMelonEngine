#include "IComponent.h"

void IComponent::updateChildren(sf::Clock & gameTime)
{
	for (IComponent* component : components)
	{
		component->update(gameTime);
	}
}

void IComponent::renderChildren(sf::RenderWindow & window)
{
	for (IComponent* component : components)
	{
		component->render(window);
	}
}
IComponent::~IComponent()
{
	while (!components.empty())
	{
		delete components.back();
		components.pop_back();
	}
}
void IComponent::enable()
{
	if (!isEnable)
	{
		onAwake();
		onEnable();
	}
	isEnable = true;
	isAwake = true;
	for (IComponent* component : components)
	{
		component->enable();
	}
}

void IComponent::disable()
{
	if (isEnable)
	{
		onSleep();
		onDisable();
	}
	isEnable = false;
	isAwake = false;
	for (IComponent* component : components)
	{
		component->disable();
	}
}

void IComponent::awake()
{
	if (!isAwake)
	{
		onAwake();
	}
	this->isAwake = true;
	for (IComponent* component : components)
	{
		component->awake();
	}
}

void IComponent::sleep()
{
	if (isAwake)
	{
		onSleep();
	}
	isAwake = false;
	for (IComponent* component : components)
	{
		component->sleep();
	}
}

void IComponent::receiveMessage(Package * package)
{
	for (IComponent* component : components)
	{
		component->receiveMessage(package);
	}
}


