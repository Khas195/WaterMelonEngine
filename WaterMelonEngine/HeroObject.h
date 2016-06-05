#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "SFML\Graphics.hpp"
#include "TileMap.h"

class DungeonMapObject;
class HeroObject : public GameObject
{
	friend class DungeonMapObject;
	Animation heroAction;
	sf::Rect<float> box;
	sf::RectangleShape heroRect;
public:
	static enum HERO_ACTION
	{
		MOVE_UP = 8,
		MOVE_LEFT = 9,
		MOVE_DOWN = 10,
		MOVE_RIGHT = 11,
		ATTACK_UP = 0,
		ATTACK_LEFT = 1,
		ATTACK_DOWN = 2,
		ATTACK_RIGHT = 3,
		FALL = 20
	};

	HeroObject() = default;
	HeroObject(sf::Vector2f startPosition);
	~HeroObject();

	// Inherited via GameObject
	virtual void update(sf::Event::EventType& type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

