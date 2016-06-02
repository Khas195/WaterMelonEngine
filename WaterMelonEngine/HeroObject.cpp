#include "HeroObject.h"
#include"Sprite.h"

#define MOVEMENT_SPEED 1

enum ACTION
{
	MOVE_UP = 8,
	MOVE_LEFT = 9,
	MOVE_DOWN = 10,
	MOVE_RIGHT = 11,
	ATTACK_UP = 0,
	ATTACK_LEFT = 1,
	ATTACK_DOWN = 2,
	ATTACK_RIGHT = 3,
	FALL = 21
};

ACTION currentAttack;
bool isAttacking = false;
sf::Clock attack_clock;

HeroObject::HeroObject(sf::Vector2f startPosition)
{
	int norm_id = TextureManager::requestID("./sprites/hero.png");
	int att_id = TextureManager::requestID("./sprites/hero_attack.png");
	Sprite move(TextureManager::requestTexture(norm_id), sf::Vector2f(64, 64), sf::Vector2f(9, 21));
	Sprite fall(TextureManager::requestTexture(norm_id), sf::Vector2f(64, 64), sf::Vector2f(6, 21));
	Sprite attack(TextureManager::requestTexture(att_id), sf::Vector2f(192, 192), sf::Vector2f(6, 4));

	move.setTimePerFrame(0.01f);
	fall.setTimePerFrame(0.01f);
	attack.setTimePerFrame(0.1f);

	move.setPosition(startPosition);
	fall.setPosition(startPosition);
	attack.setPosition(startPosition);
	attack.move(-32, -32);

	double scaleFactor = TILE_SIZE / 64.0f;
	move.setScale(scaleFactor, scaleFactor);
	fall.setScale(scaleFactor, scaleFactor);
	attack.setScale(scaleFactor, scaleFactor);

	for (int i = MOVE_UP; i <= MOVE_RIGHT; ++i)
	{
		move.setFixedRow(i);
		heroAction.set(i, move);
	}

	for (int i = ATTACK_UP; i <= ATTACK_RIGHT; ++i)
	{
		attack.setFixedRow(i);
		heroAction.set(i, attack);
	}

	fall.setFixedRow(FALL);
	heroAction.set(FALL, fall);
}

HeroObject::~HeroObject()
{
}

void HeroObject::update(sf::Event::EventType & type)
{
	if (isAttacking && attack_clock.getElapsedTime().asMilliseconds() > 600)
	{
		isAttacking = false;
		switch (heroAction.currentTrigger())
		{
		case ATTACK_UP:
			heroAction.trigger(MOVE_UP);
			break;
		case ATTACK_LEFT:
			heroAction.trigger(MOVE_LEFT);
			break;
		case ATTACK_DOWN:
			heroAction.trigger(MOVE_DOWN);
			break;
		case ATTACK_RIGHT:
			heroAction.trigger(MOVE_RIGHT);
			break;
		}
	}
	if (!isAttacking)
		heroAction.stop();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!isAttacking || MOVE_UP - heroAction.currentTrigger() != 8)
			heroAction.trigger(MOVE_UP);
		heroAction.move(0, -MOVEMENT_SPEED);
		heroAction.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!isAttacking || MOVE_LEFT - heroAction.currentTrigger() != 8)
			heroAction.trigger(MOVE_LEFT);
		heroAction.move(-MOVEMENT_SPEED, 0);
		heroAction.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (!isAttacking || MOVE_DOWN - heroAction.currentTrigger() != 8)
			heroAction.trigger(MOVE_DOWN);
		heroAction.move(0, MOVEMENT_SPEED);
		heroAction.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!isAttacking || MOVE_RIGHT - heroAction.currentTrigger() != 8)
			heroAction.trigger(MOVE_RIGHT);
		heroAction.move(MOVEMENT_SPEED, 0);
		heroAction.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		isAttacking = true;
		attack_clock.restart();
		switch (heroAction.currentTrigger())
		{
		case MOVE_UP:
			heroAction.trigger(ATTACK_UP);
			break;
		case MOVE_LEFT:
			heroAction.trigger(ATTACK_LEFT);
			break;
		case MOVE_DOWN:
			heroAction.trigger(ATTACK_DOWN);
			break;
		case MOVE_RIGHT:
			heroAction.trigger(ATTACK_RIGHT);
			break;
		}
		heroAction.go();
	}
}

void HeroObject::render(sf::RenderWindow & window)
{
	heroAction.render(window);
}

void HeroObject::receiveMessage(Package * package)
{
}

std::string HeroObject::getName()
{
	return std::string();
}
