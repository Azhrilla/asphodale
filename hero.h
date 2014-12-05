#ifndef HERO_H
#define HERO_H

#include "coordinates.h"
#include "entity.h"

class Hero : public Entity
{
 protected:
  int m_HP;

 public:
  Hero();
  const Coordinates GetTargetDeplacement();
  virtual void TakeDamage(Entity*);
  virtual const int Attack(Entity*);
  const bool IsAlive();
};

#endif
