#include "StateStack.h"
#include <assert.h>
using namespace std;

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

IState* StateStack::pop()
{
	if (!states.empty())
	{
		IState* poppedState = states.top();
		poppedState->onPoped();
		states.pop();
		if (!states.empty())
		{
			states.top()->onReturnToTop();
		}
		return poppedState;
	}
	return nullptr;
}
