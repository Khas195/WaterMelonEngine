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

	int loadFromFile(std::string filePath);
protected:
	int requestID(std::string filePath);
	sf::Texture& requestTexture(int id);

	void reset();
	void init();
};