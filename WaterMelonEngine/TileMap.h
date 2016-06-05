#pragma once
#include"GameObject.h"
#include"TextureManager.h"
#include"Sprite.h"
#include"Tile.h"
#include"TileSet.h"
#include<string>
#include<unordered_map>
#include<vector>

class TileMap : public GameObject
{
	std::unordered_map<int, sf::Sprite> tileSprites;
	std::vector<TileSet> tilesets;
	std::vector<Tile> tiles;
	void reloadState();
public:
	const sf::Uint32 mapWidth;
	const sf::Uint32 mapHeight;
	const sf::Uint32 tileWidth;
	const sf::Uint32 tileHeight;
	const std::string source;
	const std::string name;

	TileMap() = default;
	TileMap(std::string name, std::string source, sf::Uint32 mapWidth, sf::Uint32 mapHeight, sf::Uint32 tileWidth, sf::Uint32 tileHeight);

	// i think A* will do
	std::vector<Tile*> getRoad(int size, sf::Uint32 start, sf::Uint32 end);
	int getGid(int x, int y);
	Tile& getTile(int x, int y);
	std::vector<Tile>& getLayout();

	// Inherited via GameObject
	virtual void update(sf::Event::EventType& type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;

	// map loader
	static TileMap * loadMap(std::string mapPath, std::string name);
};

