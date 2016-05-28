#pragma once
#include"Sprite.h"
#include<unordered_map>
#include<string>

class Animation
{
private:
	bool run = true;

	std::string animationName;
	std::unordered_map<int, Sprite> sprite_map;
	int curID;
public:
	Animation();

	void set(int trigger, Sprite sprite);
	void trigger(int trigger);
	int currentTrigger();

	// transformation
	void move(float x, float y);

	void setPosition(float x, float y);
	sf::Vector2f getPosition();

	void setScale(float x, float y);
	sf::Vector2f getScale();

	inline void stop()
	{
		run = false;
	};
	
	inline void go()
	{
		run = true;
	};

	void update(sf::Clock& gameTime);
	void render(sf::RenderWindow& window);
	std::string getName();
};

