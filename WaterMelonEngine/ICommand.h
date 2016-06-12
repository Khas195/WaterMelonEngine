#pragma once
#include <SFML\Graphics.hpp>
#include "Definition.h"
#include <memory>

class Actor;
class IActorCommand
{
protected:
	bool done;
	/*std::shared_ptr<Actor>*/ Actor* actor;
public:
	IActorCommand(/*std::shared_ptr<Actor>*/ Actor* actor);
	virtual void execute() = 0;
	virtual bool isDone() = 0;
	virtual void setDone(bool done) = 0;
};