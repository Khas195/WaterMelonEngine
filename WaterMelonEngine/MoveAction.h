#pragma once
#include "ICommand.h"
#include <string>

class Actor;
class MoveUp : public IActorCommand
{
public:
	MoveUp(std::shared_ptr<Actor> actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};

class MoveLeft : public IActorCommand
{
public:
	MoveLeft(std::shared_ptr<Actor> actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};

class MoveDown : public IActorCommand
{
public:
	MoveDown(std::shared_ptr<Actor> actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};

class MoveRight : public IActorCommand
{
public:
	MoveRight(std::shared_ptr<Actor> actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void finished() override;
};
