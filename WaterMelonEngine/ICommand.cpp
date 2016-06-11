#include "ICommand.h"
#include <memory>

IActorCommand::IActorCommand(std::shared_ptr<Actor> actor)
	: actor(actor)
{
}
