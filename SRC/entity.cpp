#include "entity.h"


using namespace std;
// Créé l'entité et initialise son propre générateur aléatoire.
Entity::Entity()
{
  m_coord.m_posX = 0;
  m_coord.m_posY = 0;
  unsigned seed
    = std::chrono::system_clock::now().time_since_epoch().count();
  m_rng.seed(seed);
  std::uniform_int_distribution<uint32_t> distribution(0,2);
  m_dist = distribution;
}

Entity::~Entity()
{}

void Entity::SetCoord(Cell* newCell)
{
  m_coord = newCell->GetCoord();
  m_currentCell = newCell;
}

Coordinates Entity::GetCoord() const
{
  return m_coord;
}

void Entity::PrintCoord() const
{
  std::cout << "This entity is at " << m_coord.m_posX << " " << m_coord.m_posY << std::endl;
}

Coordinates Entity::GetTargetDeplacement()
{
  int dep_X = m_dist(m_rng) - 1;
  int dep_Y = m_dist(m_rng) - 1;
  Coordinates output = m_coord;
  output.m_posX += dep_X;
  output.m_posY += dep_Y;
  return output;
}

int Entity::Attack(Entity*) const
{
  return 0;
}

void Entity::TakeDamage(Entity*)
{
  cout << "Entity can't take dmg" << endl;
}

bool Entity::IsAlive() const
{
  return true;
}

string Entity::GetName() const
{
  return m_name;
}

bool Entity::CanAttack(Entity*) const
{
  return true;
}

void Entity::RegenMana()
{
}

void Entity::PrintStatus()
{
  cout << "i am "<< m_name << endl;
}


void Entity::EndTurn()
{
}

int Entity::GetId() const
{
  return 0;
}

void Entity::SetCommand(Command)
{
}
