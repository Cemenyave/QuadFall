#include "score.h"

Score::Score()
  : score(0)
{}


void Score::reset() {
  score = 0;
}


void Score::addScore(int rowsCleared, int level) {
  score += (rowsCleared + 1) * 100 * level;
}
