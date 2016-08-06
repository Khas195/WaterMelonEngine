#include "MonsterObject.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "ICommand.h"
#include "MonsterNormalState.h"
#include "KnockBack.h"
#include "DeadState.h"
#include "PostOffice.h"
#include "Package.h"
#include "PackageManager.h"
#include "WaterMelonEngine.h"
#include "HeroObject.h"
#include <iostream>

bool MonsterObject::intersect(GameObject * object)
{
	if (object->getCollisionBox())
	{
		if (collisionBox.intersects(*object->getCollisionBox()))
			return true;
	}
	return false;
}
MonsterObject::MonsterObject(std::string source, std::string name, HeroObject * hero)
	: hero(hero)
{
	enable();
	int moveID = TextureManager::requestID(source + name + "_move.png");
	int dieID = TextureManager::requestID(source + name + "_die.png");

	Sprite moveSprite(TextureManager::requestTexture(moveID), sf::Vector2f(64, 64), sf::Vector2u(9, 4));
	Sprite dieSprite(TextureManager::requestTexture(dieID), sf::Vector2f(64, 64), sf::Vector2u(6, 1));

	moveSprite.setScale(TILE_SIZE / 64.0f, TILE_SIZE / 64.0f);
	dieSprite.setScale(TILE_SIZE / 64.0f, TILE_SIZE / 64.0f);

	moveSprite.setTimePerFrame(MOVE_TIME / 1000.0f);
	dieSprite.setTimePerFrame(DIE_TIME / 1000.0f);

	moveAnimation = std::make_unique<Animation>();
	dieAnimation = std::make_unique<Animation>();

	dieSprite.setFixedRow(0);
	dieAnimation->set(DIE_ACTION, dieSprite);
	FORI(0, 4, i)
	{
		moveSprite.setFixedRow(i);
		moveAnimation->set(MOVE + i + 1, moveSprite);
	}

	collisionBox = sf::FloatRect(0, 0, TILE_SIZE, TILE_SIZE);

	normalState = std::make_shared<MonsterNormalState>(this);
	dieState = std::make_shared<DeadState>(this);

	debugBox.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	debugBox.setFillColor(sf::Color::Transparent);
	debugBox.setOutlineColor(sf::Color::Blue);
	if(WaterMelonEngine::isDebug)
		debugBox.setOutlineThickness(1);

	// TODO: change state to NORMAL
	setCurrentState(NORMAL);
}


MonsterObject::~MonsterObject()
{
}

sf::FloatRect * MonsterObject::getCollisionBox()
{
	return &collisionBox;
}

const sf::Vector2f & MonsterObject::getPosition()
{
	return position;
}

void MonsterObject::setPosition(sf::Vector2f position)
{
	this->position = position;
	moveAnimation->setPosition(position.x, position.y);
	dieAnimation->setPosition(position.x, position.y);
	collisionBox.left = position.x; collisionBox.top = position.y;
}

void MonsterObject::moveBy(float x, float y)
{
	position = position + sf::Vector2f(x, y);
	moveAnimation->move(x, y);
	dieAnimation->move(x, y);
	collisionBox.left += x, collisionBox.top += y;
}

void MonsterObject::update(sf::Event::EventType & type)
{
	if (isEnable && isAwake)
	{
		if (!curCommand->isDone())
			curCommand->execute();
		curState->update(type);
	}
}

void MonsterObject::render(sf::RenderWindow & window)
{
	if (isEnable)
	{
		if (curAction < ATTACK)
			moveAnimation->render(window);
		else if (curAction == DIE_ACTION)
			dieAnimation->render(window);

		if (WaterMelonEngine::isDebug)
		{
			debugBox.setPosition(position);
			window.draw(debugBox);
		}
	}
}

void MonsterObject::receiveMessage(Package * package)
{
	if (package)
	{
		if (package->get<bool>("end"))
			disable();
		//curState->receiveMessage(package);
	}
}

