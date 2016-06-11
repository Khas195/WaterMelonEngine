#include "AttackAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Actor.h"
#include <assert.h>


AttackAction::AttackAction(Actor * actor)
	: IActorCommand::IActorCommand(actor)
{
	assert(actor != nullptr);
}

void AttackAction::execute()
{
	actor->attack();
}

bool AttackAction::isDone()
{
	return done;
}

void AttackAction::finished()
{
	done = true;
}
