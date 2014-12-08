
#include "grid.h"

int main()
{
  Grid myGrid;
  myGrid.Initialize(5,5,1,2);
  while (true)
    {
      myGrid.PrintStatus();
      myGrid.PrintGrid();
      myGrid.RegenMana();
      myGrid.ResolveDeplacements();
      myGrid.ResolveAttacks();
    }
  return 0;
}
