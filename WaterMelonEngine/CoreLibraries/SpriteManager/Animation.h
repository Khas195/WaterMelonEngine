#pragma once
#include"Sprite.h"
#include<unordered_map>
#include<string>

class Animation
{
private:
	std::string animationName;
	std::unordered_map<int, Sprite> sprite_map;
	int curID;
public:
	Animation();

	void set(int trigger, Sprite sprite);
	void trigger(int trigger);
	int currentTrigger();

	void update(sf::Clock& gameTime);
	void render(sf::RenderWindow& window);
	std::string getName();
};

