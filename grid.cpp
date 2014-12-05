#include "grid.h"
#include "entity.h"
#include "coordinates.h"
#include <iostream>

using namespace std;

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
  Entity player2;
  player2.SetCoord(4,2,m_cells[4,2]);
  player2.PrintCoord();
  Entity player3;
  player3.SetCoord(2,0,m_cells[2,0]);
  player3.PrintCoord();


  m_entities.push_back(player1);
  m_entities.push_back(player2);
  m_entities.push_back(player3);
}

// Fonction récupérant les déplacements et les effectuant si possible.
void Grid::ResolveDeplacements()
{
  // Ce vecteur contient la liste des déplacements voulus par les entités.
  vector<Coordinates> targetDeplacements;
  for ( unsigned int i = 0; i < m_entities.size(); i++)
    {
      Coordinates nextDeplacement = m_entities[i].GetTargetDeplacement() ;
      while (nextDeplacement.m_posX < 0 || nextDeplacement.m_posY < 0
             || nextDeplacement.m_posY >= m_dimY || nextDeplacement.m_posX >= m_dimX)
        {
          nextDeplacement = m_entities[i].GetTargetDeplacement() ;
        }
      targetDeplacements.push_back(nextDeplacement);
    }

  // Vérifie de manière intérative que les entités ne veulent pas aller au
  // même endroit
  bool canMove = false;
  while (!canMove)
    {
      vector<int> index = ExtractDuplicatesIndex(targetDeplacements);
      if (index.empty())
        {
          canMove = true;
        }
      else
        {
          for (unsigned int i = 0; i < index.size(); i++)
            {
              targetDeplacements[index[i]] = m_entities[index[i]].GetCoord();
            }
        }
    }

  // Effectue les déplacements, au même endroit si déplacement impossible et
  // met à jour les cases.
  for (unsigned int i = 0; i < m_entities.size(); i++)
    {
      int x = targetDeplacements[i].m_posX;
      int y = targetDeplacements[i].m_posY;
      m_entities[i].SetCoord(x,y,m_cells[x,y]);
    }

}

// Fonction batarde de visualisation ascii.
const void Grid::PrintGrid()
{
  for (unsigned int i = 0; i < m_dimX; i++)
    {
      for (unsigned int j = 0; j < m_dimY; j++)
        {
          Coordinates coordCell(j,i);
          bool presence = false;
          for (unsigned int k = 0; k < m_entities.size(); k++)
            {
                if (m_entities[k].GetCoord() == coordCell)
                  {
                    cout << " " << k+1 << " " ;
                    presence = true;
                  }
            }
          if (!presence)
            cout << " o ";
        }
      cout << endl;
    }
  cout << endl;
}
