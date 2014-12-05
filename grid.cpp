#include "grid.h"

using namespace std;

Grid::Grid()
{
  unsigned seed
    = std::chrono::system_clock::now().time_since_epoch().count();
  m_rng.seed(seed);
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

  Coordinates coord1(0,2);
  Hero* player1 = new Hero;
  player1->SetCoord(coord1,m_cells[0,2]);
  player1->PrintCoord();
  Monster* player2 = new Monster;
  Coordinates coord2(4,2);
  player2->SetCoord(coord2,m_cells[4,2]);
  player2->PrintCoord();
  Monster* player3 = new Monster;
  Coordinates coord3(2,0);
  player3->SetCoord(coord3,m_cells[2,0]);
  player3->PrintCoord();


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
      Coordinates nextDeplacement = m_entities[i]->GetTargetDeplacement() ;
      while (DeplacementImpossible(nextDeplacement))
        {
          nextDeplacement = m_entities[i]->GetTargetDeplacement() ;
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
              targetDeplacements[index[i]] = m_entities[index[i]]->GetCoord();
            }
        }
    }

  // Effectue les déplacements, au même endroit si déplacement impossible et
  // met à jour les cases.
  for (unsigned int i = 0; i < m_entities.size(); i++)
    {
      int x = targetDeplacements[i].m_posX;
      int y = targetDeplacements[i].m_posY;
      m_entities[i]->SetCoord(targetDeplacements[i],m_cells[x,y]);
    }
}

// Fonction batarde de visualisation ascii.
void Grid::PrintGrid() const
{
  for (unsigned int i = 0; i < m_dimX; i++)
    {
      for (unsigned int j = 0; j < m_dimY; j++)
        {
          Coordinates coordCell(j,i);
          int k;
          if (IsCellFull(coordCell,k))
            {
              cout << " " << k+1 << " " ;
            }
          else
            {
              cout << " o ";
            }
        }
      cout << endl;
    }
  cout << endl;
}


// Check si une coordonnée est occupée et retourne l'index de l'occupant si
// oui.
bool Grid::IsCellFull(Coordinates coord, int& indexEntity) const
{
  bool presence = false;
  for (unsigned int i = 0; i < m_entities.size(); i++)
    {
      if (m_entities[i]->GetCoord() == coord)
        {
          presence = true;
          indexEntity = i;
        }
    }
  return presence;
}


// Check si un déplacement est possible.
bool Grid::DeplacementImpossible(Coordinates coord) const
{
  return (coord.m_posX < 0 || coord.m_posY < 0 ||
          coord.m_posY >= m_dimY || coord.m_posX >= m_dimX);
}

vector<int> Grid::GetNeighborsIndex(Coordinates coord) const
{
  vector<int> output;
  int index;

  coord.m_posX++;
  if (IsCellFull(coord,index))
    {
      output.push_back(index);
    }
  coord.m_posY++;
  if (IsCellFull(coord,index))
    {
      output.push_back(index);
    }
  coord.m_posX--;
  if (IsCellFull(coord,index))
    {
      output.push_back(index);
    }
  coord.m_posX--;
  if (IsCellFull(coord,index))
    {
      output.push_back(index);
    }
  coord.m_posY--;
  if (IsCellFull(coord,index))
    {
      output.push_back(index);
    }
  coord.m_posY--;
  if (IsCellFull(coord,index))
    {
      output.push_back(index);
    }
  coord.m_posX++;
  if (IsCellFull(coord,index))
    {
      output.push_back(index);
    }
  coord.m_posX++;
  if (IsCellFull(coord,index))
    {
      output.push_back(index);
    }
  return output;
}


void Grid::ResolveAttacks()
{
  for (unsigned int i = 0; i < m_entities.size(); i++)
    {
      vector<int> targets = GetNeighborsIndex(m_entities[i]->GetCoord());
      std::uniform_int_distribution<uint32_t> dist(0, targets.size()-1);
      int chosenOne = dist(m_rng);
      if (targets.size() > 0)
        {
          m_entities[targets[chosenOne]]->TakeDamage(m_entities[i]);
        }
    }
  vector<Entity*> bufferAlive;
   for (unsigned int i = 0; i < m_entities.size(); i++)
    {
      if (!m_entities[i]->IsAlive())
        {
          delete m_entities[i];
        }
      else
        {
          bufferAlive.push_back(m_entities[i]);
        }
    }
   m_entities = bufferAlive;
}
