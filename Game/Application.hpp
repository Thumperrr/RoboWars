#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Game/States/StateStack.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Application
{
    public:
        Application();

        void run();


    private:
        void processInput();
        void update(sf::Time dt);
        void render();

        // In this method you will need to register all the different states that
        // you game has. For a example see the definition.
        void registerStates();


    private:
        static const sf::Time m_TimePerFrame;
        sf::RenderWindow m_Window;

        StateStack m_StateStack;
};

#endif // APPLICATION_HPP
