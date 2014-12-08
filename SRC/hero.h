#ifndef HERO_H
#define HERO_H

#include "coordinates.h"
#include "entity.h"
#include "cell.h"

class Hero : public Entity
{
 protected:
  int m_HP;
  int m_id;
  map<string, int> m_mana;

 public:
  Hero();
  ~Hero();
  Coordinates GetTargetDeplacement();
  virtual void TakeDamage(Entity*);
  bool IsAlive() const;
  virtual void Initialize(int, Cell*, string);
  virtual bool CanAttack(Entity*) const;
  virtual void RegenMana();
  virtual void PrintStatus();
};

#endif
