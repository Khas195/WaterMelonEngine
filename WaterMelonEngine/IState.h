#pragma once

class IState
{
public:
	IState() = default;
	virtual ~IState() = default;
	virtual void onPushed() = 0;
	virtual void onPoped() = 0;
	virtual void onReturnToTop() = 0;
	virtual void onPressed() = 0;
};