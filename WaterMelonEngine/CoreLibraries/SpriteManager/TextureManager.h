#pragma once
#include"Sprite.h"
#include<unordered_map>
#include<string>

class TextureManager
{
private:
	 int curId;
	 std::unordered_map<std::string, int> path_to_id;
	 std::unordered_map<int, sf::Texture> tex_dictionary;

	static int loadFromFile(std::string filePath);
public:
	 void init();
	 int requestID(std::string filePath);
	 sf::Texture& requestTexture(int id);

	static void reset();
};

