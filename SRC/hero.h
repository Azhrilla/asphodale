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
  int m_team;
  map<string, int> m_mana;

 public:
  Hero();
  ~Hero();
  Coordinates GetTargetDeplacement();
  virtual void TakeDamage(Entity*);
  bool IsAlive() const;
  virtual void Initialize(int, Cell*, string, int);
  virtual bool CanAttack(Entity*) const;
  virtual void RegenMana();
  virtual void PrintStatus();
};

#endif
