#include "MoveAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Actor.h"
#include <assert.h>

MoveUp::MoveUp(std::shared_ptr<Actor> actor)
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

void MoveUp::finished()
{
	done = true;
}


MoveLeft::MoveLeft(std::shared_ptr<Actor>actor)
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

void MoveLeft::finished()
{
	done = true;
}

MoveDown::MoveDown(std::shared_ptr<Actor> actor)
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

void MoveDown::finished()
{
	done = true;
}

MoveRight::MoveRight(std::shared_ptr<Actor> actor)
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

void MoveRight::finished()
{
	done = true;
}
