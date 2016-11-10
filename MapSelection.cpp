#include "MapSelection.h"
#include <iostream>

MapSelection::MapSelection(sf::RenderWindow* window) : View {window}
{
    if (!m_textureFond.loadFromFile(BACKGROUND_IMAGE))
        std::cerr << "ERROR when loading image file: " << BACKGROUND_IMAGE << std::endl;
    m_background.setTexture(m_textureFond);
    if (!m_textureSelect.loadFromFile(SELECTOR))
        std::cerr << "ERROR when loading image file: " << SELECTOR << std::endl;
    m_selector.setTexture(m_textureSelect);

    m_font.loadFromFile("Font/Antique.ttf");

    m_info1.setFont(m_font);
    m_info1.setColor(sf::Color::Black);
    m_info1.setPosition(60,75);
    m_info1.setCharacterSize(24);
    m_info1.setString(m_levelInfo1);

    m_info2.setFont(m_font);
    m_info2.setColor(sf::Color::Black);
    m_info2.setPosition(60,200);
    m_info2.setCharacterSize(24);
    m_info2.setString(m_levelInfo2);

    m_info3.setFont(m_font);
    m_info3.setColor(sf::Color::Black);
    m_info3.setPosition(60,325);
    m_info3.setCharacterSize(24);
    m_info3.setString(m_levelInfo3);
}

MapSelection::~MapSelection()
{}

void MapSelection::draw()
{
    m_window->draw(m_background);
    m_window->draw(m_info1);
    m_window->draw(m_info2);
    m_window->draw(m_info3);
    m_window->draw(m_selector);
    m_window->display();
}

void MapSelection::synchronize()
{
    if(m_level == 1)
    {
        m_selector.setPosition(20,75);
    }
    else if(m_level == 2)
    {
        m_selector.setPosition(20,200);
    }
    else if(m_level == 3)
    {
        m_selector.setPosition(20,325);
    }
}

bool MapSelection::treatEvents()
{
    bool result = false;
    if(m_window->isOpen())
    {
        result = true;
        sf::Event event;

        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
                result = false;
            }

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    m_nextStep = false;
                    result = false;
                }
                else if(event.key.code == sf::Keyboard::Up)
                {
                    if(m_level > 0)
                        m_level--;
                }
                else if(event.key.code == sf::Keyboard::Down)
                {
                    if(m_level < 3)
                        m_level++;
                }
                else if(event.key.code == sf::Keyboard::Return)
                {
                    result = false;
                }
            }
        }
    }
    return result;
}

int MapSelection::getLevel() const
{
    return m_level;
}

bool MapSelection::getNextStep() const
{
    return m_nextStep;
}
