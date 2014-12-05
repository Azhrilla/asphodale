#ifndef MONSTER_H
#define MONSTER_H

#include "coordinates.h"
#include "entity.h"

class Monster : public Entity
{
 protected:
  int m_HP;
  int m_attackDamage;

 public:
  Monster();
  const Coordinates GetTargetDeplacement();
  virtual void TakeDamage(Entity*);
  virtual const int Attack(Entity*);
  const bool IsAlive();
};

#endif
