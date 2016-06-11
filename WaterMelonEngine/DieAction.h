#pragma once
#include "ICommand.h"
#include <string>

class DieAction : public IActorCommand
{
public:
	DieAction(std::shared_ptr<Actor> actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};

