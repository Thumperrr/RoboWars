#ifndef TESTINGSTATE_HPP
#define TESTINGSTATE_HPP

#include "State.hpp"

class TestingState : public State
{
    public:
        TestingState(StateStack& stack, Context context);

        virtual void draw();
        virtual bool update(sf::Time dt);
        virtual bool handleEvent(const sf::Event event);

    private:

};

#endif // TESTINGSTATE_HPP
