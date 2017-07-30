#ifndef _TETROMINO_IONCE
#define _TETROMINO_IONCE

#include "tetrominoType.h"

const int TETROMINO_BLOCKS_COUNT = 4;

class Tetromino {
  sf::Vector2i blockPositions[TETROMINO_BLOCKS_COUNT];
  TetrominoType::Type type;

public:
  Tetromino(const TetrominoType::Type type = TetrominoType::Type::NULL_TYPE);
  TetrominoType::Type getType() const;
  void move(sf::Vector2i displacement);
  void rotateCw();
  void rotateCcw();
  const sf::Vector2i * getPositions() const { return blockPositions; }

private:
  void generateGroup();
  void rotate(bool cw);
};

#endif
