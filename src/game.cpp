#include "game.h"
#include "defines.h"
Game::Game() {
  //create window
  window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_CAPTION);
}

void Game::restart() {
  gameTurnTime = sf::seconds(1.0f);
  timeFromLastTurn = sf::microseconds(0);

  blocks.clear();
  blocks.push_back(Block());
}

void Game::run() {
  while (window.isOpen()) {
    handleInput();
    update();
    render();
  }
}

void Game::update() {
  timeFromLastTurn += actClock.restart();

  if (timeFromLastTurn > gameTurnTime) {
    timeFromLastTurn = sf::microseconds(0);
    blocks.back().moveDown();
  }
}

void Game::handleInput() {
  sf::Event Event;
  while (window.pollEvent(Event)) {
    if (Event.type == sf::Event::Closed)
      window.close();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      blocks.back().moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      blocks.back().moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      blocks.back().moveDown();
    }
  }
}

void Game::render() {
  window.clear(sf::Color::Black);
  for (std::vector<Block>::iterator i = blocks.begin(); i != blocks.end(); ++i) {
      i->draw(window);
  }
  window.display();
}
