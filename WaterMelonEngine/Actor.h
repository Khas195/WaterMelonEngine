#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "Definition.h"
#include <memory>

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
		DIE_ACTION
	};
	virtual const sf::Vector2f & getPosition() = 0;
	virtual void setPosition(sf::Vector2f position) = 0;

	virtual void moveUp() = 0;
	virtual void moveLeft() = 0;
	virtual void moveDown() = 0;
	virtual void moveRight() = 0;
	virtual void attack() = 0;
	virtual void knockBack() = 0;
	virtual void die() = 0;

	virtual void setCurrentState(ACTOR_STATE state) = 0;
	virtual void setCurrentAction(UNIT_ACTION action) = 0;
	virtual void setCurrentCommand(std::shared_ptr<IActorCommand> command) = 0;

	virtual int getCurrentDirection() = 0; /*	0 - UP
												1 - LEFT
												2 - DOWN
												3 - RIGHT	*/
	virtual ACTOR_STATE getCurrentState() = 0;
	virtual UNIT_ACTION getCurrentAction() = 0;
	virtual const std::shared_ptr<IActorCommand> getCurrentCommand() = 0;
protected:
	std::shared_ptr<IActorCommand> curCommand;
	std::shared_ptr<IActorState> curState;
	UNIT_ACTION curAction;
	ACTOR_STATE curActorState;
};