#ifndef _PAUSE_SCENE_IONCE
#define _PAUSE_SCENE_IONCE
#pragma once

#include "scene.h"
#include "keyboardHandler.h"


class PauseScene : public Scene, public IKeyboardInputHandler {
public:
  PauseScene();

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
