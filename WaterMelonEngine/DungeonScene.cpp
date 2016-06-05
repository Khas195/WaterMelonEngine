#include "DungeonScene.h"

#include "PostOffice.h"
#include "DungeonMapObject.h"
#include "MenuPanel.h"

DungeonScene::DungeonScene()
{
	this->godObject->enable();
	this->office = new PostOffice();
	DungeonMapObject * dungeon = new DungeonMapObject();
	MenuPanel* menu = new MenuPanel();
	HeroObject* hero = new HeroObject(dungeon->getMapPosition(3, 3));
	this->addGameObject(menu);
	this->addGameObject(dungeon);
	this->addGameObject(hero);
	this->office->add(dungeon);
	this->office->add(hero);
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
