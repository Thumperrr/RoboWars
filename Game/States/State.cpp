#include "State.hpp"
#include "StateStack.hpp"

State::State(StateStack& stack, Context context) :
    m_Stack(stack),
    m_Context(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
    m_Stack.pushState(stateID);
}

void State::requestStackPop()
{
    m_Stack.popState();
}

void State::requestStackClear()
{
    m_Stack.clearStates();
}

Context State::getContext() const
{
    return m_Context;
}
