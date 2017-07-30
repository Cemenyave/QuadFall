#include "pauseScene.h"
#include "game.h"


PauseScene::PauseScene() {
  game->setKeyboardHandler(this);
}


bool PauseScene::onKeyPressed(const sf::Keyboard::Key code, const KeyModifier key_modifiers) {
  if (code == sf::Keyboard::Escape) {
    game->setKeyboardHandler(NULL);
    game->requestEndScene();
    return true;
  }
  return false;
}


void PauseScene::render(sf::RenderWindow &window) {
  Renderer * renderer = game->getRenderer();
  renderer->renderShadow(window);
  renderer->renderPauseText(window);
  renderer->renderHelp(window);
}
