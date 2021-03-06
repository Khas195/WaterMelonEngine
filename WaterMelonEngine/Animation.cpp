#include "Animation.h"



Animation::Animation()
{
	curID = -1;
}

void Animation::set(int trigger, Sprite sprite)
{
	sprite_map[trigger] = sprite;
	curID = trigger;
}

void Animation::trigger(int trigger)
{
	if (trigger == curID)
		return;
	curID = trigger;
	sprite_map[curID].reset();
}

int Animation::currentTrigger()
{
	return curID;
}
void Animation::move(float x, float y)
{
	if (curID != -1)
	{
		FORIT(sprite_map, it)
		{
			it->second.move(x, y);
		}
	}
}
void Animation::setPosition(float x, float y)
{
	if (curID != -1)
	{
		FORIT(sprite_map, it)
		{
			it->second.setPosition(x, y);
		}
	}
}
sf::Vector2f Animation::getPosition()
{
	if (curID != -1)
		return sprite_map[curID].getPosition();
	return sf::Vector2f(-1, -1);
}
void Animation::setScale(float x, float y)
{
	if (curID != -1)
	{
		FORIT(sprite_map, it)
		{
			it->second.setScale(x, y);
		}
	}
}
sf::Vector2f Animation::getScale()
{
	if (curID != -1)
		return sprite_map[curID].getScale();
}
void Animation::update(sf::Clock & gameTime)
 {
	if (curID != -1)
		sprite_map[curID].update(gameTime);
}

void Animation::render(sf::RenderWindow & window)
{

	if (curID != -1)
	{
		if (run)
			sprite_map[curID].nextFrame();
		sprite_map[curID].render(window);
	}
}

std::string Animation::getName()
{
	return animationName;
}
