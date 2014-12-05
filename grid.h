#ifndef GRID_H
#define GRID_H



#include "cell.h"
#include <vector>
#include "entity.h"

class Grid
{
 private:
  Cell** m_cells;
  std::vector<Entity> m_entities;
  unsigned int m_dimX;
  unsigned int m_dimY;

 public:
  Grid();
  void Initialize(int, int);
  void ResolveDeplacements();
  const void PrintGrid();

};


#endif




