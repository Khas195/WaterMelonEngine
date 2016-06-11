#include "DungeonScene.h"

#include "PostOffice.h"
#include "DungeonMapObject.h"
#include "MenuPanel.h"
#include "HeroObject.h"
#include "MonsterObject.h"

DungeonScene::DungeonScene()
{
	this->godObject->enable();
	this->office = new PostOffice();
	DungeonMapObject * dungeon = new DungeonMapObject();
	MenuPanel* menu = new MenuPanel();
	HeroObject* hero = new HeroObject();
	MonsterObject * monster = new MonsterObject("./sprites/darkElf/", "rouge", MONSTER_MOVE_SPD_MIN, hero);
	hero->setPosition(sf::Vector2f(300, 300));
	monster->setPosition(sf::Vector2f(100, 64));
	this->addGameObject(menu);
	this->addGameObject(dungeon);
	this->addGameObject(hero);
	this->addGameObject(monster);
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
