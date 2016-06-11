#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "Definition.h"

class IActorState;
class IActorCommand;
class Actor : public GameObject
{
public:
	enum ACTOR_STATE {
		NORMAL,
		DIE_STATE,
		KNOCKBACK
	};

	enum UNIT_ACTION {
		MOVE,
		MOVE_UP,
		MOVE_LEFT,
		MOVE_DOWN,
		MOVE_RIGHT,
		ATTACK,
		ATTACK_UP,
		ATTACK_LEFT,
		ATTACK_DOWN,
		ATTACK_RIGHT,
		DIE_ACTION,
		IDLE
	};

	virtual void moveUp() = 0;
	virtual void moveLeft() = 0;
	virtual void moveDown() = 0;
	virtual void moveRight() = 0;
	virtual void attack() = 0;
	virtual void die() = 0;

	virtual void setCurrentState(ACTOR_STATE state) = 0;
	virtual void setCurrentAnimation(UNIT_ACTION animation) = 0;
	virtual void setCurrentCommand(IActorCommand * command) = 0;

	virtual int getCurrentDirection() = 0; /*	0 - UP
											1 - LEFT
											2 - DOWN
											3 - RIGHT	*/
	virtual ACTOR_STATE getCurrentState() = 0;
	virtual UNIT_ACTION getCurrentAction() = 0;
protected:
	IActorCommand * curCommand;
	IActorState * curState;
	UNIT_ACTION curAction;
	ACTOR_STATE curActorState;
};