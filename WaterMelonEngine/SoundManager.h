#pragma once
#include "SFML\Audio.hpp"
#include <unordered_map>
#include <string>
class SoundBufferCache
{
	friend class SoundManager;
	sf::SoundBuffer buffer;
	std::string path;
public:
	SoundBufferCache() {};
	SoundBufferCache(sf::SoundBuffer newBuffer, std::string filePath) : buffer(newBuffer), path(filePath)
	{};
};
class SoundManager
{
	static int curID;
	static std::unordered_map<int, SoundBufferCache> soundBuffers;
	static sf::Music music;
public:
	int requestID(std::string filePath);
	sf::SoundBuffer* requestSoundBuffer(int id);
	void setBackgroundMusic(std::string filePath);
	void playBackgroundMusic();
	void stopBackgroundMusicMusic();
	void reset();
	void init(int resereveCache);
};

