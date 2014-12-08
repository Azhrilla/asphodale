#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
 private:
  string m_pseudo;
  int m_id;
  string m_class;

 public:
  Player(int, string);
  string GetPseudo() const;
  int GetId() const;


};


#endif
