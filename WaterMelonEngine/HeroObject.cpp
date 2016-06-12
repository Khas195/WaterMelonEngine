#include "HeroObject.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "ICommand.h"
#include "IActorState.h"
#include "Package.h"
#include <iostream>

int knockBackDirection = -1;
sf::Vector2f targetPos;
sf::Clock attackClock, knockbackClock, moveClock;
bool HeroObject::intersect(GameObject * object)
{
	if (object->getCollisionBox())
	{
		FOREACH(collisionBox, box)
		{
			if (box.intersects(*object->getCollisionBox()))
				return true;
		}
	}
	return false;
}
HeroObject::HeroObject()
{
	int moveID = TextureManager::requestID("./sprites/hero_move.png");
	int attackID = TextureManager::requestID("./sprites/hero_attack.png");
	int dieID = TextureManager::requestID("./sprites/hero_die.png");

	Sprite moveSprite(TextureManager::requestTexture(moveID), sf::Vector2f(64, 64), sf::Vector2u(9, 4));
	Sprite attackSprite(TextureManager::requestTexture(attackID), sf::Vector2f(192, 192), sf::Vector2u(6, 4));
	Sprite dieSprite(TextureManager::requestTexture(dieID), sf::Vector2f(64, 64), sf::Vector2u(6, 1));

	moveSprite.setScale(TILE_SIZE / 64.0f, TILE_SIZE / 64.0f);
	attackSprite.setScale(TILE_SIZE / 64.0f, TILE_SIZE / 64.0f);
	dieSprite.setScale(TILE_SIZE / 64.0f, TILE_SIZE / 64.0f);

	moveSprite.setTimePerFrame(MOVE_TIME / 1000.0f);
	attackSprite.setTimePerFrame(HERO_ATTACK_SPD / 1000.0f);
	dieSprite.setTimePerFrame(DIE_TIME / 1000.0f);

	attackSprite.move(-32, -32);

	moveAnimation = std::make_unique<Animation>();
	attackAnimation = std::make_unique<Animation>();
	dieAnimation = std::make_unique<Animation>();

	dieSprite.setFixedRow(0);
	dieAnimation->set(DIE_ACTION, dieSprite);
	FORI(0, 4, i)
	{
		moveSprite.setFixedRow(i);
		attackSprite.setFixedRow(i);
		moveAnimation->set(MOVE + i + 1, moveSprite);
		attackAnimation->set(ATTACK + i + 1, attackSprite);

		collisionBox[i] = sf::FloatRect(0, 0, TILE_SIZE, TILE_SIZE);
	}

	// TODO: change state to NORMAL
}


HeroObject::~HeroObject()
{
}

sf::FloatRect * HeroObject::getCollisionBox()
{
	return collisionBox;
}

const sf::Vector2f & HeroObject::getPosition()
{
	return position;
}

void HeroObject::setPosition(sf::Vector2f position)
{
	this->position = position;
	moveAnimation->setPosition(position.x, position.y);
	attackAnimation->setPosition(position.x - 32, position.y - 32);
	dieAnimation->setPosition(position.x, position.y);
	FOREACH(collisionBox, box)
	{
		box.left = position.x, box.top = position.y;
	}
	targetPos = position;
}

void HeroObject::moveBy(float x, float y)
{
	position = position + sf::Vector2f(x, y);
	moveAnimation->move(x, y);
	attackAnimation->move(x, y);
	dieAnimation->move(x, y);
	FOREACH(collisionBox, box)
	{
		box.left += x, box.top += y;
	}
}

void HeroObject::update(sf::Event::EventType & type)
{
	if (isEnable && isAwake)
	{
		curState->update(type);
	}
}

void HeroObject::render(sf::RenderWindow & window)
{
	if (isEnable)
	{
		if (curAction < ATTACK)
			moveAnimation->render(window);
		else if (curAction < DIE_ACTION)
			attackAnimation->render(window);
		else if (curAction == DIE_ACTION)
			dieAnimation->render(window);
	}
}

void HeroObject::receiveMessage(Package * package)
{
	if (package)
	{
		curState->receiveMessage(package);
	}
}

std::string HeroObject::getName()
{
	return "Bald Scalp";
}

