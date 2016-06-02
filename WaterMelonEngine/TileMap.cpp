#include"TileMap.h"
#include"Definition.h"
#include "WaterMelonEngine.h"
#include<stdio.h>
#include<iostream>
#include<queue>
#include<math.h>
#include<fstream>
#include<streambuf>
#include<sstream>
#include<algorithm>
#include<rapidxml\rapidxml.hpp>

class Path
{
	friend class PathCompare;
	Tile* lastStep;
	Path* previousSteps;
	double totalCost, estimateCost;
public:
	Path(Tile* lastStep, Path* previousSteps, double totalCost, double estimate)
	{
		this->lastStep = lastStep;
		this->previousSteps = previousSteps;
		this->totalCost = totalCost;
		this->estimateCost = totalCost + estimate;
	}
	Path(Tile* start) : Path(start, NULL, 0, 0) {};
	Path* addStep(Tile* step, double stepCost, double estimate)
	{
		return new Path(step, this, totalCost + stepCost, estimate);
	}
	// get function
	Tile* getLastStep() { return lastStep; }
	Path* getPreviousSteps() { return previousSteps; }
	double getTotalCost() { return totalCost; }
};

class PathCompare
{
public:
	PathCompare() = default;
	bool operator() (const Path* lhs, const Path* rhs) const
	{
		return lhs->estimateCost > rhs->estimateCost;
	}
};

sf::RectangleShape rect;

std::vector<std::string> stringSplit(std::string input, char delimiter[])
{
	std::vector<std::string> result;
	char* tok = strtok(&input[0], delimiter);
	while (tok != NULL)
	{
		result.push_back(tok);
		tok = strtok(NULL, delimiter);
	}
	return result;
}

TileMap::TileMap(std::string name, std::string source, sf::Uint32 mapWidth, sf::Uint32 mapHeight, sf::Uint32 tileWidth, sf::Uint32 tileHeight)
	: name(name), source(source), mapWidth(mapWidth), mapHeight(mapHeight), tileWidth(tileWidth), tileHeight(tileHeight)
{
	rect.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
	rect.setOutlineThickness(1);

	tiles.resize(mapWidth * mapHeight);
	float offset = (SCREEN_WIDTH - mapWidth * TILE_SIZE) / 2.0f;
	FORI(0, mapHeight, h)
	{
		FORI(0, mapWidth, w)
		{
			sf::Vector2f postion(offset + w * TILE_SIZE, h * TILE_SIZE);
			sf::Vector2f size(TILE_SIZE, TILE_SIZE);
			tiles[w + (h * mapWidth)].position = postion;
			tiles[w + (h * mapWidth)].box = sf::Rect<float>(postion, size);
			if (w > 0)
				tiles[w + (h * mapWidth)].neighbour.push_back(&tiles[w - 1 + (h * mapWidth)]);
			if (w < mapWidth - 1)
				tiles[w + (h * mapWidth)].neighbour.push_back(&tiles[w + 1 + (h * mapWidth)]);
			if (h > 0)
				tiles[w + (h * mapWidth)].neighbour.push_back(&tiles[w + ((h - 1) * mapWidth)]);
			if (h < mapHeight - 1)
				tiles[w + (h * mapWidth)].neighbour.push_back(&tiles[w + ((h + 1) * mapWidth)]);
		}
	}
}

std::vector<Tile*> TileMap::getRoad(int size, sf::Uint32 s, sf::Uint32 e)
{
	std::unordered_map<Tile*, bool> closed;
	std::priority_queue<Path*, std::vector<Path*>, PathCompare> queue;

	Tile* start = &tiles[s];
	Tile* end = &tiles[e];
	if (end->state == OCCUPIED)
		return std::vector<Tile*>();

	queue.push(new Path(start));

	double ex = end->position.x, ey = end->position.y;
	while (!queue.empty())
	{
		Path *p = queue.top();
		queue.pop();

		if (closed.count(p->getLastStep()))
			continue;
		if (end == p->getLastStep())
		{
			Path* cur = p, *temp;
			std::vector<Tile*> path;
			while (cur != NULL)
			{
				path.push_back(cur->getLastStep());
				temp = cur;
				cur = cur->getPreviousSteps();
				delete temp;
			}
			return path;
		}
		closed[p->getLastStep()] = true;

		FORIT(p->getLastStep()->neighbour, n)
		{
			double move = (size + (*n)->state);
			if (move <= 0)
				continue;
			double distance = move * TILE_SIZE, nx = (*n)->position.x, ny = (*n)->position.y;
			double estimate = std::sqrt((nx - ex)*(nx - ex) + (ny - ey) * (ny - ey)) / (move * TILE_SIZE);
			Path * newP = p->addStep(*n, distance, estimate);
			queue.push(newP);
		}
	}
	return std::vector<Tile*>();
}

int TileMap::getGid(int x, int y)
{
	return x + (y * mapWidth);
}

Tile & TileMap::getTile(int x, int y)
{
	return tiles[getGid(x, y)];
}

std::vector<Tile>& TileMap::getLayout()
{
	return tiles;
}

void TileMap::reloadState()
{
	FORIT(tilesets, set)
	{
		if (set->state == OCCUPIED)
		{
			FORIT(tiles, tile)
			{
				if (tile->firstgid >= set->firstgid && tile->firstgid <= set->lastGrid)
				{
					if (tile->firstgid >= set->firstgid && tile->firstgid <= set->lastGrid)
						tile->state = OCCUPIED;
				}
			}
		}
	}
}

