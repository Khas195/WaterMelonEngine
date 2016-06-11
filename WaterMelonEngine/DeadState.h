#pragma once
#include "IActorState.h"
class DeadState : public IActorState
{
public:
	DeadState(std::shared_ptr<Actor> actor);
	~DeadState();

	// Inherited via IActorState
	virtual void update(sf::Event::EventType & type) override;
};

