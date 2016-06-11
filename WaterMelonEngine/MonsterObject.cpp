#include "MonsterObject.h"
#include "TextureManager.h"
#include "HeroObject.h"
#include <iostream>

void MonsterObject::onMove()
{
}

void MonsterObject::onDie()
{
}

MonsterObject::MonsterObject(std::string source, std::string name, float movementSpeed, HeroObject * enemy)
	: enemy(enemy), movementSpeed(movementSpeed)
{
	isDie = false;
	int moveID = TextureManager::requestID(source + name + "_move.png");
	int dieID = TextureManager::requestID(source + name + "_die.png");
	Sprite moveSp(TextureManager::requestTexture(moveID), sf::Vector2f(64, 64), sf::Vector2u(9, 4));
	Sprite dieSp(TextureManager::requestTexture(dieID), sf::Vector2f(64, 64), sf::Vector2u(6, 4));

	moveSp.setScale(TILE_SIZE / 64.0f, TILE_SIZE / 64.0f);
	dieSp.setScale(TILE_SIZE / 64.0f, TILE_SIZE / 64.0f);

	moveSp.setTimePerFrame(MOVE_TIME / 1000.f);

	move = new Animation();
	die = new Animation();
	
	dieSp.setFixedRow(0);
	die->set(Actor::DIE_ACTION, dieSp);
	FORI(0, 4, i)
	{
		moveSp.setFixedRow(i);
		move->set(Actor::MOVE_UP + i, moveSp);
	}
}

MonsterObject::~MonsterObject()
{
	delete move;
	delete die;
}

const sf::FloatRect & MonsterObject::getCollisionBox()
{
	return collisionBox;
}

const sf::Vector2f & MonsterObject::getPosition()
{
	return position;
}

void MonsterObject::setPosition(sf::Vector2f position)
{
	this->position = position;
	move->setPosition(position.x, position.y);
	die->setPosition(position.x, position.y);
}

void MonsterObject::moveBy(float x, float y)
{
	position.x += x, position.y += y;
	move->move(x, y);
	die->move(x, y);
}

void MonsterObject::update(sf::Event::EventType & type)
{
	std::cout << "Monter: " << position.x << " - " << position.y << std::endl;
	if (isDie)
	{
		onDie();
	}
	else
	{
		sf::Vector2f enemyPos = enemy->getPosition();
		if (enemyPos.x - position.x < 0)
		{
			move->trigger(Actor::MOVE_LEFT);
			moveBy(-movementSpeed, 0);
		}
		else if (enemyPos.x - position.x > 0)
		{
			move->trigger(Actor::MOVE_RIGHT);
			moveBy(movementSpeed, 0);
		}
		if (enemyPos.y - position.y < 0)
		{
			move->trigger(Actor::MOVE_UP);
			moveBy(0, -movementSpeed);
		}
		else if (enemyPos.y - position.y > 0)
		{
			move->trigger(Actor::MOVE_DOWN);
			moveBy(0, movementSpeed);
		}
	}
}

void MonsterObject::render(sf::RenderWindow & window)
{
	if (isDie)
	{
		die->render(window);
	}
	else
	{
		move->render(window);
	}
}

void MonsterObject::receiveMessage(Package * package)
{
}

std::string MonsterObject::getName()
{
	return std::string();
}
