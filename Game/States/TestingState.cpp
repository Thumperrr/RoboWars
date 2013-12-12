#include "TestingState.hpp"

TestingState::TestingState(StateStack &stack, Context context) :
    State(stack, context)
{

}

void TestingState::draw()
{
    // Drawing code here
}

bool TestingState::update(sf::Time dt)
{
    // Update code here
    return false;
}

bool TestingState::handleEvent(const sf::Event event)
{
    // Handle input here
    return false;
}
