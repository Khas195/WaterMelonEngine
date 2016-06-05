#include "TextureManager.h"

int TextureManager::curId = 0;
std::unordered_map<std::string, int> TextureManager::path_to_id;
std::unordered_map<int, sf::Texture> TextureManager::tex_dictionary;

int TextureManager::loadFromFile(std::string filePath)
{
	sf::Texture tex;
	tex.loadFromFile(filePath);
	path_to_id[filePath] = curId;
	tex_dictionary[curId] = tex;
	++curId;
	return curId - 1;
}

void TextureManager::init()
{
	// clear
	path_to_id.clear();
	tex_dictionary.clear();

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
