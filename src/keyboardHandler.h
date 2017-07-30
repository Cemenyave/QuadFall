#ifndef _KEYBOARD_HANDLER_IONCE
#define _KEYBOARD_HANDLER_IONCE
#pragma once

#include <inttypes.h>

#include <SFML/Window/Keyboard.hpp>

typedef uint8_t KeyModifier;

enum KeyModifiersList {
  ALT = 0x1,
  CONTROL = 0x2,
  SHIFT = 0x4,
  SYSTEM = 0x8,
};

class IKeyboardInputHandler {
public:
  virtual bool onKeyPressed(const sf::Keyboard::Key code, const KeyModifier key_modifiers) = 0;
  virtual bool onKeyRelease(const sf::Keyboard::Key code, const KeyModifier key_modifiers) = 0;
};

#endif
