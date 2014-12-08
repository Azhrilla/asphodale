#include "cell.h"
#include <iostream>

Cell::Cell()
{
}


void Cell::SetCoord(const unsigned int x, const unsigned int y)
{
  Coordinates coord(x,y);
  m_coord = coord;
}

Coordinates Cell::GetCoord() const
{
  return m_coord;
}

void Cell::GiveMana(map<string,int>& input_mana)
{
  input_mana["blue"]++;
  input_mana["red"]++;
  input_mana["green"]++;
  input_mana["black"]++;
}
