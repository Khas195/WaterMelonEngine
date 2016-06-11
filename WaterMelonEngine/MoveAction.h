#pragma once
#include "ICommand.h"
#include <string>

class Actor;
class MoveUp : ICommand
{
public:
	MoveUp(Actor * actor);
	virtual void execute() override;
};

class MoveLeft : ICommand
{
public:
	MoveLeft(Actor * actor);
	virtual void execute() override;
};

class MoveDown : ICommand
{
public:
	MoveDown(Actor * actor);
	virtual void execute() override;
};

class MoveRight : ICommand
{
public:
	MoveRight(Actor * actor);
	virtual void execute() override;
};
