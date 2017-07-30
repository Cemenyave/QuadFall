#ifndef _GAME_SCENE_IONCE
#define _GAME_SCENE_IONCE


#include "scene.h"
#include "quadfallController.h"
#include "defines.h"
#include "quadfallControls.h"


class GameScene : public Scene {
  QuadfallControls controls;

public:

  GameScene();
  virtual void update(float deltaSec);
  virtual void render(sf::RenderWindow &window);
  virtual void pause();
  virtual void resume();
};


#endif
