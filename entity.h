#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <chrono>
#include <random>
#include "coordinates.h"
#include "cell.h"

class Entity
{
 private:
  typedef std::mt19937 MyRNG;
  MyRNG m_rng;
  std::uniform_int_distribution<uint32_t> m_dist;

  Coordinates m_coord;
  Coordinates m_coordWanted;
  Cell* m_currentCell;


 public:
  Entity();
  void SetCoord(unsigned int, unsigned int, Cell*);
  const void PrintCoord();
  const Coordinates GetTargetDeplacement();
  const Coordinates GetCoord();
};


#endif
