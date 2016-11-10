#include "Level.h"
#include  <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

Level::Level(string name) : m_name{name}
{
  buildMap();
}

Level::~Level()
{
}

void Level::buildMap()
{

  fstream f;
  char element;
  int i=0;
  int j=0;

  f.open(m_name.c_str(), ios:: in);

  if(f.fail())
  {
    std::cerr << "ouverture en lecture impossible" << endl;
    exit(EXIT_FAILURE);
  }
  while(!f.eof())
  {
    f.get(element);
    if(element == '\n')
    {/*
      j++;
      i=0;*/
      i++;
      j=0;
    }
    else
    {
      m_grid[i][j] = element;
      //i++;
      j++;
    }
  }
}

char Level::getMapContains(int i, int j) const
{
  return m_grid[i][j];
}

void Level::setMapContains(int i, int j, char c)
{
  m_grid[i][j] = c;
}

int Level::getLines() const
{
    return LINES;
}

int Level::getColums() const
{
    return COLUMS;
}
