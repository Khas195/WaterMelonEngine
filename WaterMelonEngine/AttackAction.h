#pragma once
#include "ICommand.h"
#include <string>
class AttackAction : ICommand
{
public:
	AttackAction(Actor * actor);
	virtual void execute() override;
};

