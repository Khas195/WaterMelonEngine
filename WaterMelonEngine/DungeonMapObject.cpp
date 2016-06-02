#include "DungeonMapObject.h"
#include <iostream>


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
	//sf::Vector2f heroPos = hero->heroAction.getPosition();
	//sf::Vector2i temp((int)(heroPos.x - 48) / TILE_SIZE, (int)(heroPos.y) / TILE_SIZE);
	//std::cout << temp.x << " " << temp.y << std::endl;
	//
	//Tile tile = map->getTile(temp.x, temp.y);
	//if (tile.getState() == OCCUPIED)
	//{
	//	sf::Vector2f tilePos = tile.getPosition();
	//}
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
