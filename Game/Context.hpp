#ifndef CONTEXT_HPP
#define CONTEXT_HPP

namespace sf
{
    class RenderWindow;
}

struct Context
{
    Context(sf::RenderWindow& window):
        m_Window(window)
    {
    }

    // TODO: Add other things that might need to be passed between states
    // like resource managers and player controllers.
    sf::RenderWindow& m_Window;
};

#endif // CONTEXT_HPP
