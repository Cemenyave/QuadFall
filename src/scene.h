#ifndef _SCENE_IONCE
#define _SCENE_IONCE
#pragma once

#include <SFML/Graphics.hpp>


class Scene {
  Scene operator =(Scene &s) { return *this; }
public:
  virtual void render(sf::RenderWindow &window) = 0;
  virtual void update(float deltaSec) = 0;
  virtual void pause() = 0;
  virtual void resume() = 0;
};


#endif
