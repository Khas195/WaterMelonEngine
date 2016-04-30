#pragma once
#include <stack>
#include "IState.h"

class StateStack
{
	std::stack<IState*> states;
public:
	StateStack();
	~StateStack();

	void push(IState* state);
	IState* pop();
};

