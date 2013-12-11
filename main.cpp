#include "Game/Application.hpp"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        Application app;
        app.run();
    }
    catch (std::exception& e)
    {
        std::cout << "\nException: " << e.what() << std::endl;
    }
}

