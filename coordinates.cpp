#include "coordinates.h"


Coordinates::Coordinates()
{
  m_posX = 0;
  m_posY = 0;
}

Coordinates::Coordinates(int x, int y)
{
  m_posX = x;
  m_posY = y;
}

bool operator==(Coordinates const& lhs, Coordinates const& rhs)
{
  return (lhs.m_posX == rhs.m_posX && lhs.m_posY == rhs.m_posY);
}

vector<int> ExtractDuplicatesIndex(const vector<Coordinates> input)
{
  vector<int> output;
  for(unsigned int i = 0; i < input.size(); i++)
    {
      for(unsigned int j = 0; j < input.size(); j++)
        {
          if(input[i] == input[j] && i != j)
            {
              output.push_back(i);
              cout << "meme destination : " << input[i].m_posX << " " << input[i].m_posY <<endl;
            }
        }
    }

  return output;
}
