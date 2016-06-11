#include "HeroObject.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "ICommand.h"
#include <iostream>

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
	}

	collisionBox = sf::FloatRect(0, 0, 64, 64);
}


HeroObject::~HeroObject()
{
}

const sf::FloatRect & HeroObject::getCollisionBox()
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
	collisionBox.left = position.x, collisionBox.top = position.y;
}

void HeroObject::moveBy(float x, float y)
{
	position = position + sf::Vector2f(x, y);
	moveAnimation->move(x, y);
	attackAnimation->move(x, y);
	dieAnimation->move(x, y);
	collisionBox.left += x, collisionBox.top += y;
}

void HeroObject::update(sf::Event::EventType & type)
{
	if (isEnable && isAwake)
	{
		//curState->update(type);
	}
}

void HeroObject::render(sf::RenderWindow & window)
{
	if (isEnable)
	{
		if (curAction - ATTACK < 0)
			moveAnimation->render(window);
		else if (curAction - DIE_ACTION < 0)
			attackAnimation->render(window);
		else if (curAction == DIE_ACTION)
			dieAnimation->render(window);
	}
}

void HeroObject::receiveMessage(Package * package)
{
}

std::string HeroObject::getName()
{
	return "Bald Scalp";
}

void HeroObject::moveUp()
{
	curAction = MOVE_UP;
	moveAnimation->trigger(MOVE_UP);
	moveBy(0, -HERO_MOVE_SPD);
}

void HeroObject::moveLeft()
{
	curAction = MOVE_LEFT;
	moveAnimation->trigger(MOVE_LEFT);
	moveBy(-HERO_MOVE_SPD, 0);
}

void HeroObject::moveDown()
{
	curAction = MOVE_DOWN;
	moveAnimation->trigger(MOVE_DOWN);
	moveBy(0, HERO_MOVE_SPD);
}

void HeroObject::moveRight()
{
	curAction = MOVE_RIGHT;
	moveAnimation->trigger(MOVE_RIGHT);
	moveBy(HERO_MOVE_SPD, 0);
}

void HeroObject::attack()
{
	curAction = (Actor::UNIT_ACTION) (ATTACK_UP + getCurrentDirection());
	attackAnimation->trigger(ATTACK_UP + getCurrentDirection());
}

void HeroObject::die()
{
	curAction = DIE_ACTION;
	dieAnimation->trigger(DIE_ACTION);
}

void HeroObject::setCurrentState(ACTOR_STATE state)
{
	// need istate
	curActorState = state;
}

void HeroObject::setCurrentCommand(std::shared_ptr<IActorCommand> command)
{
	if (curCommand->isDone())
		this->curCommand = command;
}

void HeroObject::setCurrentAnimation(UNIT_ACTION animation)
{
	curAction = animation;
}

int HeroObject::getCurrentDirection()
{
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
