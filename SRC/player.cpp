#include "player.h"

Player::Player(int id, string pseudo)
{
  m_id = id;
  m_pseudo = pseudo;
}

string Player::GetPseudo() const
{
  return m_pseudo;
}

int Player::GetId() const
{
  return m_id;
}
