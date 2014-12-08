#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <map>
#include "coordinates.h"
#include "cell.h"


// Tout est entité sur la grille, spécialisations possibles : héros, monstres,
// murs ... etc
class Entity
{
 protected:
  typedef std::mt19937 MyRNG;
  MyRNG m_rng;
  std::uniform_int_distribution<uint32_t> m_dist;

  Coordinates m_coord;
  Coordinates m_coordWanted;
  Cell* m_currentCell;
  string m_name;

 public:
  Entity();
  virtual ~Entity()=0;
  void SetCoord(Cell*);
  void PrintCoord() const;
  Coordinates GetCoord() const;
  virtual string GetName() const;
  virtual Coordinates GetTargetDeplacement();
  virtual int Attack(Entity*) const;
  virtual void TakeDamage(Entity*);
  virtual bool IsAlive() const;
  virtual bool CanAttack(Entity*) const;
  virtual void RegenMana();
  virtual void PrintStatus();
};


#endif
