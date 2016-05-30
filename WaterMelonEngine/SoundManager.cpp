#include "SoundManager.h"
#include <iostream>

int SoundManager::curID = 0;
std::unordered_map<int, SoundBufferCache> SoundManager::soundBuffers;
sf::Music SoundManager::music;
int SoundManager::requestID(std::string filePath)
{
	for (unsigned int i = 0; i < soundBuffers.size(); ++i)
		if (soundBuffers[i].path.compare(filePath) == 0) return i;

	sf::SoundBuffer newBuffer;
	if (newBuffer.loadFromFile(filePath))
	{
		SoundBufferCache newCache(newBuffer, filePath);
		++curID;
		soundBuffers[curID] = newCache;
	}
	return curID;
}

sf::SoundBuffer* SoundManager::requestSoundBuffer(int id)
{
	if (soundBuffers.count(id) > 0)
	{
		return &soundBuffers[id].buffer;
	}
	else
	{
		std::cout << "Invalid Id inputted in Sound Manager: " << id << "\n";
		return nullptr;
	}
}

void SoundManager::setBackgroundMusic(std::string filePath)
{
	this->music.openFromFile(filePath);
}

void SoundManager::playBackgroundMusic()
{
	this->music.play();
}

void SoundManager::stopBackgroundMusicMusic()
{
	this->music.stop();
}

void SoundManager::reset()
{
	curID = -1;
	soundBuffers.clear();
}

void SoundManager::init(int reserveCache)
{
	this->soundBuffers.reserve(reserveCache);
	reset();
}
