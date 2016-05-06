#include "Scene.h"


#include "WaterMelonEngine.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::update()
{
	for each (auto const& gameObject in gameObjects)
	{
		gameObject->update();
	}
}

void Scene::render(sf::RenderWindow& window)
{
	for each (auto const& gameObject in gameObjects)
	{
		gameObject->render(window);
	}
}

void Scene::setEngine(WaterMelonEngine* engine)
{
	Scene::engine = engine;
}

void Scene::addGameObject(ObjectPointer gameObject)
{
	this->gameObjects.push_back(gameObject);
}

void Scene::removeGameObject(ObjectPointer target)
{
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if (target == *it)
		{
			gameObjects.erase(it);
			return;
		}
	}
}

void Scene::onPushed()
{
	for each(auto const& gameObject in gameObjects)
	{
		gameObject->enable();
	}
}

void Scene::onPoped()
{
	for each (auto const& gameObject in gameObjects)
	{
		gameObject->disable();
	}
}

void Scene::onReturnToTop()
{
	for each (auto const& gameObject in gameObjects)
	{
		gameObject->awaken();
	}
}

void Scene::onPressed()
{
	for each (auto const& gameObject in gameObjects)
	{
		gameObject->sleep();
	}
}
