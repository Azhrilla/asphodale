#ifndef ENTITY_H
#define ENTITY_H

#include "coordinates.h"
#include "cell.h"

class Entity
{
 private:
  Coordinates m_coord;
  Coordinates m_coordWanted;
  Cell m_currentCell;

 public:
  Entity();
  void SetCoord(unsigned int, unsigned int, Cell);
  const void PrintCoord();
};


#endif