std::string MonsterObject::getName()
{
	return "Bald Scalp";
}

void MonsterObject::onCollistion(GameObject * object)
{
	MonsterObject* temp = dynamic_cast<MonsterObject*>(object);
	if (dynamic_cast<HeroObject*>(object))
	{
		setCurrentState(DIE_STATE);
	}
	else if (temp && temp->getCurrentState() != DIE_STATE)
	{
		switch (curAction)
		{
		case Actor::MOVE_UP:
			moveBy(0, HERO_MOVE_SPD);
			break;
		case Actor::MOVE_LEFT:
			moveBy(HERO_MOVE_SPD, 0);
			break;
		case Actor::MOVE_DOWN:
			moveBy(0, -HERO_MOVE_SPD);
			break;
		case Actor::MOVE_RIGHT:
			moveBy(-HERO_MOVE_SPD, 0);
		default:
			break;
		}
	}
}

void MonsterObject::moveUp()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY * 2)
	{
		curAction = MOVE_UP;
		moveAnimation->trigger(MOVE_UP);
		moveBy(0, -HERO_MOVE_SPD);
		moveClock.restart();
	}
	curCommand->setDone(true);
}

void MonsterObject::moveLeft()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY * 2)
	{
		curAction = MOVE_LEFT;
		moveAnimation->trigger(MOVE_LEFT);
		moveBy(-HERO_MOVE_SPD, 0);
		moveClock.restart();
	}
	curCommand->setDone(true);
}

void MonsterObject::moveDown()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY * 2)
	{
		curAction = MOVE_DOWN;
		moveAnimation->trigger(MOVE_DOWN);
		moveBy(0, HERO_MOVE_SPD);
		moveClock.restart();
	}
	curCommand->setDone(true);
}

void MonsterObject::moveRight()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY * 2)
	{
		curAction = MOVE_RIGHT;
		moveAnimation->trigger(MOVE_RIGHT);
		moveBy(HERO_MOVE_SPD, 0);
		moveClock.restart();
	}
	curCommand->setDone(true);
}

void MonsterObject::attack()
{
}

void MonsterObject::knockBack()
{
}

void MonsterObject::die()
{
	if (curAction != DIE_ACTION)
	{
		curAction = DIE_ACTION;
		dieAnimation->trigger(DIE_ACTION);
		moveClock.restart();		
		PackageManager * pm = PackageManager::getInstance();
		Package * p = pm->requestPackage();
		bool dead = true;
		p->put<bool>("menu", &dead);
		p->put<bool>("score", &dead);
		office->notifyAllObserver(p);
		pm->returnPackage(p);
	}
	else
	{
		if (moveClock.getElapsedTime().asMilliseconds() >= DIE_TIME * 6)
		{
			curCommand->setDone(true);
			disable();
		}
	}
}

void MonsterObject::setCurrentState(ACTOR_STATE state)
{
	curActorState = state;
	switch (state)
	{
	case Actor::NORMAL:
		curState = normalState;
		break;
	case Actor::DIE_STATE:
		curState = dieState;
		break;
	}
}

void MonsterObject::setCurrentCommand(std::shared_ptr<IActorCommand> command)
{
	this->curCommand = command;
	this->curCommand->setDone(false);
}

void MonsterObject::setCurrentAction(UNIT_ACTION action)
{
	curAction = action;
}

int MonsterObject::getCurrentDirection()
{
	return moveAnimation->currentTrigger() - MOVE_UP;
}

Actor::ACTOR_STATE MonsterObject::getCurrentState()
{
	return curActorState;
}

Actor::UNIT_ACTION MonsterObject::getCurrentAction()
{
	return curAction;
}

const std::shared_ptr<IActorCommand> MonsterObject::getCurrentCommand()
{
	return curCommand;
}

sf::Vector2f MonsterObject::getHeroPosition()
{
	return hero->getPosition();
}

void MonsterObject::onEnable()
{
	setCurrentState(NORMAL);
}
