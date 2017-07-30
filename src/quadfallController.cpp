#include "quadfallController.h"
#include "game.h"
#include "gameOverScene.h"

#include <cstdlib>
#include <time.h>

static bool chek_uint(const GameField &gameField, const sf::Vector2i &pos) {
  if (pos.y == WELL_HEIGHT ||
      pos.x == WELL_WIDTH ||
      pos.x < 0 ||
      gameField.getUnit(pos.x, pos.y) != TetrominoType::NULL_TYPE) {
    return false;
  }
  return true;
}


static bool check(const GameField &gameField, const Tetromino &currentTet) {
  const sf::Vector2i * tetBlocks = currentTet.getPositions();
  for (int i = 0; i < TETROMINO_BLOCKS_COUNT; ++i) {
    if (!chek_uint(gameField, tetBlocks[i])) {
      return false;
    }
  }

  return true;
}


void QuadfallController::init() {
  reset();
}


void QuadfallController::reset() {
  srand(time(NULL));
  gameOver = false;
  gameTurnTimeSec = 0.5f;
  timeFromLastTurnSec = 0.f;
  gameField.clear();
  level = 1;
  score.reset();

  history[0] = TetrominoType::O;
  history[1] = TetrominoType::S;
  history[2] = TetrominoType::Z;
  history[3] = TetrominoType::NULL_TYPE;

  for (int i = 0; i < NEXT_TET_COUNT; ++i) {
    nextTet[i] = Tetromino(getRandomType());
  }
  spawnNewTetramin();
}


bool QuadfallController::checkHistory(TetrominoType::Type new_type) {
  return history[3] != new_type;
}


TetrominoType::Type QuadfallController::getRandomType() {
  TetrominoType::Type newType = TetrominoType::NULL_TYPE;

  while (true) {
    int rndres = std::rand();
    newType = TetrominoType::Type(rndres % TetrominoType::Type::TypeCount);

    if (!checkHistory(newType)) {
      continue;
    }

    break;
  }

  addToHistory(newType);
  return newType;
}


void QuadfallController::addToHistory(TetrominoType::Type new_type) {
  for (size_t i = 3; i > 0; --i) {
    history[i] = history[ i - 1 ];
  }

  history[0] = new_type;
}


void QuadfallController::update(float deltaSec) {
  if (gameOver || paused) {
    return;
  }
  timeFromLastTurnSec += deltaSec;
  if (timeFromLastTurnSec > gameTurnTimeSec) {
    timeFromLastTurnSec = 0.f;
    if (!moveDown()) {
      gameField.putTetrominoToWell(currentTet);
      spawnNewTetramin();
      if (!check(gameField, currentTet)) {
        gameOver = true;
        game->startScene(new GameOverScene);
      }
      int cleared = gameField.clearFilledRows();
      if (cleared > 0) {
        score.addScore(cleared, 1);
        clearedLinesCount += cleared;

        if (clearedLinesCount >= 10) {
          level++;
          gameTurnTimeSec -= .05f;
        }
      }
    }
  }
}


void QuadfallController::spawnNewTetramin() {
  currentTet = nextTet[0];
  for (int i = 1; i < NEXT_TET_COUNT; ++i) {
    nextTet[i - 1] = nextTet[i];
  }
  nextTet[NEXT_TET_COUNT - 1] = Tetromino(getRandomType());
}


bool QuadfallController::moveDown() {
  currentTet.move(sf::Vector2i(0, 1));
  if (!check(gameField, currentTet)) {
    currentTet.move(sf::Vector2i(0, -1));
    return false;
  }
  return true;
}


void QuadfallController::rotateCurrentTetromino() {
  currentTet.rotateCw();
  if (!check(gameField, currentTet)) {
    currentTet.rotateCcw();
  }
}


void QuadfallController::moveLeft() {
  currentTet.move(sf::Vector2i(-1, 0));
  if (!check(gameField, currentTet)) {
    currentTet.move(sf::Vector2i(1, 0));
  }
}


void QuadfallController::moveRight() {
  currentTet.move(sf::Vector2i(1, 0));
  if (!check(gameField, currentTet)) {
    currentTet.move(sf::Vector2i(-1, 0));
  }
}


void QuadfallController::softDrop() {
  moveDown();
}
