#include "DungeonScene.h"

#include "PostOffice.h"
#include"DungeonMapObject.h"


DungeonScene::DungeonScene()
{
	this->godObject->enable();
	this->office = new PostOffice();
	DungeonMapObject * dungeon = new DungeonMapObject();
	this->addGameObject(dungeon);
	this->office->add(dungeon);
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
