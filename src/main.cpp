#include "game.h"
#include "gameScene.h"

int main(int argc, char* argv[]) {
  init_game();

  game->startScene(new GameScene());
  game->run();

  terminate_game();

  return 0;
}
