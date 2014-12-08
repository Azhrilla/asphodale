#include "monster.h"

using namespace std;

Monster::Monster()
{
  m_HP = 5;
  m_attackDamage = 1;
  m_name = "monster";
}

Monster::~Monster()
{
}

Coordinates Monster::GetTargetDeplacement()
{
  int dep_X = m_dist(m_rng) - 1;
  int dep_Y = m_dist(m_rng) - 1;
  Coordinates output = m_coord;
  output.m_posX += dep_X;
  output.m_posY += dep_Y;
  return output;
}

void Monster::TakeDamage(Entity* foe)
{
  m_HP -= foe->Attack(this);
  cout << m_name << " took " << foe->Attack(this)<< " damages from " << foe->GetName()<< endl;
}

int Monster::Attack(Entity* target) const
{
  return m_attackDamage;
}


bool Monster::IsAlive() const
{
  return (m_HP > 0);
}
