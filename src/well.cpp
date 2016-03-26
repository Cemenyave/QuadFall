#include <iostream>
#include "well.h"

Well::Well()
{
  memset(content, 0, WELL_WIDTH * WELL_HEIGHT * (sizeof(int)));

  for (size_t i = 0; i < WELL_WIDTH; ++i) {
    content[i] = 1;
  }
}

void Well::testRows() {
  for (int i = 0; i < WELL_HEIGHT; ++i) {
    bool rowIsFull = true;
    for (int j = 0; j < WELL_WIDTH; ++j) {
      if (content[i * WELL_WIDTH + j] == 0) {
        rowIsFull = false;
        break;
      }
    }

    if (rowIsFull) {
      setRowToClear(i);
    }
  }
}

void Well::setRowToClear(size_t row_number) {
  rowsToClear |= 1 << row_number;
}

bool Well::shouldClearRow(size_t row_number) {
  return 1 << row_number & rowsToClear;
}

void Well::clearFullRows() {
  for (size_t i = 0; i < WELL_HEIGHT; ++i) {
    if (!shouldClearRow(i)) {
      continue;
    }

    for (size_t j = 0; j < WELL_WIDTH; ++j) {
      content[i * WELL_WIDTH + j] = 0;
    }
  }
}

size_t Well::getWidth() const {
  return WELL_WIDTH;
}

size_t Well::getHeight() const {
  return WELL_HEIGHT;
}

bool Well::isCellFree(size_t rowNumber, size_t collNumber) const {
  return content[rowNumber * WELL_WIDTH + collNumber] == 0;
}

