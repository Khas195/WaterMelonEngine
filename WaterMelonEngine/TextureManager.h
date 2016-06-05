#pragma once
#include"SFML\Graphics.hpp"
#include<unordered_map>
#include<string>

class TextureManager
{
private:
	static int curId;
	static std::unordered_map<std::string, int> path_to_id;
	static std::unordered_map<int, sf::Texture> tex_dictionary;

	static int loadFromFile(std::string filePath);
public:
	static int requestID(std::string filePath);
	static sf::Texture& requestTexture(int id);

	static void init();
};