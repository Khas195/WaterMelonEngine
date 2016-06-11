#include "ICommand.h"
#include "Actor.h"
#include <memory>

IActorCommand::IActorCommand(std::shared_ptr<Actor> actor)
	: actor(actor)
{
}
