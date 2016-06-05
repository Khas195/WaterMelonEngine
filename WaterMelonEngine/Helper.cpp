#include "Helper.h"
#include "Tile.h"
#include "TileSet.h"
//#include "TileLayer.h"
#include "TextureManager.h"
#include <rapidxml\rapidxml.hpp>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>

std::vector<std::string> & split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> Helper::strsplit(const std::string & s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

TileMap * Helper::LoadMapFromSource(std::string source, std::string name)
{
	std::string parentFolder = source.substr(0, source.find_last_of("/") + 1);

	// TileMap value hold here
	sf::Uint32 MapWidth;
	sf::Uint32 MapHeight;
	sf::Uint32 TileWidth;
	sf::Uint32 TileHeight;

	// parse value from file
	std::cout << "Load map from path: " << source << std::endl;
	rapidxml::xml_document<> doc;
	rapidxml::xml_node<> * root;

	// read xml file
	std::ifstream mapFile(source.c_str());
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

	TileMap * result = new TileMap(name, source, MapWidth, MapHeight, TileWidth, TileHeight);
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

		result->tilesetList.push_back(TileSet(firstgid, tsName, tsTileWidth, tsTileHeight, state, tsPath));
		++count;
	}
	// parse map layout
	rapidxml::xml_node<> * layout = root->first_node("layer");
	rapidxml::xml_node<> * data = layout->first_node("data");
	std::string dataCSV = data->value();
	dataCSV.erase(std::remove(dataCSV.begin(), dataCSV.end(), '\n'), dataCSV.end());

	// the real parse is here
	std::vector<std::string> elems = strsplit(dataCSV, ',');

	// TODO: add layers

	return result;
}

class Path
{
	sf::Uint32 lastStep;
	Path* previousSteps;
	double totalCost, estimatedCost;
public:
	Path(sf::Uint32 lastStep, Path* previousSteps, double totalCost, double estimate)
	{
		this->lastStep = lastStep;
		this->previousSteps = previousSteps;
		this->totalCost = totalCost;
		this->estimatedCost = totalCost + estimate;
	}
	Path(sf::Uint32 start) : Path(start, NULL, 0, 0) {};
	Path* addStep(sf::Uint32 step, double stepCost, double estimate)
	{
		return new Path(step, this, totalCost + stepCost, estimate);
	}

	// get properities
	sf::Uint32 getLastStep() { return lastStep; }
	Path* getPreviousSteps() { return previousSteps; }
	double getTotalCost() { return totalCost; }

	double operator()() { return estimatedCost; }
};


std::vector<sf::Uint32> Helper::getRoad(TileMap & map, sf::Uint32 moveWidth, sf::Uint32 s, sf::Uint32 e)
{
	std::unordered_map<sf::Uint32, bool> closed;
	std::priority_queue<Path*, std::vector<Path*>, std::less<Path>> queue;
	TileLayer layer = map.layerList.back();

	Tile* start = &layer[s];
	Tile* end = &layer[e];
	if (end->state == OCCUPIED)
		return std::vector<sf::Uint32>();

	queue.push(new Path(s));

	double ex = end->position.x, ey = end->position.y;
	while (!queue.empty())
	{
		Path *p = queue.top();
		queue.pop();

		if (closed.count(p->getLastStep()))
			continue;
		if (e == p->getLastStep())
		{
			Path* cur = p, *temp;
			std::vector<sf::Uint32> path;
			// TODO generator result
			return path;
		}
		closed[p->getLastStep()] = true;

		FORIT(layer[p->getLastStep()].neighbour, n)
		{
			double move = (moveWidth + (*n)->state);
			if (move <= 0)
				continue;
			double distance = move * TILE_SIZE, nx = (*n)->position.x, ny = (*n)->position.y;
			double estimate = std::sqrt((nx - ex)*(nx - ex) + (ny - ey) * (ny - ey)) / (move * TILE_SIZE);
			Path * newP = p->addStep(*n, distance, estimate);
			queue.push(newP);
		}
	}
}
