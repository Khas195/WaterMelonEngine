#include "DungeonMapObject.h"
#include <iostream>
#include "WaterMelonEngine.h"
#include "Package.h"
#include "PackageManager.h"
#include "PostOffice.h"
#include "TextureManager.h"
#include "Helper.h"

sf::Uint32 top, left, bottom, right;

int curPath;

DungeonMapObject::DungeonMapObject()
{
	map = Helper::LoadMapFromSource("./sprites/dungeon/map/Dungeon.tmx", "Dungeon");
}


DungeonMapObject::~DungeonMapObject()
{
}

//sf::Vector2f DungeonMapObject::getMapPosition(float x, float y)
//{
//
//}
void DungeonMapObject::update(sf::Event::EventType & type)
{
	updateChildren(type);
}

void DungeonMapObject::render(sf::RenderWindow & window)
{
	map->render(window);
	renderChildren(window);
}

void DungeonMapObject::receiveMessage(Package * package)
{
}

std::string DungeonMapObject::getName()
{
	return std::string();
}
