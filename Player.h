#ifndef PLAYER_H
#define PLAYER_H
#include "Level.h"

enum Direction {UP,DOWN,LEFT, RIGHT};

class Level;
class Player
{
private :
    int m_posX;
    int m_posY;
    Level* level;
public:
    Player(Level* lvl);
    Player(int x, int y, Level* lvl);
    ~Player();
    void move(Direction dir);
    void setLevel(Level* lvl);
    int getPosX() const;
    int getPosY() const;
};

#endif // PLAYER_H
