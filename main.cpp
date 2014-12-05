
#include "grid.h"

int main()
{
  Grid myGrid;
  myGrid.Initialize(5,5);
  while (true)
    {
      myGrid.PrintGrid();
      myGrid.ResolveDeplacements();
      int i;
      cin >>i;
    }
  return 0;
}
