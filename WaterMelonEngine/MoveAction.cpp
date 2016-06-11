#include "MoveAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include <assert.h>
#include "Actor.h"

MoveUp::MoveUp(Actor * actor)
	: IActorCommand::IActorCommand(actor)
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


MoveLeft::MoveLeft(Actor * actor)
	: IActorCommand::IActorCommand(actor)
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

MoveDown::MoveDown(Actor * actor)
	: IActorCommand::IActorCommand(actor)
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

MoveRight::MoveRight(Actor * actor)
	: IActorCommand::IActorCommand(actor)
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
