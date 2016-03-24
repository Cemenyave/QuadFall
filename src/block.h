#ifndef _BLOCK_IONCE
#define _BLOCK_IONCE
#pragma once

#include <SFML/Graphics.hpp>

class Block {
  sf::RectangleShape rect;

public:
  Block();

  void moveDown();
  void moveLeft();
  void moveRight();
  void draw(sf::RenderWindow &window);
  bool isOnBottom();
};

#endif
