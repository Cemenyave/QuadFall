#include "game.h"
#include "quadfallControls.h"
#include "quadfallController.h"

#include "pauseScene.h"


enum PlayerAction {
  NULL_ACTION = -1,
  MOVE_LEFT,
  MOVE_RIGHT,
  ROTATE,
  SOFT_DROP,
  ACTIONS_COUNT
};


static sf::Keyboard::Key binding[ACTIONS_COUNT];

void QuadfallControls::init() {
  binding[MOVE_LEFT] = sf::Keyboard::A;
  binding[MOVE_RIGHT] = sf::Keyboard::D;
  binding[ROTATE] = sf::Keyboard::Space;
  binding[SOFT_DROP] = sf::Keyboard::S;
}


bool QuadfallControls::onKeyPressed(
    const sf::Keyboard::Key code,
    const KeyModifier /*key_modifiers*/
) {
  if (code == sf::Keyboard::Escape) {
    game->startScene(new PauseScene);
    return true;
  }

  for (int i = 0; i < ACTIONS_COUNT; ++i) {
    if (code == binding[i]) {
      switch (PlayerAction(i)) {
        case MOVE_LEFT:
          controller->moveLeft();
          break;
        case MOVE_RIGHT:
          controller->moveRight();
          break;
        case ROTATE:
          controller->rotateCurrentTetromino();
          break;
        case SOFT_DROP:
          controller->softDrop();
          break;
        default:
          return false;
          break;
      }
      return true;
    }
  }
  return false;
}
