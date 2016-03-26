#include <SFML/Graphics.hpp>
#include "renderer.h"
#include "well.h"

void Renderer::renderWell(const Well &well, sf::RenderWindow &window) {
  size_t ractIndex = 0;
  //for each row in well
  for (size_t i = 0; i < well.getHeight(); ++i) {

    //for each cell in row
    for (size_t j = 0; j < well.getWidth(); ++j) {

      //if cell is not empty, get rect, calculate creen coordinate
      //set that coordinate to rect and put to render
      if (well.isCellFree(i, j)) {
        continue;
      }

      if (racts.size() < ractIndex + 1) {
        racts.push_back(sf::RectangleShape(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE)));
        racts.back().setFillColor(sf::Color::Green);
      }

      racts[ractIndex++].setPosition(
        30 + (BLOCK_SIZE + BLOCK_OFFSET) * j,
        WINDOW_HEIGHT - (BLOCK_SIZE + BLOCK_OFFSET) * (i + 1));
    }
  }

  for (size_t i = 0; i < ractIndex; ++i) {
    window.draw(racts[i]);
  }
}
