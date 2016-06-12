#include "NormalState.h"
#include "SFML\Graphics.hpp"
#include "Actor.h"
#include "Package.h"
#include "MoveAction.h"
#include "AttackAction.h"
NormalState::NormalState(Actor * actor) : IActorState::IActorState(actor)
{
	goUp = std::make_shared<MoveUp>(actor);
	goDown = std::make_shared<MoveDown>(actor);
	goLeft = std::make_shared<MoveLeft>(actor);
	goRight = std::make_shared<MoveRight>(actor);
	attack = std::make_shared<AttackAction>(actor);
	curActor->setCurrentCommand(goRight);
	curActor->getCurrentCommand()->setDone(true);
}


NormalState::~NormalState()
{

}

void NormalState::update(sf::Event::EventType & type)
{
	if (curActor->getCurrentCommand()->isDone())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			curActor->setCurrentCommand(goUp);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			curActor->setCurrentCommand(goLeft);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			curActor->setCurrentCommand(goRight);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			curActor->setCurrentCommand(goDown);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			curActor->setCurrentCommand(attack);
		}
	}
}

void NormalState::receiveMessage(Package * package)
{
}

