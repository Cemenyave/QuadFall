#ifndef _GAME_OVER_SCENE_IONCE
#define _GAME_OVER_SCENE_IONCE
#pragma once

#include "scene.h"
#include "keyboardHandler.h"


class GameOverScene : public Scene, public IKeyboardInputHandler {
public:
  GameOverScene();

  void update(float deltaSec) {}
  void render(sf::RenderWindow &window);
  void pause() {}
  void resume() {}


  virtual bool onKeyPressed(const sf::Keyboard::Key code, const KeyModifier key_modifiers);
  virtual bool onKeyRelease(const sf::Keyboard::Key code, const KeyModifier key_modifiers) { return false; }
private:
  int score;
};


#endif
