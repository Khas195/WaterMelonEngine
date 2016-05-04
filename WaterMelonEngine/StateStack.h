#pragma once
#include <stack>
#include <assert.h>
#include <memory>

#include "IState.h"

class StateStack
{
	std::stack<std::shared_ptr<IState>> states;
public:
	StateStack();
	~StateStack();

	void push(std::shared_ptr<IState> state);
	bool isEmpty();
	std::shared_ptr<IState> pop();
	std::shared_ptr<IState> getTop();

};

