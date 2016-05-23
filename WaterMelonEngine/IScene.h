#pragma once

#include <string>
#include <vector>
#include <memory>

class IComponent;
class IScene 
{
	std::vector<IComponent*> gameObjects;
public:
	IScene();
	virtual ~IScene();
	virtual void addGameObject(IComponent* newGameObject);
	virtual void removeGameObject(IComponent* target);

};

