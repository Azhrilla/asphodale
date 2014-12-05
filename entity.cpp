#include "entity.h"


using namespace std;
// Créé l'entité et initialise son propre générateur aléatoire.
Entity::Entity()
{
  m_coord.m_posX = 0;
  m_coord.m_posY = 0;
  m_isAlive = true;
  unsigned seed
    = std::chrono::system_clock::now().time_since_epoch().count();
  m_rng.seed(seed);
  std::uniform_int_distribution<uint32_t> distribution(0,2);
  m_dist = distribution;
}

void Entity::SetCoord(Coordinates coord, Cell* newCell)
{
  m_coord = coord;
  m_currentCell = newCell;
}

const Coordinates Entity::GetCoord()
{
  return m_coord;
}

const void Entity::PrintCoord()
{
  std::cout << "This entity is at " << m_coord.m_posX << " " << m_coord.m_posY << std::endl;
}

const Coordinates Entity::GetTargetDeplacement()
{
  int dep_X = m_dist(m_rng) - 1;
  int dep_Y = m_dist(m_rng) - 1;
  Coordinates output = m_coord;
  output.m_posX += dep_X;
  output.m_posY += dep_Y;
  return output;
}

const int Entity::Attack(Entity* target)
{
  return 0;
}

void Entity::TakeDamage(Entity*)
{
  cout << "Entity can't take dmg" << endl;
}

const bool Entity::IsAlive()
{
  return true;
}

const string Entity::GetName()
{
  return m_name;
}
