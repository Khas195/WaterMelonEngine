#pragma once
#include "Scene.h"

class MonsterObject;
class DungeonMapObject;
class HeroObject;
class DungeonScene : public Scene
{
	bool isEnd;
	std::vector<MonsterObject*> monsterList;
	std::vector<sf::Vector2i> spawner;
	sf::Clock spawnClock;
	HeroObject* hero;
	DungeonMapObject* dungeon;
public:
	DungeonScene();
	~DungeonScene();

	virtual void onPushed() override;
	virtual void onPoped() override;
	virtual void onReturnToTop() override;
	virtual void onPressed() override;

	virtual void update(sf::Event::EventType& type) override;
	virtual void receiveMessage(Package * package) override;
};