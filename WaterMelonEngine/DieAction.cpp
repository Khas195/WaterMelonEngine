#include "DieAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include <assert.h>


DieAction::DieAction(std::string source)
{
	millisecondPerFrame = DIE_TIME;
	currentAct = IDLE;
	int dieId = TextureManager::requestID(source);

	act = new Animation();

	Sprite sprite(TextureManager::requestTexture(dieId), sf::Vector2f(64, 64), sf::Vector2u(6, 1));
	sprite.setScale(TILE_SIZE * 1.0f / 64, TILE_SIZE * 1.0f / 64);
	sprite.setTimePerFrame(DIE_TIME / 1000.0f);

	sprite.setFixedRow(0);
	act->set(DIE, sprite);
}

UNIT_ACTION DieAction::action(UNIT_ACTION action)
{
	assert(action == DIE);
	act->trigger(action);
	return DIE;
}
