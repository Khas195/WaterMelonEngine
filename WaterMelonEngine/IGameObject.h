#pragma once
#include "INode.h"
#include <string>
class IGameObject : public INode
{
public:
	IGameObject();
	virtual ~IGameObject();
	virtual std::string getName() override;
};

