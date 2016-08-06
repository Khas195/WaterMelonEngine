#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Actor.h"
#include <memory>
#include <vector>

class HeroObject : public Actor
{
	int HP = 14;
	sf::RectangleShape debugBox;
	int knockBackDirection = -1;
	sf::Vector2f targetPos;
	sf::Clock attackClock, knockbackClock, moveClock;

	sf::Vector2f position;

	sf::FloatRect collisionBox[2];

	std::shared_ptr<IActorState> normalState;
	std::shared_ptr<IActorState> knockbackState;
	std::shared_ptr<IActorState> dieState;

	std::unique_ptr<Animation> moveAnimation;
	std::unique_ptr<Animation>  attackAnimation;
	std::unique_ptr<Animation>  dieAnimation;
protected:
	virtual bool intersect(GameObject * object) override;
public:
	HeroObject();
	~HeroObject();

	virtual sf::FloatRect * getCollisionBox() override;
	virtual const sf::Vector2f & getPosition() override;
	virtual void setPosition(sf::Vector2f position) override;
	void moveBy(float x, float y);

	// Inherited via GameObject
	virtual void update(sf::Event::EventType& type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;


	virtual void onCollistion(GameObject * object) override;

	// actor
	virtual void moveUp() override;
	virtual void moveLeft() override;
	virtual void moveDown() override;
	virtual void moveRight() override;
	virtual void attack() override;
	virtual void knockBack() override;
	virtual void die() override;

	virtual void setCurrentState(ACTOR_STATE state) override;
	virtual void setCurrentCommand(std::shared_ptr<IActorCommand> command) override;
	virtual void setCurrentAction(UNIT_ACTION action) override;

	virtual int getCurrentDirection() override;
	virtual ACTOR_STATE getCurrentState() override;
	virtual UNIT_ACTION getCurrentAction() override;
	virtual const std::shared_ptr<IActorCommand> getCurrentCommand() override;

	virtual void onEnable() override;
};

