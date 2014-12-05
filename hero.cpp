#include "hero.h"

using namespace std;

Hero::Hero()
{
  m_HP = 20;
  m_name = "hero";
}

const Coordinates Hero::GetTargetDeplacement()
{
  Coordinates output = m_coord;
  cout << "hero dep : ?"<<endl;
  int dep;
  cin >> dep;

  switch (dep)
    {
    case 1:
      {
        output.m_posX -= 1;
        output.m_posY += 1;
        break;
      }
    case 2:
      {
        output.m_posY += 1;
        break;
      }
    case 3:
      {
        output.m_posX += 1;
        output.m_posY += 1;
        break;
      }
    case 4:
      {
        output.m_posX -= 1;
        break;
      }
    case 6:
      {
        output.m_posX += 1;
        break;
      }
    case 7:
      {
        output.m_posX -= 1;
        output.m_posY -= 1;
        break;
      }
    case 8:
      {
        output.m_posY -= 1;
        break;
      }
    case 9:
      {
        output.m_posX += 1;
        output.m_posY -= 1;
        break;
      }
    default:
      {
        cout << "commande non reconnue" << endl;
      }
    }
  return output;
}

void Hero::TakeDamage(Entity* foe)
{
      m_HP -= foe->Attack(this);
      cout << m_name <<" took " << foe->Attack(this) << " damages from " << foe->GetName()<< endl;
}
 
 const int Hero::Attack(Entity* target)
 {
      return 0;
    }
 
 const bool Hero::IsAlive()
 {
      return (m_HP > 0);
    }
