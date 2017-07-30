#ifndef _TETROMINO_TYPE_IONCE
#define _TETROMINO_TYPE_IONCE

#include <SFML/System/Vector2.hpp>

namespace TetrominoType {

  enum Type {
    NULL_TYPE = -1,
    L,
    J,
    I,
    S,
    Z,
    T,
    O,
    TypeCount
  };

  sf::Vector2i getCellPosition(Type type, size_t cellNumber);
  sf::Vector2i getSpriteOffset(Type type);
};

#endif
