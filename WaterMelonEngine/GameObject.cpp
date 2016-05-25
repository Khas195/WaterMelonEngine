#include "GameObject.h"

GameObject::~GameObject()
{
	while (!childObjects.empty())
	{
		delete childObjects.back();
		childObjects.pop_back();
	}
}
void GameObject::enable()
{
	if (!isEnable)
	{
		onAwake();
		onEnable();
	}
	isEnable = true;
	isAwake = true;
}
void GameObject::disable()
{
	if (isEnable)
	{
		onSleep();
		onDisable();
	}
	isEnable = false;
	isAwake = false;
}
void GameObject::sleep()
{
	if (isAwake)
	{
		onSleep();
	}
	isAwake = false;
}
void GameObject::awake()
{
	if (!isAwake)
	{
		onAwake();
	}
	isAwake = true;
}
void GameObject::updateChildren(sf::Clock & gameTime)
{
	for (GameObject* gameObject : childObjects)
	{
		gameObject->update(gameTime);
	}
}

void GameObject::renderChildren(sf::RenderWindow & window)
{
	for (GameObject* gameObject : childObjects)
	{
		gameObject->render(window);
	}
}


void GameObject::addGameObject(GameObject * gameObject)
{
	assert(gameObject);
	this->childObjects.push_back(gameObject);
};


void GameObject::removeGameObject(GameObject * target)
{
	for (int i = 0; i < childObjects.size(); ++i)
	{
		if (childObjects[i] == target)
		{
			childObjects.erase(childObjects.begin() + i);
			return;
		}
	}
	assert(false);
}


