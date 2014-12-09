
#include "grid.h"
#include "player.h"
#include <vector>
#include "coordinates.h"
int main()
{
  Grid myGrid;
  int i;

  Player P1(1,"barbare");
  Player P2(2,"batman");
  vector<Player> team1;
  team1.push_back(P1);
  vector<Player> team2;
  team2.push_back(P2);

  Command j1;
  Command j2;
  j1.m_id=1;
  j2.m_id=2;

  Coordinates temp;
  myGrid.Initialize(team1,team2);
  while (true)//while !myGrid.GameOver()
    {
      myGrid.PrintStatus();
      myGrid.PrintGrid();
      j1=myGrid.GetAvailableCommand(j1.m_id);
      j2=myGrid.GetAvailableCommand(j2.m_id);

      cout << endl << "id=" << j1.m_id <<endl;
      for (unsigned int i = 0 ; i < j1.m_coord.size(); i++)
        {
          cout<<i<<"=> " << j1.m_coord[i].m_posX << " "  <<j1.m_coord[i].m_posY <<endl ;
        }
      cin >> i;
      temp = j1.m_coord[i];
      j1.m_coord.clear();
      j1.m_coord.push_back(temp);
      cout << "destination choisie : " << j1.m_coord[0].m_posX << " " << j1.m_coord[0].m_posY << endl;
      myGrid.GiveCommand(j1);

      cout << endl << "id=" << j2.m_id <<endl;
      for (unsigned int i = 0 ; i < j2.m_coord.size(); i++)
        {
          cout <<i <<"=> "<<j2.m_coord[i].m_posX << " "  <<j2.m_coord[i].m_posY<<endl ;
        }

      cin >> i;
      temp = j2.m_coord[i];
      j2.m_coord.clear();
      j2.m_coord.push_back(temp);
      cout << "destination choisie : " << j2.m_coord[0].m_posX << " "<<  j2.m_coord[0].m_posY <<endl;
      myGrid.GiveCommand(j2);
      myGrid.RegenMana();
      myGrid.ResolveDeplacements();
      myGrid.ResolveAttacks();
      //myGrid.ResolveSpells();
      myGrid.EndTurn();
      cout << endl << endl;
    }
  return 0;
}
