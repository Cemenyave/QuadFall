#ifndef _GAME_FIELD_IONCE
#define _GAME_FIELD_IONCE

#include "tetromino.h"
#include "tetrominoType.h"

class GameField {
  int width;
  int height;

  TetrominoType::Type * simpleField;

  int index(int x, int y) const;

public:
  GameField(int width, int height);
  ~GameField();

  void clear();
  void putTetrominoToWell(const Tetromino &tet);
  int clearFilledRows();
  TetrominoType::Type getUnit(int x, int y) const;
};
#endif
