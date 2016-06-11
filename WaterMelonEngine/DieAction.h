#pragma once
#include "ICommand.h"
#include <string>

class Actor;
class DieAction : ICommand
{
public:
	DieAction(Actor * actor);
	virtual void execute() override;
};

