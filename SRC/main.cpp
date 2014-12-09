
#include "grid.h"
#include "player.h"
#include <vector>
#include "coordinates.h"

//Command batarde pour faire mumuz en mode texte
Command GetCommand(Command input)
{
  Command output;
  int i;
  cout << endl << "id=" << input.m_id <<endl;
      for (unsigned int i = 0 ; i < input.m_coord.size(); i++)
        {
          cout<<i<<"=> " << input.m_coord[i].m_posX << " "  <<input.m_coord[i].m_posY <<endl ;
        }
      cin >> i;
      output.m_id=input.m_id;
      output.m_coord.push_back(input.m_coord[i]);
      cout << "destination choisie : " << output.m_coord[0].m_posX << " " << output.m_coord[0].m_posY << endl;

      return output;
}

int main()
{
  Grid myGrid;
  Player P1(1,"barbare");
  Player P2(2,"batman");
  vector<Player> team1;
  vector<Player> team2;

  team1.push_back(P1);
  team2.push_back(P2);

  int idJ1=1;
  int idJ2=2;


  myGrid.Initialize(team1,team2);
  while (true)//while !myGrid.GameOver()
    {
      myGrid.PrintStatus();
      myGrid.PrintGrid();

      Command j1=myGrid.GetAvailableCommand(idJ1);
      Command J1b=GetCommand(j1);
      myGrid.GiveCommand(J1b);

      Command j2=myGrid.GetAvailableCommand(idJ2);
      Command J2b=GetCommand(j2);
      myGrid.GiveCommand(J2b);



      myGrid.RegenMana();
      myGrid.ResolveDeplacements();
      myGrid.ResolveAttacks();
      //myGrid.ResolveSpells();
      myGrid.EndTurn();
      cout << endl << endl;
    }
  return 0;
}
