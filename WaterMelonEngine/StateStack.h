#pragma once
#include <stack>
#include <assert.h>
#include <memory>

#include "IState.h"

class StateStack
{
	std::stack<IState*> states;
public:
	StateStack();
	virtual ~StateStack();

	void push(IState* state);
	bool isEmpty();
	IState* pop();
	template <typename T>
	T* getTop()
	{
		assert(!states.empty());
		T* result =  dynamic_cast<T*>(states.top());
		assert(result);
		return result;
	}
};

