#include "hero.h"

using namespace std;

Hero::Hero()
{
  m_HP = 20;
  m_name = "unnamed_hero";
  m_mana["red"] = 5;
  m_mana["blue"] = 5;
  m_mana["green"] = 5;
  m_mana["black"] = 5;
}

Hero::~Hero()
{}

Coordinates Hero::GetTargetDeplacement()
{
  return m_coordWanted;
}

void Hero::TakeDamage(Entity* foe)
{
   m_HP -= foe->Attack(this);
   cout << m_name <<" took " << foe->Attack(this) << " damages from "
        << foe->GetName()<< endl;
}

bool Hero::IsAlive() const
{
   return (m_HP > 0);
}

void Hero::Initialize(int id, Cell* cell, string pseudo, int team)
{
   m_currentCell = cell;
   m_coord = cell->GetCoord();
   m_id = id;
   m_name = pseudo;
   m_team = team;
}

bool Hero::CanAttack(Entity*) const
{
   return false;
}

void Hero::RegenMana()
{
  m_currentCell->GiveMana(m_mana);
}

void Hero::PrintStatus()
{
      cout << "i am "<< m_name << " & i have " << m_HP << " pvs." << endl;
      cout << "blue= " << m_mana["blue"] << " red= " <<m_mana["red"] <<
        " green= " << m_mana["green"]<< " black= " <<m_mana["black"] << endl;
}

int Hero::GetId() const
{
  return m_id;
}

void Hero::SetCommand(Command order)
{
  m_coordWanted = order.m_coord[0];
}
