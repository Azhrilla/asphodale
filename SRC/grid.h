#ifndef GRID_H
#define GRID_H



#include "cell.h"
#include <vector>
#include "entity.h"
#include "entity.h"
#include "coordinates.h"
#include <iostream>
#include "monster.h"
#include "hero.h"


class Grid
{
 private:
  typedef std::mt19937 MyRNG;
  MyRNG m_rng;
  Cell** m_cells;
  std::vector<Entity*> m_entities;
  unsigned int m_dimX;
  unsigned int m_dimY;
  unsigned int m_idJ1;
  unsigned int m_idJ2;



 public:
  Grid();
  void Initialize(int, int, int, int);
  void ResolveDeplacements();
  void ResolveAttacks();
  void PrintGrid() const;
  bool IsCellFull(Coordinates, int&) const;
  bool DeplacementImpossible(Coordinates) const;
  vector<int> GetNeighborsIndex(Coordinates) const;
  void CheckAlive();
  void RegenMana();
  void PrintStatus() const;
};


#endif




