#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "Animation.h"
#include <string>

class HeroObject;
class MonsterObject : public GameObject
{
	HeroObject * enemy;

	sf::Vector2f position;

	sf::FloatRect collisionBox;

	float movementSpeed;

	Animation * move;
	//Animation * attack;
	Animation * die;

	//bool isAttack;
	bool isDie;

	//void onAttack();
	void onMove();
	void onDie();
public:
	MonsterObject(std::string source, std::string name, float movementSpeed, HeroObject * enemy);
	~MonsterObject();

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

