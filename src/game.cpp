#include "game.h"
#include "defines.h"

Game::Game() 
  : well()
  , renderer()
{
  //create window
  window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_CAPTION);
}

void Game::restart() {
  gameTurnTime = sf::seconds(1.0f);
  timeFromLastTurn = sf::microseconds(0);
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
    //moveDown();
  }
}

void Game::handleInput() {
  sf::Event Event;
  while (window.pollEvent(Event)) {
    if (Event.type == sf::Event::Closed)
      window.close();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      //moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      //moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      //moveDown();
    }
  }
}

void Game::render() {
  window.clear(sf::Color::Black);
  renderer.renderWell(well, window);
  window.display();
}
