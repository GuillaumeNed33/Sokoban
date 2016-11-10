#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <vector>

class Level
{
private:
    static const int LINES = 15;
    static const int COLUMS = 15;
    std::string m_name;
    char m_grid[LINES][COLUMS];

public:
    Level(std::string name);
    ~Level();
    void buildMap();
    char getMapContains(int i, int j) const;
        void setMapContains(int i, int j, char c);
    int getLines() const;
    int getColums() const;
};

#endif // LEVEL_H
