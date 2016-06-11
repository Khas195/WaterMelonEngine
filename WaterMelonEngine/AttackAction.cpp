#include "AttackAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include <assert.h>


AttackAction::AttackAction(std::string source, sf::Int32 millisecondPerFrame)
{
	this->millisecondPerFrame = millisecondPerFrame;
	currentAct = IDLE;
	int attID = TextureManager::requestID(source);
	sf::Texture tex = TextureManager::requestTexture(attID);

	act = new Animation();

	sf::Vector2u dim;
	sf::Vector2f framesize;
	if (tex.getSize().x > 384)
	{
		framesize = sf::Vector2f(192, 192);
		if (tex.getSize().x > 1152)
			dim = sf::Vector2u(6, 4);
		else
			dim = sf::Vector2u(8, 4);
	}
	else
	{
		framesize = sf::Vector2f(64, 64);
		if (tex.getSize().x > 1152)
			dim = sf::Vector2u(6, 4);
	}
	Sprite sprite(tex, framesize, dim);
	sprite.setScale(TILE_SIZE * 1.0f / framesize.x, TILE_SIZE * 1.0f / framesize.y);
	sprite.setTimePerFrame(millisecondPerFrame / 1000.0f);

	FORI(ATTACK_UP, ATTACK_RIGHT + 1, i)
	{
		sprite.setFixedRow(i - ATTACK_UP);
		act->set(i, sprite);
	}
}

UNIT_ACTION AttackAction::action(UNIT_ACTION action)
{
	assert(action >= ATTACK_UP && action <= ATTACK_DOWN);
	act->trigger(action);
	return ATTACK;
}
