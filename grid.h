#ifndef ENTITY_H
#define ENTITY_H



#include "cell.h"



class Grid
{
 private:
  Cell** m_cells;
  unsigned int m_dimX;
  unsigned int m_dimY;

 public:
  Grid();
  void Initialize(int, int);

};


#endif




