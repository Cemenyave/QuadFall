#ifndef _SCORE_IONCE
#define _SCORE_IONCE
#pragma once

class Score {
  unsigned int score;

public:
  Score();

  void reset();
  void addScore(int rowsCleared, int level);
  unsigned int getScore() const { return score; }
};

#endif