void HeroObject::onCollistion(GameObject * object)
{
	sf::FloatRect* objBox = object->getCollisionBox();

	if (collisionBox[0].intersects(*objBox))
	{
		if (knockbackClock.getElapsedTime().asSeconds() > 2)
		{
			if (objBox->top > collisionBox[0].top)
				knockBackDirection = 0;
			else if (objBox->left > collisionBox[0].left)
				knockBackDirection = 1;
			else if (objBox->top < collisionBox[0].top)
				knockBackDirection = 2;
			else
				knockBackDirection = 3;

			// knock back action
			curActorState = KNOCKBACK;
			curAction = (UNIT_ACTION)moveAnimation->currentTrigger();
			moveAnimation->stop();
			
			switch (knockBackDirection)
			{
			case 0:
				targetPos.y -= KNOCKBACK_DISTANCE * TILE_SIZE;
				break;
			case 1:
				targetPos.x -= KNOCKBACK_DISTANCE * TILE_SIZE;
				break;
			case 2:
				targetPos.y += KNOCKBACK_DISTANCE * TILE_SIZE;
				break;
			case 3:
				targetPos.x += KNOCKBACK_DISTANCE * TILE_SIZE;
			}
			//TODO: change state to knockback state
			knockbackClock.restart();
		}
	}
	else if (curAction == ATTACK)
	{
		object->onCollistion(this);
	}
}

void HeroObject::moveUp()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY)
	{
		curAction = MOVE_UP;
		moveAnimation->trigger(MOVE_UP);
		moveBy(0, -HERO_MOVE_SPD);
	}
	curCommand->finished();
}

void HeroObject::moveLeft()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY)
	{
		curAction = MOVE_LEFT;
		moveAnimation->trigger(MOVE_LEFT);
		moveBy(-HERO_MOVE_SPD, 0);
	}
	curCommand->finished();
}

void HeroObject::moveDown()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY)
	{
		curAction = MOVE_DOWN;
		moveAnimation->trigger(MOVE_DOWN);
		moveBy(0, HERO_MOVE_SPD);
	}
	curCommand->finished();
}

void HeroObject::moveRight()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY)
	{
		curAction = MOVE_RIGHT;
		moveAnimation->trigger(MOVE_RIGHT);
		moveBy(HERO_MOVE_SPD, 0);
	}
	curCommand->finished();
}

void HeroObject::attack()
{
	if (curAction < ATTACK)
	{
		int currentDirection = getCurrentDirection();
		curAction = (Actor::UNIT_ACTION) (ATTACK_UP + currentDirection);
		attackAnimation->trigger(ATTACK_UP + currentDirection);
		FORI(1, 4, i)
		{
			switch (currentDirection)
			{
			case 0:
				collisionBox[i].top += TILE_SIZE;
				collisionBox[i].left += (i - 2) * TILE_SIZE;
				break;
			case 1:
				collisionBox[i].top += (i - 2) * TILE_SIZE;
				collisionBox[i].left -= TILE_SIZE;
				break;
			case 2:
				collisionBox[i].top -= TILE_SIZE;
				collisionBox[i].left += (i - 2) * TILE_SIZE;
				break;
			case 3:
				collisionBox[i].top += (i - 2) * TILE_SIZE;
				collisionBox[i].left += TILE_SIZE;
			}
		}
		attackClock.restart();
	}
	else if (curAction != DIE_ACTION)
	{
		if (attackClock.getElapsedTime().asMilliseconds() > HERO_ATTACK_SPD * 6)
		{
			curAction = (UNIT_ACTION)moveAnimation->currentTrigger();
			moveAnimation->reset();
			FORI(0, 4, i)
			{
				collisionBox[i].top = position.y, collisionBox[i].left = position.x;
			}
			curCommand->finished();
		}
	}
}

void HeroObject::knockBack()
{
	if (targetPos == position)
	{
		curActorState = NORMAL;
		moveAnimation->go();
		knockBackDirection = -1;
		// TODO: change state to NORMAL
		curCommand->finished();
	}
	else
	{
		if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY / 2)
		{
			switch (knockBackDirection)
			{
			case 0:
				moveBy(0, -HERO_MOVE_SPD);
				break;
			case 1:
				moveBy(-HERO_MOVE_SPD, 0);
				break;
			case 2:
				moveBy(0, HERO_MOVE_SPD);
				break;
			case 3:
				moveBy(HERO_MOVE_SPD, 0);
				break;
			default:
			}
			moveClock.restart();
		}

	}
}

void HeroObject::die()
{
	curAction = DIE_ACTION;
	dieAnimation->trigger(DIE_ACTION);
}

void HeroObject::setCurrentState(ACTOR_STATE state)
{
	// TODO: need states
	curActorState = state;
}

void HeroObject::setCurrentCommand(std::shared_ptr<IActorCommand> command)
{
	this->curCommand = command;
}

void HeroObject::setCurrentAction(UNIT_ACTION action)
{
	curAction = action;
}

int HeroObject::getCurrentDirection()
{
	if (knockBackDirection != -1)
		return knockBackDirection;
	return moveAnimation->currentTrigger() - MOVE_UP;
}

Actor::ACTOR_STATE HeroObject::getCurrentState()
{
	return curActorState;
}

Actor::UNIT_ACTION HeroObject::getCurrentAction()
{
	return curAction;
}

const std::shared_ptr<IActorCommand> HeroObject::getCurrentCommand()
{
	return curCommand;
}