Tile* last = nullptr;
sf::Color lastColor;
void TileMap::update(sf::Event::EventType& type)
{
	if (type == sf::Event::EventType::MouseMoved)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(WaterMelonEngine::getWindow());
		FORIT(tiles, tile)
		{
			sf::Vector2i offset = mousePos - static_cast<sf::Vector2i>(tile->position);
			if (offset.x >= 0 && offset.y >= 0 && offset.x <= TILE_SIZE &&offset.y <= TILE_SIZE)
			{
				if (last != nullptr)
				{
					last->fillColor = lastColor;
				}
				lastColor = tile->fillColor;
				tile->fillColor = sf::Color(0, 255, 0, 127);
				last = &(*tile);
			}
		}
	}
}

void TileMap::render(sf::RenderWindow & window)
{
	sf::Sprite* temp;
	FORIT(tiles, tile)
	{
		// get sprite
		// lazy load! yayyyyyyyyyyy!!!!
		if (!tileSprites.count(tile->firstgid))
		{
			FORIT(tilesets, set)
			{
				if (tile->firstgid >= set->firstgid && tile->firstgid <= set->lastGrid)
				{
					int  setx = (tile->firstgid - set->firstgid) % set->tileAmountWidth, sety = (tile->firstgid - set->firstgid) / set->tileAmountWidth;
					tileSprites[tile->firstgid] = sf::Sprite(TextureManager::requestTexture(set->texId));
					tileSprites[tile->firstgid].setTextureRect(sf::IntRect(setx * set->tileWidth, sety * set->tileHeight, set->tileWidth, set->tileHeight));
					tileSprites[tile->firstgid].setScale(set->scaleFactor);
				}
			}
		}
		temp = &tileSprites[tile->firstgid];
		temp->setPosition(tile->position);
		// get rect
		rect.setPosition(tile->position);
		rect.setFillColor(tile->fillColor);

		window.draw(*temp);
		window.draw(rect);
	}
}

// wut dis?
void TileMap::receiveMessage(Package * package)
{
}

std::string TileMap::getName()
{
	return name;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

TileMap * TileMap::loadMap(std::string mapPath, std::string name)
{
	std::string parentFolder = mapPath.substr(0, mapPath.find_last_of("/") + 1);
	// TileMap value hold here
	sf::Uint32 MapWidth;
	sf::Uint32 MapHeight;
	sf::Uint32 TileWidth;
	sf::Uint32 TileHeight;

	// parse value from file
	std::cout << "Load map from path: " << mapPath << std::endl;
	rapidxml::xml_document<> doc;
	rapidxml::xml_node<> * root;
	// read xml file
	std::ifstream mapFile(mapPath.c_str());
	std::vector<char> buffer((std::istreambuf_iterator<char>(mapFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	// pass buffer to doc to start parsing
	doc.parse<0>(&buffer[0]);
	// get root
	root = doc.first_node("map");
	// get attribute of root node
	rapidxml::xml_attribute<>* attr = root->first_attribute("width");
	MapWidth = atoi(attr->value());

	attr = root->first_attribute("height");
	MapHeight = atoi(attr->value());

	attr = root->first_attribute("tilewidth");
	TileWidth = atoi(attr->value());

	attr = root->first_attribute("tileheight");
	TileHeight = atoi(attr->value());
	
	TileMap * result = new TileMap(name, mapPath, MapWidth, MapHeight, TileWidth, TileHeight);
	int count = 0;
	// parse tileset
	for (rapidxml::xml_node<> * tileset = root->first_node("tileset"); tileset; tileset = tileset->next_sibling("tileset"))
	{
		attr = tileset->first_attribute("firstgid");
		sf::Uint32 firstgid = atoi(attr->value());

		attr = tileset->first_attribute("name");
		std::string tsName = attr->value();

		attr = tileset->first_attribute("tilewidth");
		sf::Uint32 tsTileWidth = atoi(attr->value());

		attr = tileset->first_attribute("tileheight");
		sf::Uint32 tsTileHeight = atoi(attr->value());

		TILE_STATE state = FREE;
		attr = tileset->first_attribute("state");
		if (attr)
			state = static_cast<TILE_STATE>(atoi(attr->value()));

		rapidxml::xml_node<> * image = tileset->first_node("image");
		attr = image->first_attribute("source");
		std::string tsPath = parentFolder + attr->value();

		result->tilesets.push_back(TileSet(firstgid, tsName, tsTileWidth, tsTileHeight, state, tsPath));
		++count;
	}
	// parse map layout
	rapidxml::xml_node<> * layout = root->first_node("layer");
	rapidxml::xml_node<> * data = layout->first_node("data");
	std::string dataCSV = data->value();
	dataCSV.erase(std::remove(dataCSV.begin(), dataCSV.end(), '\n'), dataCSV.end());
	// the real parse is here
	std::vector<std::string> elems = split(dataCSV, ',');
	int i = 0;
	FORIT(elems, it)
	{
		if (*it != "")
		{
			sf::Uint32 firstgid = atoi(&(*it)[0]);
			result->tiles[i++].firstgid = firstgid;
		}
	}

	result->reloadState();

	return result;
}