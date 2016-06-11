#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"

class IActorState;
class IActorCommand;
class Actor : public GameObject
{
	IActorCommand * curCommand;
	IActorState * curState;
public:
	enum ACTORSTATE {
		NORMAL,
		DIE,
		KNOCKBACK
	};
	virtual void moveUp() = 0;
	virtual void moveLeft() = 0;
	virtual void moveDown() = 0;
	virtual void moveRight() = 0;
	virtual void attack() = 0;
	virtual void die() = 0;

	virtual void setCurrentState(ACTORSTATE state) = 0;
	virtual void setCurrentCommand(IActorCommand * command) = 0;
};