#include "entity.h"
#include <iostream>

Entity::Entity()
{
  m_coord.m_posX = 0;
  m_coord.m_posY = 0;
}

void Entity::SetCoord(unsigned int x, unsigned int y, Cell newCell)
{
m_coord.m_posX = x;
  m_coord.m_posY = y;
m_currentCell = newCell;
}


const void Entity::PrintCoord()
{
std::cout << "this entity is at" << m_coord.m_posX << " " << m_coord.m_posY << std::endl;
}
