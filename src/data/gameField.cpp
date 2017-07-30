#include "gameField.h"

#include <SFML/System/Vector2.hpp>


GameField::GameField(int in_width, int in_height)
  : width(in_width)
  , height(in_height)
{
  simpleField = new TetrominoType::Type[width * height];
}


GameField::~GameField() {
  delete [] simpleField;
}


int GameField::index(int x, int y) const {
  return x + y * width;
}


void GameField::clear() {
  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      simpleField[index(i, j)] = TetrominoType::NULL_TYPE;
    }
  }
}


void GameField::putTetrominoToWell(const Tetromino &tet) {
  const sf::Vector2i * tetBlocks = tet.getPositions();
  for (int i = 0; i < TETROMINO_BLOCKS_COUNT; ++i) {
    simpleField[index(tetBlocks[i].x, tetBlocks[i].y)] = tet.getType();
  }
}


int GameField::clearFilledRows() {
  int rowsCleared = 0;
  for (int j = 0; j < height; ++j) {
    bool rowFilled = true;
    for (int i = 0; i < width; ++i) {
      if (simpleField[index(i, j)] == TetrominoType::NULL_TYPE) {
        rowFilled = false;
        break;
      }
    }

    if (rowFilled) {
      ++rowsCleared;

      for (int k = j - 1; k >= 0; --k) {
        for (int i = 0; i < width; ++i) {
            simpleField[index(i, k + 1)] = simpleField[index(i, k)];
            simpleField[index(i, k)] = TetrominoType::NULL_TYPE;
        }
      }
    }
  }

  return rowsCleared;
}


TetrominoType::Type GameField::getUnit(int x, int y) const {
  return simpleField[index(x, y)];
}
