#include "../defines.h"
#include "tetrominoType.h"


const static sf::Vector2i colors [TetrominoType::Type::TypeCount] = {
  sf::Vector2i(6 * BLOCK_SIZE, 0),
  sf::Vector2i(5 * BLOCK_SIZE, 0),
  sf::Vector2i(0 * BLOCK_SIZE, 0),
  sf::Vector2i(3 * BLOCK_SIZE, 0),
  sf::Vector2i(4 * BLOCK_SIZE, 0),
  sf::Vector2i(2 * BLOCK_SIZE, 0),
  sf::Vector2i(1 * BLOCK_SIZE, 0),
};


const static sf::Vector2i cellPositions[TetrominoType::Type::TypeCount][4] = {
  {//L
    sf::Vector2i(0, 1),
    sf::Vector2i(1, 1),
    sf::Vector2i(2, 1),
    sf::Vector2i(2, 0),
  },

  {//J
    sf::Vector2i(2, 1),
    sf::Vector2i(1, 1),
    sf::Vector2i(0, 1),
    sf::Vector2i(0, 0),
  },

  {//I
    sf::Vector2i(0, 0),
    sf::Vector2i(1, 0),
    sf::Vector2i(2, 0),
    sf::Vector2i(3, 0),
  },

  {//S
    sf::Vector2i(0, 1),
    sf::Vector2i(1, 1),
    sf::Vector2i(1, 0),
    sf::Vector2i(2, 0),
  },

  {//Z
    sf::Vector2i(2, 1),
    sf::Vector2i(1, 1),
    sf::Vector2i(1, 0),
    sf::Vector2i(0, 0),
  },

  {//T
    sf::Vector2i(2, 1),
    sf::Vector2i(1, 1),
    sf::Vector2i(1, 0),
    sf::Vector2i(0, 1),
  },

  {//O
    sf::Vector2i(0, 0),
    sf::Vector2i(1, 1),
    sf::Vector2i(0, 1),
    sf::Vector2i(1, 0),
  }
};


sf::Vector2i TetrominoType::getCellPosition(Type type, size_t cellNumber) {
  return cellPositions[type][cellNumber];
}


sf::Vector2i TetrominoType::getSpriteOffset(Type type) {
  return colors[type];
}
