#pragma once
#include "ICommand.h"
#include <string>

class MoveUp : public IActorCommand
{
public:
	MoveUp(/*std::shared_ptr<Actor>*/ Actor* actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void setDone(bool done) override;
};

class MoveLeft : public IActorCommand
{
public:
	MoveLeft(/*std::shared_ptr<Actor>*/ Actor* actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void setDone(bool done) override;
};

class MoveDown : public IActorCommand
{
public:
	MoveDown(/*std::shared_ptr<Actor>*/ Actor* actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void setDone(bool done) override;
};

class MoveRight : public IActorCommand
{
public:
	MoveRight(/*std::shared_ptr<Actor>*/ Actor* actor);
	virtual void execute() override;

	// Inherited via IActorCommand
	virtual bool isDone() override;

	// Inherited via IActorCommand
	virtual void setDone(bool done) override;
};
