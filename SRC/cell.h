#ifndef CELL_H
#define CELL_H

#include <map>
#include "coordinates.h"
#include <string>

class Cell
{
 private:
  Coordinates m_coord;

 public:
  Cell();
  void SetCoord(const unsigned int, const unsigned int);
  Coordinates GetCoord() const;
  void GiveMana(map<string,int>&);
};


#endif
