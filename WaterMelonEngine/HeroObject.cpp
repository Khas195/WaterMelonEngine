#include "HeroObject.h"
#include "TextureManager.h"
#include "Sprite.h"
#include <iostream>

sf::Clock attackClock;
sf::Clock dieClock;
void HeroObject::onAttack()
{
	if (attackClock.getElapsedTime().asMilliseconds() > HERO_ATTACK_SPD * 6)
	{
		isAttack = false;
	}
}

void HeroObject::onMove()
{
}

void HeroObject::onDie()
{
}

HeroObject::HeroObject()
{
	isAttack = isDie = false;

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

	move = new Animation();
	attack = new Animation();
	die = new Animation();

	dieSprite.setFixedRow(0);
	die->set(DIE, dieSprite);
	FORI(0, 4, i)
	{
		moveSprite.setFixedRow(i);
		attackSprite.setFixedRow(i);
		move->set(MOVE + i + 1, moveSprite);
		attack->set(ATTACK + i + 1, attackSprite);
	}

	collisionBox = sf::FloatRect(0, 0, 64, 64);
}


HeroObject::~HeroObject()
{
	delete move;
	delete attack;
	delete die;
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
	move->setPosition(position.x, position.y);
	attack->setPosition(position.x - 32, position.y - 32);
	die->setPosition(position.x, position.y);
	collisionBox.left = position.x, collisionBox.top = position.y;
}

void HeroObject::moveBy(float x, float y)
{
	position = position + sf::Vector2f(x, y);
	move->move(x, y);
	attack->move(x, y);
	die->move(x, y);
	collisionBox.left += x, collisionBox.top += y;
}

void HeroObject::update(sf::Event::EventType & type)
{
	std::cout << "Hero: " << position.x << " - " << position.y << std::endl;
	if (isDie)
		onDie();
	else if (isAttack)
		onAttack();
	else
	{

		move->stop();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			move->trigger(MOVE_UP);
			moveBy(0, -HERO_MOVE_SPD);
			move->go();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			move->trigger(MOVE_LEFT);
			moveBy(-HERO_MOVE_SPD, 0);
			move->go();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			move->trigger(MOVE_DOWN);
			moveBy(0, HERO_MOVE_SPD);
			move->go();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			move->trigger(MOVE_RIGHT);
			moveBy(HERO_MOVE_SPD, 0);
			move->go();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			isAttack = true;
			attack->trigger(move->currentTrigger() + ATTACK - MOVE);
			attack->go();
			attackClock.restart();
		}
	}
}

void HeroObject::render(sf::RenderWindow & window)
{
	if (isDie)
		die->render(window);
	else if (isAttack)
		attack->render(window);
	else
		move->render(window);
}

void HeroObject::receiveMessage(Package * package)
{
}

std::string HeroObject::getName()
{
	return "Bald Scalp";
}
