#include "DieAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Actor.h"
#include <memory>
#include <assert.h>

DieAction::DieAction(std::shared_ptr<Actor> actor)
	: IActorCommand::IActorCommand(actor)
{
	assert(actor != nullptr);
}

void DieAction::execute()
{
	actor->die();
}

bool DieAction::isDone()
{
	return done;
}

void DieAction::finished()
{
	done = true;
}
