#pragma once
#include "IActorState.h"
#include <memory>
class IActorCommand;
class Actor;
class MonsterNormalState :	public IActorState
{
	std::shared_ptr<IActorCommand> goUp;
	std::shared_ptr<IActorCommand> goLeft;
	std::shared_ptr<IActorCommand> goRight;
	std::shared_ptr<IActorCommand> goDown;
public:
	MonsterNormalState(Actor * actor);
	~MonsterNormalState();

	// Inherited via IActorState
	virtual void update(sf::Event::EventType & type) override;

	// Inherited via IActorState
	virtual void receiveMessage(Package * package) override;
};

