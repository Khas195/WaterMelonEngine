#pragma once
#include "IActorState.h"
class IActorCommand;
class KnockBack : public IActorState
{
	std::shared_ptr<IActorCommand> knockBack;
public:
	KnockBack(std::shared_ptr<Actor> actor);
	~KnockBack();

	// Inherited via IActorState
	virtual void update(sf::Event::EventType & type) override;
	virtual void receiveMessage(Package * package) override;
};
