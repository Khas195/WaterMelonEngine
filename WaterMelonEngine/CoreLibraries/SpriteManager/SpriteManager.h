#pragma once
#include"ISprite.h"
#include<string>
#include<vector>
#include<map>

#define DEFAULT_SPRITE_POOL 100

class IScence;
class SpriteManager
{
private:
	std::string scenceName;
	std::vector<ISprite> spritePool;
	std::map<int, ISprite*> spriteList;

	// load sprite
	ISprite* loadSpriteFromFile(std::string filePath);
	void loadSprite(int spriteID, std::string spriteName, std::string spritePath);
	void save();
public:
	SpriteManager();
	~SpriteManager();

	void reserve(int size);
	void reset();

	void init(std::string scenceName);
	ISprite* request(int spriteID);
};

