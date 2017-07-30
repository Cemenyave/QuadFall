#ifndef _GAME_IONCE
#define _GAME_IONCE
#pragma once

#include <SFML/Graphics.hpp>

#include "scene.h"
#include "quadfallController.h"
#include "renderer.h"

#include <vector>
#include <queue>


class IKeyboardInputHandler;

typedef Scene (*t_scenePointer);
typedef std::vector<t_scenePointer> t_sceneStack;
typedef std::queue<t_scenePointer> t_sceneQueue;


class Game {
  sf::Clock actClock;
  sf::RenderWindow window;

  t_sceneStack sceneStack;
  t_sceneQueue sceneStackSuspended;
  bool endScene = false;

  IKeyboardInputHandler * kbdHandler = nullptr;

  QuadfallController controller;
  Renderer renderer;

public:
  Game();

  void startScene(t_scenePointer scene);
  void requestEndScene();

  void setKeyboardHandler(IKeyboardInputHandler * kbd_handler);

  //Manages running of game cycle
  void run();

  //Update game state
  void update();

  void render();


  QuadfallController * getController() { return &controller; }
  Renderer * getRenderer() { return &renderer; }

private:
  void registerNewScenes();
  void endLastScene();

};


void init_game();
void terminate_game();


extern Game * game;
#endif
