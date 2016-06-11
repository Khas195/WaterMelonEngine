#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Actor.h"
#include <memory>

class HeroObject : public Actor
{
	sf::Vector2f position;

	sf::FloatRect collisionBox;

	std::unique_ptr<Animation> moveAnimation;
	std::unique_ptr<Animation>  attackAnimation;
	std::unique_ptr<Animation>  dieAnimation;
public:
	HeroObject();
	~HeroObject();

	const sf::FloatRect & getCollisionBox();
	const sf::Vector2f & getPosition();
	void setPosition(sf::Vector2f position);
	void moveBy(float x, float y);

	// Inherited via GameObject
	virtual void update(sf::Event::EventType& type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;

	// actor
	virtual void moveUp() override;
	virtual void moveLeft() override;
	virtual void moveDown() override;
	virtual void moveRight() override;
	virtual void attack() override;
	virtual void die() override;

	virtual void setCurrentState(ACTOR_STATE state) override;
	virtual void setCurrentCommand(IActorCommand * command) override;
	virtual void setCurrentAnimation(UNIT_ACTION command) override;

	virtual int getCurrentDirection() override;
	virtual ACTOR_STATE getCurrentState() override;
	virtual UNIT_ACTION getCurrentAction() override;
};

