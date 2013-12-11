#ifndef STATE_HPP
#define STATE_HPP

#include "Game/Context.hpp"
#include "Game/States/StateIdentifiers.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

class StateStack;

class State
{
    public:
        typedef std::unique_ptr<State> Ptr;

        State(StateStack& stack, Context context);
        ~State();

        virtual void draw() = 0;

        // These return bool so that when you have more then one state on the stack
        // you can make it so that it doesn't update the states below it by returning false.
        // For example when you have a pause screen you don't want the underlying gameplay state
        // to continue updating and handling events while the pause state is active.
        virtual bool update(sf::Time dt) = 0;
        virtual bool handleEvent(const sf::Event event) = 0;


    protected:

        // These will send requests to the state stack which will then handle the transitions
        void requestStackPush(States::ID stateID);
        void requestStackPop();
        void requestStackClear();

        Context getContext() const;


    private:
        StateStack& m_Stack;
        Context m_Context;
};

#endif // STATE_HPP
