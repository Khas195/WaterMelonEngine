#pragma once
#include "Scene.h"

class DungeonScene : public Scene
{
public:
	DungeonScene();
	~DungeonScene();

	virtual void onPushed() override;
	virtual void onPoped() override;
	virtual void onReturnToTop() override;
	virtual void onPressed() override;
};