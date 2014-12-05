#include "grid.h"
#include "entity.h"



Grid::Grid()
{

}

void Grid::Initialize(int X, int Y)
{
  m_dimX = X;
  m_dimY = Y;

  m_cells = new Cell* [m_dimX];
  for (unsigned int i = 0 ; i < m_dimX ; i++)
    {
      m_cells[i] = new Cell[m_dimY];
    }

  Entity player1;
  player1.SetCoord(0,2,m_cells[0,2]);
  player1.PrintCoord();
}
