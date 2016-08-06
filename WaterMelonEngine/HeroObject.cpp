#include "HeroObject.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "ICommand.h"
#include "NormalState.h"
#include "KnockBack.h"
#include "DeadState.h"
#include "Package.h"
#include "PostOffice.h"
#include "WaterMelonEngine.h"
#include <iostream>

bool HeroObject::intersect(GameObject * object)
{
	if (object->getCollisionBox())
	{
		for (int i = 0; i < 2; ++i)
		{
			if (collisionBox[i].intersects(*object->getCollisionBox()))
				return true;
		}
	}
	return false;
}
HeroObject::HeroObject()
{
	enable();
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
	}

	collisionBox[0] = collisionBox[1] = sf::FloatRect(0, 0, TILE_SIZE, TILE_SIZE);

	normalState = std::make_shared<NormalState>(this);
	knockbackState = std::make_shared<KnockBack>(this);
	dieState = std::make_shared<DeadState>(this);

	debugBox.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	debugBox.setFillColor(sf::Color::Transparent);
	debugBox.setOutlineColor(sf::Color::Red);
	if(WaterMelonEngine::isDebug)
		debugBox.setOutlineThickness(1);

	// TODO: change state to NORMAL
	setCurrentState(NORMAL);
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
	for (int i = 0; i < 2; ++i)
	{
		collisionBox[i].left = position.x; collisionBox[i].top = position.y;
	}
	targetPos = position;
}

void HeroObject::moveBy(float x, float y)
{
	position = position + sf::Vector2f(x, y);
	moveAnimation->move(x, y);
	attackAnimation->move(x, y);
	dieAnimation->move(x, y);
	for (int i = 0; i < 2; ++i)
	{
		collisionBox[i].left += x, collisionBox[i].top += y;
	}
}

void HeroObject::update(sf::Event::EventType & type)
{
	if (isEnable && isAwake)
	{
		if (!curCommand->isDone())
			curCommand->execute();
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

		if (WaterMelonEngine::isDebug)
		{
			for (int i = 0; i < 2; ++i)
			{
				debugBox.setPosition(sf::Vector2f(collisionBox[i].left, collisionBox[i].top));
				window.draw(debugBox);
			}
		}
	}
}

void HeroObject::receiveMessage(Package * package)
{
	if (package)
	{
		if (package->get<bool>("restart"))
		{
			HP = 14;
			curActorState = NORMAL;
			setCurrentState(NORMAL);
		}
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
			//if (objBox->top > position.y)
			//	knockBackDirection = 0;
			//else if (objBox->left > position.x)
			//	knockBackDirection = 1;
			//else if (objBox->top < position.y)
			//	knockBackDirection = 2;
			//else
			//	knockBackDirection = 3;

			//// knock back action
			//curAction = (UNIT_ACTION)moveAnimation->currentTrigger();
			//moveAnimation->stop();
			//
			//switch (knockBackDirection)
			//{
			//case 0:
			//	targetPos.y -= KNOCKBACK_DISTANCE * TILE_SIZE;
			//	break;
			//case 1:
			//	targetPos.x -= KNOCKBACK_DISTANCE * TILE_SIZE;
			//	break;
			//case 2:
			//	targetPos.y += KNOCKBACK_DISTANCE * TILE_SIZE;
			//	break;
			//case 3:
			//	targetPos.x += KNOCKBACK_DISTANCE * TILE_SIZE;
			//}

			//setCurrentState(KNOCKBACK);
			Actor * temp = dynamic_cast<Actor*>(object);
			if (temp && temp->getCurrentState() != DIE_STATE)
			{
				--HP;
				if (HP < 0)
				{
					setCurrentState(DIE_STATE);
				}
				else
				{
					PackageManager * pm = PackageManager::getInstance();
					Package * p = pm->requestPackage();
					bool b = true;
					p->put<bool>("menu", &b);
					p->put<bool>("HP", &b);
					office->notifyAllObserver(p);
					pm->returnPackage(p);
					knockbackClock.restart();
				}
			}
		}
	}
	else if (curAction >= ATTACK_UP && curAction <= ATTACK_RIGHT)
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
		moveClock.restart();
	}
	curCommand->setDone(true);
}

void HeroObject::moveLeft()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY)
	{
		curAction = MOVE_LEFT;
		moveAnimation->trigger(MOVE_LEFT);
		moveBy(-HERO_MOVE_SPD, 0);
		moveClock.restart();
	}
	curCommand->setDone(true);
}

void HeroObject::moveDown()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY)
	{
		curAction = MOVE_DOWN;
		moveAnimation->trigger(MOVE_DOWN);
		moveBy(0, HERO_MOVE_SPD);
		moveClock.restart();
	}
	curCommand->setDone(true);
}

void HeroObject::moveRight()
{
	if (moveClock.getElapsedTime().asMilliseconds() > MOVE_TIME_DELAY)
	{
		curAction = MOVE_RIGHT;
		moveAnimation->trigger(MOVE_RIGHT);
		moveBy(HERO_MOVE_SPD, 0);
		moveClock.restart();
	}
	curCommand->setDone(true);
}

void HeroObject::attack()
{
	if (curAction < ATTACK)
	{
		int currentDirection = getCurrentDirection();
		curAction = (Actor::UNIT_ACTION) (ATTACK_UP + currentDirection);
		attackAnimation->trigger(ATTACK_UP + currentDirection);
		switch (currentDirection)
		{
		case 0:
			collisionBox[1].top -= TILE_SIZE;
			break;
		case 1:
			collisionBox[1].left -= TILE_SIZE;
			break;
		case 2:
			collisionBox[1].top += TILE_SIZE;
			break;
		case 3:
			collisionBox[1].left += TILE_SIZE;
		}
		attackClock.restart();
	}
	else if (curAction != DIE_ACTION)
	{
		if (attackClock.getElapsedTime().asMilliseconds() > HERO_ATTACK_SPD * 6)
		{
			curAction = (UNIT_ACTION)moveAnimation->currentTrigger();
			moveAnimation->reset();
			collisionBox[1] = collisionBox[0];
			curCommand->setDone(true);
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
		setCurrentState(NORMAL);
		curCommand->setDone(true);
		knockbackClock.restart();
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
				break;
			}
			moveClock.restart();
		}
	}
}

void HeroObject::die()
{
	if (curAction != DIE_ACTION)
	{
		curAction = DIE_ACTION;
		dieAnimation->trigger(DIE_ACTION);
		moveClock.restart();
	}
	else
	{
		if (moveClock.getElapsedTime().asMilliseconds() > DIE_TIME * 6)
		{
			curCommand->setDone(true);
			dieAnimation->stop();
			PackageManager * pm = PackageManager::getInstance();
			Package * p = pm->requestPackage();
			bool theEnd = true;
			p->put<bool>("end", &theEnd);
			office->notifyAllObserver(p);
			pm->returnPackage(p);
		}
	}
}

void HeroObject::setCurrentState(ACTOR_STATE state)
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
	case Actor::KNOCKBACK:
		curState = knockbackState;
		break;
	}
}

void HeroObject::setCurrentCommand(std::shared_ptr<IActorCommand> command)
{
	this->curCommand = command;
	this->curCommand->setDone(false);
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

void HeroObject::onEnable()
{
	HP = 14;
	setCurrentState(NORMAL);
}
