#pragma once
#include "GameObject.h"
#include "Sprite.h"
class ActionButton : public GameObject
{
	Sprite buttonClicked;
	Sprite buttonNormal;
	Sprite* buttonHover;

public:
	ActionButton() = default;
	virtual ~ActionButton(){ if (buttonHover) delete buttonHover; };
	virtual void onClicked() = 0;
	virtual void onMouseHover() = 0;

};

