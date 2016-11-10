#include "Player.h"

using namespace std;

Player::Player(Level* lvl) : m_posX {0},m_posY {0}, level {lvl}
{
}

Player::Player(int x, int y, Level* lvl) : m_posX {x},m_posY {y}, level {lvl}
{
}

Player::~Player()
{
}

void Player::move(Direction dir)
{
    switch (dir)
    {
    case UP:
        if(m_posX > 0)
        {
            if(level->getMapContains(m_posX-1,m_posY) == '0' || level->getMapContains(m_posX-1,m_posY) == 'x')
            {
                m_posX--;
            }
            else if(level->getMapContains(m_posX-1,m_posY) == 'c' && level->getMapContains(m_posX-2,m_posY) == '0')
            {
                level->setMapContains(m_posX-2,m_posY,'c');
                level->setMapContains(m_posX-1,m_posY,'0');
                m_posX--;
            }
            else if(level->getMapContains(m_posX-1,m_posY) == 'c' && level->getMapContains(m_posX-2,m_posY) == 'x')
            {
                level->setMapContains(m_posX-2,m_posY,'k');
                level->setMapContains(m_posX-1,m_posY,'0');
                m_posX--;
            }
        }
        break;

    case DOWN:
        if(m_posX < level->getColums()-2)
        {
            if(level->getMapContains(m_posX+1,m_posY) == '0' || level->getMapContains(m_posX+1,m_posY) == 'x')
            {
                m_posX++;
            }
            else if(level->getMapContains(m_posX+1,m_posY) == 'c' && level->getMapContains(m_posX+2,m_posY) == '0')
            {
                level->setMapContains(m_posX+2, m_posY, 'c');
                level->setMapContains(m_posX+1,m_posY,'0');
                m_posX++;
            }
            else if(level->getMapContains(m_posX+1,m_posY) == 'c' && level->getMapContains(m_posX+2,m_posY) == 'x')
            {
                level->setMapContains(m_posX+2, m_posY, 'k');
                level->setMapContains(m_posX+1,m_posY,'0');
                m_posX++;
            }
        }
        break;

    case RIGHT:
        if(m_posY < level->getLines()-2)
        {
            if(level->getMapContains(m_posX, m_posY+1) == '0' || level->getMapContains(m_posX,m_posY+1) == 'x')
            {
                m_posY++;
            }
            else if(level->getMapContains(m_posX, m_posY+1) == 'c' && level->getMapContains(m_posX, m_posY+2) == '0')
            {
                level->setMapContains(m_posX, m_posY+2,'c');
                level->setMapContains(m_posX, m_posY+1,'0');
                m_posY++;
            }
            else if(level->getMapContains(m_posX, m_posY+1) == 'c' && level->getMapContains(m_posX, m_posY+2) == 'x')
            {
                level->setMapContains(m_posX, m_posY+2,'k');
                level->setMapContains(m_posX, m_posY+1,'0');
                m_posY++;
            }
        }
        break;

    case LEFT:
        if(m_posY > 0)
        {
            if(level->getMapContains(m_posX,m_posY-1) == '0' || level->getMapContains(m_posX,m_posY-1) == 'x')
            {
                m_posY--;
            }
            else if(level->getMapContains(m_posX,m_posY-1) == 'c' && level->getMapContains(m_posX,m_posY-2) == '0')
            {
                level->setMapContains(m_posX,m_posY-2, 'c');
                level->setMapContains(m_posX, m_posY-1, '0');
                m_posY--;
            }
            else if(level->getMapContains(m_posX,m_posY-1) == 'c' && level->getMapContains(m_posX,m_posY-2) == 'x')
            {
                level->setMapContains(m_posX,m_posY-2, 'k');
                level->setMapContains(m_posX, m_posY-1, '0');
                m_posY--;
            }
        }
        break;
    }
}

int Player::getPosX() const
{
    return m_posX;
}

int Player::getPosY() const
{
    return m_posY;
}
