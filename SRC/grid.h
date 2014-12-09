#ifndef GRID_H
#define GRID_H


#include "player.h"
#include "cell.h"
#include <vector>
#include "entity.h"
#include "entity.h"
#include "coordinates.h"
#include <iostream>
#include "monster.h"
#include "hero.h"
#include "command.h"

class Grid
{
 private:
  typedef std::mt19937 MyRNG;
  MyRNG m_rng;
  Cell** m_cells;
  std::vector<Entity*> m_entities;
  unsigned int m_dimX;
  unsigned int m_dimY;
  vector<Entity*> m_playerEntities;
  unsigned int m_turn;


 public:
  Grid();
  void Initialize(vector<Player>, vector<Player>);
  void ResolveDeplacements();
  void ResolveAttacks();
  void CreateCells();
  void PrintGrid() const;
  bool IsCellFull(Coordinates, int&) const;
  bool DeplacementImpossible(Coordinates) const;
  vector<int> GetNeighborsIndex(Coordinates) const;
  void CheckAlive();
  void RegenMana();
  void PrintStatus() const;
  void EndTurn();
  Command GetAvailableCommand(int) const;
  void GiveCommand(Command);
};


#endif




