#include "MoveAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Actor.h"
#include <assert.h>

MoveUp::MoveUp(/*std::shared_ptr<Actor>*/ Actor* actor)
	: IActorCommand(actor)
{
	assert(actor != nullptr);
}

void MoveUp::execute()
{
	actor->moveUp();
}

bool MoveUp::isDone()
{
	return done;
}

void MoveUp::setDone(bool done)
{
	this->done = done;
}


MoveLeft::MoveLeft(/*std::shared_ptr<Actor>*/ Actor*actor)
	: IActorCommand(actor)
{
	assert(actor != nullptr);
}

void MoveLeft::execute()
{
	actor->moveLeft();
}

bool MoveLeft::isDone()
{
	return done;
}

void MoveLeft::setDone(bool done)
{
	this->done = done;
}

MoveDown::MoveDown(/*std::shared_ptr<Actor>*/ Actor* actor)
	: IActorCommand(actor)
{
	assert(actor != nullptr);
}

void MoveDown::execute()
{
	actor->moveDown();
}

bool MoveDown::isDone()
{
	return done;
}

void MoveDown::setDone(bool done)
{
	this->done = done;
}

MoveRight::MoveRight(/*std::shared_ptr<Actor>*/ Actor* actor)
	: IActorCommand(actor)
{
	assert(actor != nullptr);
}

void MoveRight::execute()
{
	actor->moveRight();
}

bool MoveRight::isDone()
{
	return done;
}

void MoveRight::setDone(bool done)
{
	this->done = done;
}
