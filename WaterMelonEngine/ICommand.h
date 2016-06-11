#pragma once
#include <SFML\Graphics.hpp>
#include "Definition.h"
#include "Animation.h"

class Actor;
class IActorCommand
{
protected:
	bool done;
	Actor * actor;
public:
	IActorCommand(Actor * actor);
	virtual void execute() = 0;
	virtual bool isDone() = 0;
	virtual void finished() = 0;
};