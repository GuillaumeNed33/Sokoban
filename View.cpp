#include "View.h"
#include <iostream>
sf::Music View::m_music;
bool View::m_charge = false;

View::View(sf::RenderWindow* window) : m_window{window}
{
    if(!m_charge)
    {
    if(!m_music.openFromFile(SOUND))
            std::cerr << "ERROR when loading audio file: " << SOUND << std::endl;
        m_music.setLoop(true);
        m_music.setVolume(20);
        m_music.play();
        m_charge = true;
    }

}

View::~View()
{

}
