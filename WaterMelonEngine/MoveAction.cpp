#include "MoveAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include <assert.h>
#include "Actor.h"

MoveUp::MoveUp(Actor * actor)
	: ICommand::ICommand(actor)
{
	assert(actor != nullptr);
}

void MoveUp::execute()
{
	actor->moveUp();
}

MoveLeft::MoveLeft(Actor * actor)
	: ICommand::ICommand(actor)
{
	assert(actor != nullptr);
}

void MoveLeft::execute()
{
	actor->moveLeft();
}

MoveDown::MoveDown(Actor * actor)
	: ICommand::ICommand(actor)
{
	assert(actor != nullptr);
}

void MoveDown::execute()
{
	actor->moveDown();
}

MoveRight::MoveRight(Actor * actor)
	: ICommand::ICommand(actor)
{
	assert(actor != nullptr);
}

void MoveRight::execute()
{
	actor->moveRight();
}
