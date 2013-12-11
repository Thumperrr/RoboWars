#include "StateStack.hpp"
#include <cassert>

StateStack::StateStack(Context context) :
    m_Stack(),
    m_PendingList(),
    m_Context(context),
    m_Factories()
{
}

void StateStack::update(sf::Time dt)
{
    for (auto it = m_Stack.rbegin(); it != m_Stack.rend(); ++it)
    {
        // If the states update method returns false
        // the other states beneath it will not update.
        // This is handy if you want to pause the states beneath the current one.
        if (!(*it)->update(dt))
            return;
    }
}

void StateStack::draw()
{
    for (State::Ptr& state : m_Stack)
        state->draw();
}

void StateStack::handleEvent(const sf::Event& event)
{
    for (auto it = m_Stack.rbegin(); it != m_Stack.rend(); ++it)
    {
        // Same as the update method. Stops inputs from being passed
        // down the stack if false is returned.
        if (!(*it)->handleEvent(event))
            break;
    }

    applyPendingChanges();
}

void StateStack::pushState(States::ID stateID)
{
    m_PendingList.push_back(PendingChange(Action::Push, stateID));
}

void StateStack::popState()
{
    m_PendingList.push_back(PendingChange(Action::Pop));
}

void StateStack::clearStates()
{
    m_PendingList.push_back(PendingChange(Action::Clear));
}

bool StateStack::isEmpty() const
{
    return m_Stack.empty();
}

State::Ptr StateStack::createState(States::ID stateID)
{
    auto found = m_Factories.find(stateID);
    assert(found != m_Factories.end());

    return found->second();
}

void StateStack::applyPendingChanges()
{
    for (PendingChange change : m_PendingList)
    {
        switch (change.m_Action)
        {
            case Push:
                m_Stack.push_back(createState(change.m_StateID));
                break;

            case Pop:
                m_Stack.pop_back();
                break;

            case Clear:
                m_Stack.clear();
                break;
        }
    }

    m_PendingList.clear();
}

StateStack::PendingChange::PendingChange(Action action, States::ID stateID) :
    m_Action(action),
    m_StateID(stateID)
{
}
