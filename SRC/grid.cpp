#include "grid.h"

using namespace std;

Grid::Grid()
{
  unsigned seed
    = std::chrono::system_clock::now().time_since_epoch().count();
  m_rng.seed(seed);
}

// Créé la grid et initialise les joueurs.
void Grid::Initialize(vector<Player> team1, vector<Player> team2)
{
  if (team1.size() != team2.size())
    {
      cout << "equipes de taille différentes !!" <<endl;
      // faudrait throw une erreur en théorie
    }
  if (team1.size() == 1)
    {
      m_dimX = 5;
      m_dimY = 5;

      CreateCells();
      Hero* player1 = new Hero;
      Hero* player2 = new Hero;
      player1->Initialize(team1[0].GetId(), &m_cells[0][2],
                          team1[0].GetPseudo(),1);
      player2->Initialize(team2[0].GetId(), &m_cells[4][2],
                          team2[0].GetPseudo(),2);

      m_entities.push_back(player1);
      m_entities.push_back(player2);
    }

}

void Grid::CreateCells()
{
  m_cells = new Cell* [m_dimX];
  for (unsigned int i = 0; i < m_dimX; i++)
    {
      m_cells[i] = new Cell[m_dimY];
    }
  for (unsigned int i = 0; i < m_dimX; i++)
    {
      for (unsigned int j = 0; j < m_dimY; j++)
        {
          m_cells[i][j].SetCoord(i,j);
        }
    }
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
      m_entities[i]->SetCoord(&m_cells[x][y]);
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
  return (coord.m_posY >= m_dimY || coord.m_posX >= m_dimX);
}

// Recupere les voisins sous la forme d'un vecteur des index (index sur le
// vecteur m_entities)
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

// Resolve the attacks from entities if needed
void Grid::ResolveAttacks()
{
  // Pour chaque entité
  for (unsigned int i = 0; i < m_entities.size(); i++)
    {
      // Recupère les voisins
      vector<int> targets = GetNeighborsIndex(m_entities[i]->GetCoord());
      // Enleve les cibles innataquables.
      for (unsigned int j = 0; j < targets.size(); j++)
        {
          if (!m_entities[i]->CanAttack(m_entities[targets[j]]))
            {
              targets.erase(targets.begin()+j);
              j--;
            }
        }
      // choisi une cible au hasard
      if (targets.size() > 0)
        {
          std::uniform_int_distribution<uint32_t> dist(0, targets.size()-1);
          int chosenOne = dist(m_rng);
          m_entities[targets[chosenOne]]->TakeDamage(m_entities[i]);
        }
    }

  CheckAlive();
}

// Check the entities to see if some are dead.
void Grid::CheckAlive()
{
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


void Grid::RegenMana()
{
  for (unsigned int i = 0; i < m_entities.size(); i++)
    {
      m_entities[i]->RegenMana();
    }
}

void Grid::PrintStatus() const
{
  for (unsigned int i = 0; i < m_entities.size(); i++)
    {
      m_entities[i]->PrintStatus();
    }
}
