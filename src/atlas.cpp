#include "atlas.h"
#include <SFML/Graphics/Rect.hpp>

#include <iostream>


Atlas::Atlas()
  : atlas()
{
  if (!atlas.loadFromFile("block_atlas.png") ) {
    std::cout << "failed to load texture" << std::endl;
  }

  if (!background.loadFromFile("background.png")) {
    std::cout << "failed to load background" << std::endl;
  }
}


sf::Texture& Atlas::getTexture() {
  return atlas;
}


const sf::Texture& Atlas::getBackground() const {
  return background;
}
