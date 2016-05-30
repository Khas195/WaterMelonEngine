#include "Scene.h"
#include "DefaultObject.h"
Scene::Scene()
{
	godObject = new DefaultObject();
}

void Scene::addGameObject(GameObject * gameObject)
{
	assert(godObject);
	godObject->addGameObject(gameObject);
}

void Scene::removeGameObject(GameObject * gameObject)
{
	assert(gameObject);
	godObject->removeGameObject(gameObject);
}

void Scene::update(sf::Event::EventType& type)
{
	assert(godObject);
	godObject->update(type);
}

void Scene::render(sf::RenderWindow & window)
{
	assert(godObject);
	godObject->render(window);
}

Scene::~Scene()
{
	delete godObject;
}

void Scene::receiveMessage(Package * package)
{
}
