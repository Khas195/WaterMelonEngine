#pragma once
#include "SFML\Graphics.hpp"
#include <memory>
#include <assert.h>
class Actor;
class Package;
class IActorState
{
protected:
	std::shared_ptr<Actor> curActor;
public:
	IActorState(std::shared_ptr<Actor> actor) : curActor(actor)
	{ assert(actor != nullptr);  }
	virtual void update(sf::Event::EventType& type) = 0;
	virtual void receiveMessage(Package * package) = 0;
};