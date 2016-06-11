#pragma once
#include "ICommand.h"
#include <string>

class Actor;
class DieAction : IActorCommand
{
public:
	DieAction(Actor * actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};

