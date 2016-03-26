#ifndef _GAME_IONCE
#define _GAME_IONCE
#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "well.h"
#include "renderer.h"

class Game {

  sf::Clock actClock;
  sf::Time gameTurnTime;// = sf::seconds(1.0f);
  sf::Time timeFromLastTurn; // = sf::microseconds(0);

  sf::RenderWindow window;

  Well well;
  Renderer renderer;

public:
  Game();

  //Manages running of game cycle
  void run();

  //Drop game state
  void restart();

  //Update dame state
  void update();

  virtual void handleInput();

  virtual void render();
};
#endif
