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

void Animation::update(sf::Clock & gameTime)
{
	if (curID != -1)
		sprite_map[curID].update(gameTime);
}

void Animation::render(sf::RenderWindow & window)
{
	if (curID != -1)
		sprite_map[curID].render(window);
}

std::string Animation::getName()
{
	return animationName;
}
