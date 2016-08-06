#include "ICommand.h"
#include "Actor.h"
#include <memory>

IActorCommand::IActorCommand(/*std::shared_ptr<Actor>*/ Actor* actor)
	: actor(actor)
{
}
