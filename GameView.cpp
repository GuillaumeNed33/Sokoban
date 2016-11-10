#include "GameView.h"
#include <iostream>
using namespace std;

GameView::GameView(sf::RenderWindow* window, int level) : View {window}, m_level {level}
{
    switch(m_level)
    {
    case 1 :
        m_mapName += "n1";
        break;
    case 2:
        m_mapName += "n2";
        break;
    case 3:
        m_mapName += "n3";
        break;
    }

    m_map = new Level(m_mapName);
    if(m_level == 3)
        m_player = new Player(9,5,m_map);
    else
        m_player = new Player(m_map);

    loadImages();
}

GameView::~GameView()
{
    delete m_player;
    delete m_map;
}

void GameView::draw()
{
    m_window->clear();
    m_window->draw(m_background);
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(m_map->getMapContains(i,j)=='m')
            {
                m_wall.setPosition(j*30,i*30);
                m_window->draw(m_wall);
            }
            else if(m_map->getMapContains(i,j)=='x')
            {
                m_obj.setPosition(j*30,i*30);
                m_window->draw(m_obj);
            }
            else if(m_map->getMapContains(i,j)=='c')
            {
                m_pokeball.setPosition(j*30,i*30);
                m_window->draw(m_pokeball);
            }
            else if(m_map->getMapContains(i,j)=='k')
            {
                m_completeObj.setPosition(j*30,i*30);
                m_window->draw(m_completeObj);
            }
        }
    }
    m_perso.setPosition(m_player->getPosY()*30,m_player->getPosX()*30);
    m_window->draw(m_perso);
    if(m_end)
        m_window->draw(m_victory);
    m_window->display();
}

void GameView::synchronize()
{
    int cpt = 0;
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(m_map->getMapContains(i,j)=='x')
            {
                cpt++;
            }
        }
    }
    if(cpt == 0)
        m_end = true;
}

bool GameView::treatEvents()
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
                if(m_end)
                {
                    result = false;
                }
                else
                {
                    if(event.key.code == sf::Keyboard::Up)
                    {
                        m_player->move(UP);
                    }
                    if(event.key.code == sf::Keyboard::Down)
                    {
                        m_player->move(DOWN);
                    }
                    if(event.key.code == sf::Keyboard::Left)
                    {
                        m_player->move(LEFT);
                    }
                    if(event.key.code == sf::Keyboard::Right)
                    {
                        m_player->move(RIGHT);
                    }
                    if(event.key.code == sf::Keyboard::Escape)
                    {
                        result = false;
                    }
                    if(event.key.code == sf::Keyboard::BackSpace)
                    {
                        reset();
                    }
                }
            }
        }
    }
    return result;
}

void GameView::loadImages()
{
    if (!m_Textwall.loadFromFile(WALL))
        std::cerr << "ERROR when loading image file: " << WALL << std::endl;
    if (!m_Textperso.loadFromFile(PLAYER))
        std::cerr << "ERROR when loading image file: " << PLAYER << std::endl;
    if (!m_TextcompleteObj.loadFromFile(SUCCESS))
        std::cerr << "ERROR when loading image file: " << SUCCESS << std::endl;
    if (!m_Textobj.loadFromFile(CHECK))
        std::cerr << "ERROR when loading image file: " << CHECK << std::endl;
    if (!m_TextPokeball.loadFromFile(POKEBALL))
        std::cerr << "ERROR when loading image file: " << POKEBALL << std::endl;
    if (!m_textureFond.loadFromFile(BACKGROUND))
        std::cerr << "ERROR when loading image file: " << BACKGROUND << std::endl;
    if (!m_TextVictory.loadFromFile(VICTORY))
        std::cerr << "ERROR when loading image file: " << VICTORY << std::endl;

    m_wall.setTexture(m_Textwall);
    m_perso.setTexture(m_Textperso);
    m_completeObj.setTexture(m_TextcompleteObj);
    m_obj.setTexture(m_Textobj);
    m_pokeball.setTexture(m_TextPokeball);
    m_background.setTexture(m_textureFond);
    m_victory.setTexture(m_TextVictory);
    m_victory.setPosition(70,138);
}

void GameView::reset()
{
    delete m_map;
    delete m_player;
    m_map = new Level(m_mapName);
    if(m_level == 3)
        m_player = new Player(9,5,m_map);
    else
        m_player = new Player(m_map);
    m_end = false;
}
