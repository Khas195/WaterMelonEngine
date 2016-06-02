#include "DungeonMapObject.h"



DungeonMapObject::DungeonMapObject()
{
	TextureManager::reset();
	map = TileMap::loadMap("./sprites/dungeon/map/Dungeon.tmx", "Dungeon");
	hero = new HeroObject(map->getTile(3, 3).getPosition());
	addGameObject(hero);
}


DungeonMapObject::~DungeonMapObject()
{
	delete map;
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
