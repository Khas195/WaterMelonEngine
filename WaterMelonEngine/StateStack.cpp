#include "StateStack.h"

StateStack::StateStack()
{
}
StateStack::~StateStack()
{
}

void StateStack::push(IState* state)
{
	assert(state != nullptr);
	if (!states.empty())
	{
		states.top()->onPressed();
	}
	state->onPushed();
	states.push(state);
}
bool StateStack::isEmpty()
{
	return states.empty();
}

IState* StateStack::pop()
{
	assert(!states.empty());
	IState* poppedState = states.top();
	poppedState->onPoped();
	states.pop();
	if (!states.empty())
	{
		states.top()->onReturnToTop();
	}
	return poppedState;
}
