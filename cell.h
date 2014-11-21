#include "coordinates.h"

class Cell
{
 private:
  Coordinates m_coord;
 public:
  Cell();
  void SetCoord(unsigned int, unsigned int);
  const void PrintCoord();
};
