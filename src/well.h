#ifndef _WELL_IONCE
#define _WELL_IONCE
#pragma once

#include <vector>

#include "defines.h"
#include "block.h"

class Well {

  //0,0 bottom left cell of the well
  int content[WELL_WIDTH * WELL_HEIGHT];

  //bitarray of rows which should be cleared
  size_t rowsToClear;

public:
  Well();

  void testRows();
  void setRowToClear(size_t row_number);
  bool shouldClearRow(size_t row_number);
  void clearFullRows();

  size_t getWidth() const;
  size_t getHeight() const;

  bool isCellFree(size_t rowNumber, size_t collNumber) const;
};

#endif
