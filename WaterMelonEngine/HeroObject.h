#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "Animation.h"
class HeroObject : public GameObject
{
	sf::Vector2f position;

	sf::FloatRect collisionBox;

	Animation * move;
	Animation * attack;
	Animation * die;

	bool isAttack;
	bool isDie;

	void onAttack();
	void onMove();
	void onDie();
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
};

