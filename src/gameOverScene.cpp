#include "gameOverScene.h"
#include "game.h"


GameOverScene::GameOverScene() {
  game->setKeyboardHandler(this);
  score = game->getController()->getScore();
}


bool GameOverScene::onKeyPressed(const sf::Keyboard::Key code, const KeyModifier key_modifiers) {
  if (code == sf::Keyboard::Space) {
    game->getController()->reset();
    game->setKeyboardHandler(NULL);
    game->requestEndScene();
    return true;
  }
  return false;
}


void GameOverScene::render(sf::RenderWindow &window) {
  Renderer * renderer = game->getRenderer();
  renderer->renderShadow(window);
  renderer->renderGameOverText(score, window);
}
