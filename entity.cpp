#include "entity.h"


using namespace std;
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

void Entity::SetCoord(unsigned int x, unsigned int y, Cell* newCell)
{
  m_coord.m_posX = x;
  m_coord.m_posY = y;
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
