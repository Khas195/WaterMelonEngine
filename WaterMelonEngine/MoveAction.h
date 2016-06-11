#pragma once
#include "ICommand.h"
#include <string>

class Actor;
class MoveUp : IActorCommand
{
public:
	MoveUp(Actor * actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};

class MoveLeft : IActorCommand
{
public:
	MoveLeft(Actor * actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};

class MoveDown : IActorCommand
{
public:
	MoveDown(Actor * actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};

class MoveRight : IActorCommand
{
public:
	MoveRight(Actor * actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};
