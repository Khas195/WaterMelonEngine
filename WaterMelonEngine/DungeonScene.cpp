#include "DungeonScene.h"

#include "PostOffice.h"
#include "DungeonMapObject.h"
#include "MenuPanel.h"
#include "HeroObject.h"
#include "GameDirector.h"
#include "MonsterObject.h"
#include <vector>

DungeonScene::DungeonScene()
{
	this->godObject->enable();
	this->office = new PostOffice();
	DungeonMapObject * dungeon = new DungeonMapObject();
	MenuPanel* menu = new MenuPanel();
	HeroObject* hero = new HeroObject();
	MonsterObject * monster = new MonsterObject("./sprites/darkElf/", "rouge");
	hero->setPosition(dungeon->getMapPosition(11,7));
	monster->setPosition(dungeon->getMapPosition(2, 3));
	GameDirector *director = new GameDirector(this);


	this->addGameObject(menu);
	this->addGameObject(dungeon);
	this->addGameObject(hero);
	this->addGameObject(monster);
	this->addGameObject(director);

	this->office->add(dungeon);
	this->office->add(menu);
	this->office->add(hero);
	this->office->add(monster);
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

void DungeonScene::update(sf::Event::EventType & type)
{
	assert(godObject);
	godObject->update(type);
}
