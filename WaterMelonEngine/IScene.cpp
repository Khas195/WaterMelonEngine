#include "IScene.h"
#include <assert.h>


IScene::IScene()
{
}


IScene::~IScene()
{
}

void IScene::addGameObject(IGameObject* newGameObject)
{
	assert(newGameObject != nullptr);
	/*std::unique_ptr<IGameObject> gameObject;

	this->gameObjects.push_back(gameObject);*/
}

void IScene::removeGameObject(IGameObject* target)
{
	assert(target != nullptr);
}

std::string IScene::getName()
{
	return "Scene";
}
