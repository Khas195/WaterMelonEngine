#include "TextureManager.h"



int TextureManager::loadFromFile(std::string filePath)
{
	//path_to_id[filePath] = curId;
	//tex_dictionary[curId].loadFromFile(filePath);
	//return curId++;
	return 0;
}


void TextureManager::init()
{
	// init
	curId = 0;
	path_to_id.reserve(20);
	tex_dictionary.reserve(20);
}

int TextureManager::requestID(std::string filePath)
{
	if (path_to_id.find(filePath) != path_to_id.end())
	{
		return path_to_id[filePath];
	}
	else
	{
		return loadFromFile(filePath);
	}
}

sf::Texture& TextureManager::requestTexture(int id)
{
	if (tex_dictionary.find(id) != tex_dictionary.end())
		return tex_dictionary[id];
	else
		return sf::Texture();
}

void TextureManager::reset()
{
	//// clear
	//path_to_id.clear();
	//tex_dictionary.clear();
	//// init
	//curId = 0;
	//path_to_id.reserve(20);
	//tex_dictionary.reserve(20);
}
