#pragma once
#include "IActorState.h"
#include <memory>
class IActorCommand;
class Actor;
class NormalState :	public IActorState
{
	std::shared_ptr<IActorCommand> goUp;
	std::shared_ptr<IActorCommand> goLeft;
	std::shared_ptr<IActorCommand> goRight;
	std::shared_ptr<IActorCommand> goDown;
	std::shared_ptr<IActorCommand> attack;
public:
	NormalState(std::shared_ptr<Actor> actor);
	~NormalState();

	// Inherited via IActorState
	virtual void update(sf::Event::EventType & type) override;
};

