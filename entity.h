#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include "coordinates.h"
#include "cell.h"

class Entity
{
 protected:
  typedef std::mt19937 MyRNG;
  MyRNG m_rng;
  std::uniform_int_distribution<uint32_t> m_dist;

  Coordinates m_coord;
  Coordinates m_coordWanted;
  Cell* m_currentCell;
  bool m_isAlive;
  string m_name;
 public:
  Entity();
  void SetCoord(Coordinates, Cell*);
  const void PrintCoord();
  const Coordinates GetCoord();
  const string GetName();

  virtual const Coordinates GetTargetDeplacement();
  virtual const int Attack(Entity*);
  virtual void TakeDamage(Entity*);
  virtual const bool IsAlive();
};


#endif
