#pragma once
#include <SFML\Graphics.hpp>
#include "Definition.h"
#include "Animation.h"

class Actor;
class ICommand
{
protected:
	bool done;
	Actor * actor;
public:
	ICommand(Actor * actor);
	virtual void execute() = 0;
	virtual bool isDone() = 0;
};