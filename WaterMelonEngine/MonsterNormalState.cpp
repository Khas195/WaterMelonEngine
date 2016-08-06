#include "MonsterNormalState.h"
#include "SFML\Graphics.hpp"
#include "Actor.h"
#include "Package.h"
#include "MoveAction.h"
#include "AttackAction.h"
#include "MonsterObject.h"

MonsterNormalState::MonsterNormalState(Actor * actor) : IActorState::IActorState(actor)
{
	goUp = std::make_shared<MoveUp>(actor);
	goDown = std::make_shared<MoveDown>(actor);
	goLeft = std::make_shared<MoveLeft>(actor);
	goRight = std::make_shared<MoveRight>(actor);
	curActor->setCurrentCommand(goRight);
	curActor->getCurrentCommand()->setDone(true);
}


MonsterNormalState::~MonsterNormalState()
{

}

void MonsterNormalState::update(sf::Event::EventType & type)
{
	if (curActor->getCurrentCommand()->isDone())
	{
		sf::Vector2f pos = ((MonsterObject*)curActor)->getHeroPosition();
		sf::Vector2f offset = pos - curActor->getPosition();
		if (offset.x && offset.x < offset.y || !offset.y)
		{
			if (offset.x < 0)
			{
				curActor->setCurrentCommand(goLeft);
			}
			else if (offset.x > 0)
			{
				curActor->setCurrentCommand(goRight);
			}
		}
		else
		{
			if (offset.y < 0)
			{
				curActor->setCurrentCommand(goUp);
			}
			else if (offset.y > 0)
			{
				curActor->setCurrentCommand(goDown);
			}
		}
	}
}

void MonsterNormalState::receiveMessage(Package * package)
{
}

