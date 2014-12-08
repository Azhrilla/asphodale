
#include "grid.h"
#include "player.h"
#include <vector>

int main()
{
  Grid myGrid;


  Player P1(0,"barbare");
  Player P2(2,"batman");
  vector<Player> team1;
  team1.push_back(P1);
  vector<Player> team2;
  team2.push_back(P2);

  myGrid.Initialize(team1,team2);

  while (true)//while !myGrid.GameOver()
    {
      myGrid.PrintStatus();
      myGrid.PrintGrid();
      //myGrid.GetAvailableDeplacements();
      //myGrid.GetAvailableSpells();
      myGrid.RegenMana();
      myGrid.ResolveDeplacements();
      myGrid.ResolveAttacks();
      //myGrid.ResolveSpells();
    }
  return 0;
}
