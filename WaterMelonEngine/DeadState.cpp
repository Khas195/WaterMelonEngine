#include "DeadState.h"
#include "Actor.h"

DeadState::DeadState(std::shared_ptr<Actor> actor) : IActorState::IActorState(actor)
{
}


DeadState::~DeadState()
{
}

void DeadState::update(sf::Event::EventType & type)
{
}
