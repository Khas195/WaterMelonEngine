#include "DungeonMapObject.h"
#include <iostream>
#include "WaterMelonEngine.h"
#include "Package.h"
#include "PackageManager.h"
#include "PostOffice.h"
#include "TextureManager.h"
#include "Helper.h"
#include "Actor.h"

sf::Uint32 top, left, bottom, right;

int curPath;
sf::FloatRect * collidedBox;
DungeonMapObject::DungeonMapObject()
{
	enable();
	map = Helper::LoadMapFromSource("./sprites/dungeon/map/Dungeon.tmx", "Dungeon");
	std::vector<MapTile*> temp = map->allTiles();
	FORIT(temp, tile)
	{
		if ((*tile)->getState() <= OCCUPIED)
		{
			collisionBoxList.push_back(sf::FloatRect((*tile)->getPosition(), sf::Vector2f(TILE_SIZE, TILE_SIZE)));
		}
	}
}


DungeonMapObject::~DungeonMapObject()
{
}

sf::Vector2f DungeonMapObject::getMapPosition(int x, int y)
{
	return map->getPosition(x, y);
}

void DungeonMapObject::update(sf::Event::EventType & type)
{
}

void DungeonMapObject::render(sf::RenderWindow & window)
{
	map->render(window);
}

void DungeonMapObject::receiveMessage(Package * package)
{
}

std::string DungeonMapObject::getName()
{
	return std::string();
}

bool DungeonMapObject::intersect(GameObject * object)
{
	if (object->getCollisionBox())
	{
		FORIT(collisionBoxList, box)
		{
			if (box->intersects(*object->getCollisionBox()))
				return true;
		}
	}
	return false;
}

void DungeonMapObject::onCollistion(GameObject * object)
{
	Actor* temp = dynamic_cast<Actor*>(object);
	if (temp)
	{
		sf::Vector2f pos = temp->getPosition();
		switch (temp->getCurrentAction())
		{
		case Actor::MOVE_UP:
			temp->setPosition(pos + sf::Vector2f(0, TILE_SIZE));
			break;
		case Actor::MOVE_LEFT:
			temp->setPosition(pos + sf::Vector2f(TILE_SIZE, 0));
			break;
		case Actor::MOVE_DOWN:
			temp->setPosition(pos + sf::Vector2f(0, -TILE_SIZE));
			break;
		case Actor::MOVE_RIGHT:
			temp->setPosition(pos + sf::Vector2f(-TILE_SIZE, 0));
			break;
		}
	}
}
