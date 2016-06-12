#pragma once
#include "SFML\Graphics.hpp"
#include <memory>
#include <assert.h>
class Actor;
class Package;
class IActorState
{
protected:
	///*std::shared_ptr<Actor>*/ Actor* curActor;
	Actor * curActor;
public:
	IActorState(Actor * actor) : curActor(actor)
	//IActorState(/*std::shared_ptr<Actor>*/ Actor* actor) : curActor(actor)
	{ assert(actor != nullptr);  }
	virtual void update(sf::Event::EventType& type) = 0;
	virtual void receiveMessage(Package * package) = 0;
};