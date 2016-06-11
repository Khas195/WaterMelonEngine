#pragma once
#include "IActorState.h"
#include <memory>
class IActorCommand;
class DeadState : public IActorState
{
	std::shared_ptr<IActorCommand> die;
public:
	DeadState(std::shared_ptr<Actor> actor);
	~DeadState();

	// Inherited via IActorState
	virtual void update(sf::Event::EventType & type) override;
};

