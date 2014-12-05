#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>
#include <vector>

using namespace std;

class Coordinates
{
 public:
  unsigned int m_posX;
  unsigned int m_posY;

 public:
  Coordinates();
  Coordinates(int, int);
};


const bool operator==(Coordinates const&, Coordinates const&);
const vector<int> ExtractDuplicatesIndex(const vector<Coordinates>);

#endif
