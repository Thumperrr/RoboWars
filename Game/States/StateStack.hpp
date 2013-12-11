#ifndef STATESTACK_HPP
#define STATESTACK_HPP

#include "Game/Context.hpp"
#include "Game/States/StateIdentifiers.hpp"
#include "Game/States/State.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <vector>
#include <map>

class StateStack : public sf::NonCopyable
{
    public:
        enum Action
        {
            Push,
            Pop,
            Clear,
        };


    public:
        explicit StateStack(Context context);

        template <typename T>
        void registerState(States::ID stateID);

        void update(sf::Time dt);
        void draw();
        void handleEvent(const sf::Event& event);

        void pushState(States::ID stateID);
        void popState();
        void clearStates();

        bool isEmpty() const;


    private:
        State::Ptr createState(States::ID stateID);
        void applyPendingChanges();


    private:
        struct PendingChange
        {
                PendingChange(Action action, States::ID stateID = States::ID::None);

                Action m_Action;
                States::ID m_StateID;
        };


    private:
        std::vector<State::Ptr> m_Stack;
        std::vector<PendingChange> m_PendingList;
        Context m_Context;
        std::map<States::ID, std::function<State::Ptr()>> m_Factories;
};

template <typename T>
void StateStack::registerState(States::ID stateID)
{
    m_Factories[stateID] = [this] ()
    {
        return State::Ptr(new T(*this, m_Context));
    };
}

#endif // STATESTACK_HPP
