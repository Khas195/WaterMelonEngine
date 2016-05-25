#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	virtual void onPushed() override;
	virtual void onPoped() override;
	virtual void onReturnToTop() override;
	virtual void onPressed() override;
};

