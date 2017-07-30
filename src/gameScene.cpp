#include "gameScene.h"
#include "game.h" 
#include "renderer.h"


GameScene::GameScene () {
  controls.init();
  controls.setController(game->getController());
  game->setKeyboardHandler(&controls);
}


void GameScene::update(float deltaSec) {
  game->getController()->update(deltaSec);
}


void GameScene::render(sf::RenderWindow &window) {
  QuadfallController * controller = game->getController();
  Renderer * renderer = game->getRenderer();
  renderer->renderBackground(window);
  renderer->renderTetromino(controller->getCurrentTetromino(), window);
  renderer->renderTetrominoPreview(controller->getNextTetromino(), NEXT_TET_COUNT, window);
  renderer->renderField(controller->getGameField(), WELL_WIDTH, WELL_HEIGHT, window);
  renderer->renderScore(controller->getScore(), window);
  renderer->renderLevel(controller->getLevel(), window);
}


void GameScene::pause() {
  game->getController()->pause();
}


void GameScene::resume() {
  game->getController()->resume();
  game->setKeyboardHandler(&controls);
}
