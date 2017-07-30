#ifndef _QUADFALL_CONTROLS_IONCE
#define _QUADFALL_CONTROLS_IONCE
#pragma once

#include "keyboardHandler.h"

class QuadfallController;

class QuadfallControls : public IKeyboardInputHandler {
  QuadfallController * controller = nullptr;
public:
  void init();
  void setController(QuadfallController * controller_to_set) { controller = controller_to_set; }
  virtual bool onKeyPressed(const sf::Keyboard::Key code, const KeyModifier key_modifiers);
  virtual bool onKeyRelease(const sf::Keyboard::Key code, const KeyModifier key_modifiers) { return false; }
};

#endif
