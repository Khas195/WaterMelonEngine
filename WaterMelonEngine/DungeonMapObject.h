#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "Map.h"
#include "Definition.h"
#include <vector>

class Actor;
class DungeonMapObject : public GameObject
{
	Map * map;
	std::vector<sf::FloatRect> collisionBoxList;
public:
	DungeonMapObject();
	~DungeonMapObject();

	sf::Vector2f getMapPosition(int x, int y);

	std::vector<sf::Vector2i> getSpawner();
	// Inherited via GameObject
	virtual void render(sf::RenderWindow & window) override;
	virtual void update(sf::Event::EventType& type) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;

	virtual bool intersect(GameObject * object);
	virtual void onCollistion(GameObject * object);
};
