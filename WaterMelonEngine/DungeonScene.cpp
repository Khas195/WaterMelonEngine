#include "DungeonScene.h"

#include "PostOffice.h"
#include "Package.h"
#include "DungeonMapObject.h"
#include "MenuPanel.h"
#include "GameDirector.h"
#include "MonsterObject.h"
#include "HeroObject.h"
#include "GameObject.h"
#include <vector>

DungeonScene::DungeonScene()
{
	isEnd = true;
	monsterList.reserve(MAX_ACTORS);
	this->godObject->enable();
	this->office = new PostOffice();
	dungeon = new DungeonMapObject();
	hero = new HeroObject();
	MenuPanel* menu = new MenuPanel();
	hero->setPosition(dungeon->getMapPosition(11,7));
	spawner = dungeon->getSpawner();


	this->addGameObject(menu);
	this->addGameObject(dungeon);
	this->addGameObject(hero);

	this->office->add(this);
	this->office->add(dungeon);
	this->office->add(menu);
	this->office->add(hero);
	spawnClock.restart();
}


DungeonScene::~DungeonScene()
{
}

void DungeonScene::onPushed()
{
}

void DungeonScene::onPoped()
{
}

void DungeonScene::onReturnToTop()
{
}

void DungeonScene::onPressed()
{
}

void DungeonScene::receiveMessage(Package * package)
{
	if (package)
	{
		if (package->get<bool>("end"))
			isEnd = true;
		if (package->get<bool>("restart"))
		{
			FORIT(monsterList, monster)
			{
				(*monster)->disable();
			}
			hero->setPosition(dungeon->getMapPosition(11, 7));
			isEnd = false;
		}
	}
}

void DungeonScene::update(sf::Event::EventType & type)
{
	assert(godObject);
	if (!isEnd && spawnClock.getElapsedTime().asMilliseconds() > MONSTER_SPAWN_TIME)
	{
		sf::Vector2i tempS(rand() % MAP_WIDTH + 1, rand() % MAP_HEIGHT + 1);
		if (tempS.x == MAP_WIDTH || tempS.x == MAP_WIDTH - 1)
			tempS.x = 1;
		if (tempS.y == MAP_HEIGHT || tempS.y == MAP_HEIGHT - 1)
			tempS.y = 1;
		spawnClock.restart();
		if (monsterList.size() < MAX_ACTORS)
		{
			MonsterObject* temp = new MonsterObject("./sprites/darkElf/", "rouge", hero);
			temp->setPosition(dungeon->getMapPosition(tempS.x, tempS.y));
			monsterList.push_back(temp);
			this->addGameObject(temp);
			this->office->add(temp);
		}
		else
		{
			FORIT(monsterList, monster)
			{
				if (!(*monster)->isEnable)
				{
					(*monster)->setPosition(dungeon->getMapPosition(tempS.x, tempS.y));
					(*monster)->enable();
					break;
				}
			}
		}
	}
	godObject->update(type);
}
