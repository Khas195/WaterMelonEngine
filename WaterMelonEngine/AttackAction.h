#pragma once
#include "ICommand.h"
#include <string>

class AttackAction : public IActorCommand
{
public:
	AttackAction(/*std::shared_ptr<Actor>*/ Actor* actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void setDone(bool done) override;
};

