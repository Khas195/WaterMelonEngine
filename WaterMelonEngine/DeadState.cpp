#include "DeadState.h"
#include "Actor.h"
#include "DieAction.h"
DeadState::DeadState(std::shared_ptr<Actor> actor) : IActorState::IActorState(actor)
{
	die = std::make_shared<DieAction>();
}


DeadState::~DeadState()
{
}

void DeadState::update(sf::Event::EventType & type)
{
	if (curActor->getCurrentState() != Actor::DIE_STATE)
	{
		curActor->setCurrentCommand(die);
	}
}
