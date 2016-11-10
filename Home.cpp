#include "Home.h"
#include <iostream>

Home::Home(sf::RenderWindow* window) : View {window}
{
    if (!m_textureFond.loadFromFile(BACKGROUND_IMAGE))
        std::cerr << "ERROR when loading image file: " << BACKGROUND_IMAGE << std::endl;
    m_background.setTexture(m_textureFond);

}

Home::~Home()
{}

void Home::draw()
{
    m_window->draw(m_background);
    m_window->display();
}

bool Home::treatEvents()
{
    bool result = false;
    if(m_window->isOpen())
    {
        result = true;
        sf::Event event;

        while (m_window->pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                m_window->close();
                result = false;
            }

            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return))
            {
                result = false;
            }
        }
    }
    return result;
}

void Home::synchronize()
{


}
