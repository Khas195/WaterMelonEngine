#include "AttackAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Actor.h"
#include <assert.h>


AttackAction::AttackAction(Actor * actor)
	: ICommand::ICommand(actor)
{
	assert(actor != nullptr);
}

void AttackAction::execute()
{
	actor->attack();
}
