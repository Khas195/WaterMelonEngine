#pragma once

#include <string>
#include <vector>
#include <memory>

#include "INode.h"
#include "IGameObject.h"

class IScene : public INode
{
	std::vector<std::unique_ptr<IGameObject>> gameObjects;
public:
	IScene();
	virtual ~IScene();
	virtual void addGameObject(IGameObject* newGameObject);
	virtual void removeGameObject(IGameObject* target);
	virtual std::string getName() override;

};

