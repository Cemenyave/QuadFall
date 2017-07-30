#ifndef _QUADFALLCONTROLLER_IONCE
#define _QUADFALLCONTROLLER_IONCE
#pragma once

#include "defines.h"
#include <SFML/System/Time.hpp>
#include "data/tetrominoType.h"
#include "data/tetromino.h"
#include "data/gamefield.h"
#include "score.h"

class QuadfallController {
  Tetromino currentTet;
  Tetromino nextTet[NEXT_TET_COUNT];
  GameField gameField = GameField(WELL_WIDTH, WELL_HEIGHT);
  int level = 0;
  Score score;
  bool gameOver = false;
  bool paused = false;
  TetrominoType::Type history[4];

  int clearedLinesCount = 0;

  float gameTurnTimeSec;
  float timeFromLastTurnSec;

public:
  void init();
  void reset();
  void update(float deltasec);

  const Tetromino * getCurrentTetromino() const { return &currentTet; }
  const Tetromino * getNextTetromino() const { return nextTet; }
  const GameField &getGameField() const { return gameField; }
  int getScore() const { return score.getScore(); }
  int getLevel() const { return level; }

  void pause() { paused = true; }
  void resume() { paused = false; }

  //input reaction
  void rotateCurrentTetromino();
  void moveLeft();
  void moveRight();
  void softDrop();

private:
  void spawnNewTetramin();
  bool moveDown();

  TetrominoType::Type getRandomType();
  void addToHistory(TetrominoType::Type new_type);
  bool checkHistory(TetrominoType::Type new_type);
};

#endif
