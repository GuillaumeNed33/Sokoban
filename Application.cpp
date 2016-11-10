#include "Application.h"
#include "Home.h"
#include "MapSelection.h"
#include "GameView.h"
#include <iostream>

Application::Application()
{
    m_window = new sf::RenderWindow {sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Sokoban", sf::Style::Close};
    if(!m_icon.loadFromFile(ICON))
        std::cerr << "ERROR when loading image file: " << ICON << std::endl;
    m_window->setIcon(256,256,m_icon.getPixelsPtr());
}

Application::~Application()
{
    delete m_window;
}

void Application::run()
{
    m_window->setFramerateLimit(60);

label:
    ;

    Home* home = new Home{m_window};
    while(home->treatEvents() && m_window->isOpen())
    {
        home->draw();
    }
    delete home;

    while(m_window->isOpen())
    {
        MapSelection* mapping = new MapSelection(m_window);
        while(mapping->treatEvents())
        {
            mapping->draw();
            mapping->synchronize();
        }
        if(!mapping->getNextStep())
        {
            delete mapping;
            goto label;
        }
        else
        {
            GameView* game = new GameView(m_window, mapping->getLevel());
            delete mapping;
            while(game->treatEvents())
            {
                game->draw();
                game->synchronize();
            }
            delete game;
        }
    }
}
