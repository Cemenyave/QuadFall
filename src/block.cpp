#include "block.h"
#include "defines.h"

Block::Block() 
  : rect(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE))
{
  rect.setFillColor(sf::Color::Green);
  rect.setPosition(375, 0);
}

void Block::moveDown() {
  if (rect.getSize().y + rect.getPosition().y <= 550) {
    rect.move(0, 50);
  } else {
    rect.setPosition(375, 0);
  }
}

void Block::moveLeft() {
  rect.move(-50, 0);
}

void Block::moveRight() {
  rect.move(50, 0);
}

void Block::draw(sf::RenderWindow &window) {
  window.draw(rect);
}

bool Block::isOnBottom() {
  return rect.getSize().y + rect.getPosition().y <= 550;
}
