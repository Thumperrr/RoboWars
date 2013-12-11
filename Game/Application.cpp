#include "Application.hpp"
#include <SFML/Window/Event.hpp>

const sf::Time Application::m_TimePerFrame = sf::seconds(1.0f / 60.0f);

Application::Application() :
    m_Window(sf::VideoMode(800, 600), "Robo Wars"),
    m_StateStack(Context(m_Window))
{
    // Setup basic info for this window
    m_Window.setKeyRepeatEnabled(false);
    m_Window.setMouseCursorVisible(true);

    // State stuff
    registerStates();
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (m_Window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > m_TimePerFrame)
        {
            timeSinceLastUpdate -= m_TimePerFrame;

            processInput();
            update(m_TimePerFrame);

            // If the state stack is empty we need to exit
            if (m_StateStack.isEmpty())
                m_Window.close();
        }

        render();
    }
}

void Application::processInput()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        // Do event polling for the stack here
        m_StateStack.handleEvent(event);

        if (event.type == sf::Event::Closed)
            m_Window.close();
    }
}

void Application::update(sf::Time dt)
{
    m_StateStack.update(dt);
}

void Application::render()
{
    m_Window.clear();
    m_StateStack.draw();
    m_Window.display();
}

void Application::registerStates()
{
    // Register all the global states that the application will have here.

    /* Example
     *
     * m_StateStack.registerState<MenuState>(States::Menu);
     *
     * The template parameter is the class which defines the state and the method parameter
     * is the ID you wish to assign to that state. You will use this ID for transitions.
     *
     */
}
