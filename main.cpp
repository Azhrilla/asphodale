
#include "grid.h"

int main()
{
  Grid myGrid;
  myGrid.Initialize(5,5);
  while (true)
    {
      myGrid.PrintGrid();
      myGrid.ResolveDeplacements();
      myGrid.ResolveAttacks();
    }
  return 0;
}
