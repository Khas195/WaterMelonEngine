#include "StateStack.h"

StateStack::StateStack()
{
}
StateStack::~StateStack()
{
}

void StateStack::push(std::shared_ptr<IState> state)
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

std::shared_ptr<IState> StateStack::pop()
{
	assert(!states.empty());
	std::shared_ptr<IState> poppedState = states.top();
	poppedState->onPoped();
	states.pop();
	if (!states.empty())
	{
		states.top()->onReturnToTop();
	}
	return poppedState;
}

std::shared_ptr<IState> StateStack::getTop()
{
	assert(!states.empty());
	return states.top();
}
