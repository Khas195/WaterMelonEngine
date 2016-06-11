#include "DieAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Actor.h"
#include <assert.h>

DieAction::DieAction(Actor * actor)
	: ICommand::ICommand(actor)
{
	assert(actor != nullptr);
}

void DieAction::execute()
{
	actor->die();
}
