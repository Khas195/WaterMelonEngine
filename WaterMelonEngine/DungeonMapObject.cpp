#include "DungeonMapObject.h"
#include <iostream>
#include "WaterMelonEngine.h"
#include "Package.h"
#include "PackageManager.h"
#include "PostOffice.h"

sf::Uint32 top, left, bottom, right;

int curPath;
std::vector<Tile*> path;

DungeonMapObject::DungeonMapObject()
{
	TextureManager::reset();
	map = TileMap::loadMap("./sprites/dungeon/map/Dungeon.tmx", "Dungeon");
	left = map->getTile(1, 1).getPosition().x;
	top = map->getTile(1, 1).getPosition().y;
	right = map->getTile(20, 12).getPosition().x;
	bottom = map->getTile(20, 12).getPosition().y;
}


DungeonMapObject::~DungeonMapObject()
{
	delete map;
}

sf::Vector2f DungeonMapObject::getMapPosition(float x, float y)
{
	return map->getTile(x, y).getPosition();
}

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
