#ifndef COMMAND_H
#define COMMAND_H

#include "coordinates.h"
#include <vector>

using namespace std;

class Command
{
 public:
  vector<Coordinates> m_coord;
  int m_id;
};

#endif
