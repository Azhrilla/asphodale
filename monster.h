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
  Coordinates GetTargetDeplacement();
  virtual void TakeDamage(Entity*);
  virtual  int Attack(Entity*) const;
  bool IsAlive() const;
};

#endif
