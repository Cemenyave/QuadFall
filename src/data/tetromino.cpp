#include "tetromino.h"

Tetromino::Tetromino(const TetrominoType::Type type)
  : type(type)
{
  generateGroup();
}


TetrominoType::Type Tetromino::getType() const {
  return type;
}


void Tetromino::move(sf::Vector2i displacement) {
  for (int i = 0; i < TETROMINO_BLOCKS_COUNT; ++i) {
    blockPositions[i] += displacement;
  }
}


void Tetromino::rotate(bool cw) {
  sf::Vector2i o = blockPositions[1];
  for (int i = 0; i < TETROMINO_BLOCKS_COUNT; ++i) {
    //to local space
    blockPositions[i].x = blockPositions[i].x - o.x;
    blockPositions[i].y = blockPositions[i].y - o.y;

    int newX = (cw ? -1 :  1) * blockPositions[i].y;
    int newY = (cw ?  1 : -1) * blockPositions[i].x;

    //rotate
    blockPositions[i].x = newX;
    blockPositions[i].y = newY;

    //to field space
    blockPositions[i].x += o.x;
    blockPositions[i].y += o.y;
  }
}


void Tetromino::rotateCw() {
  rotate(true);
}


void Tetromino::rotateCcw() {
  rotate(false);
}


void Tetromino::generateGroup() {
  for (int i = 0; i < TETROMINO_BLOCKS_COUNT; ++i) {
    blockPositions[i] = TetrominoType::getCellPosition(type, i);
  }
}
