#include "IScene.h"
#include "IComponent.h"
#include <assert.h>


IScene::IScene()
{
}


IScene::~IScene()
{
}

void IScene::addGameObject(IComponent* newGameObject)
{
	assert(newGameObject != nullptr);
	this->gameObjects.push_back(newGameObject);
}

void IScene::removeGameObject(IComponent* target)
{
	assert(target != nullptr);
	for (register int i = 0; i < gameObjects.size(); ++i)
	{
		if (gameObjects[i] == target)
		{
			gameObjects.erase(gameObjects.begin() + i);
			return;
		}
	}
}
