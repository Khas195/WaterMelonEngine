#include "KnockBack.h"
#include "Actor.h"
#include "ICommand.h"

KnockBack::KnockBack(Actor * actor) : IActorState(actor)
{
}


KnockBack::~KnockBack()
{
}

void KnockBack::update(sf::Event::EventType & type)
{
	if (curActor->getCurrentState() != curActor->KNOCKBACK)
	{
		curActor->setCurrentCommand(knockBack);
	}
	else
	{
		if (curActor->getCurrentCommand()->isDone())
		{
			curActor->setCurrentState(Actor::NORMAL);
		}
	}
}

void KnockBack::receiveMessage(Package * package)
{
}