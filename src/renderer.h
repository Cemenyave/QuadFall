#ifndef _RENDERER_IONCE
#define _RENDERER_IONCE

#include <SFML/Graphics.hpp>
#include "data/gameField.h"
#include "data/tetrominoType.h"

#include "atlas.h"

class Tetromino;


namespace sf {
  class RenderWindow;
  class Drawable;
  class RectangleShape;
};


enum TextAlign {
  ALIGN_LEFT,
  ALIGN_RIGHT,
  ALIGN_CENTER
};


/**
 * Renderer class holds all view objects (sptes, texts, etc.)
 * and translates game state to actual images on screen
 **/
class Renderer {
  Atlas atlas;
  sf::Font font;
public:
  Renderer();

  void renderBackground(sf::RenderWindow &window);
  void renderField(
    const GameField &gameField,
    int widht,
    int height,
    sf::RenderWindow &window
  );
  void renderTetromino(const Tetromino * tetromino, sf::RenderWindow &window);
  void renderTetrominoPreview(const Tetromino * tetromino, int count, sf::RenderWindow &window);

  void renderString(const char * str, int pos_x, int pos_y, TextAlign align, sf::RenderWindow &window);
  void renderScore(int score, sf::RenderWindow &window);
  void renderLevel(int level, sf::RenderWindow &window);
  void renderHelp(sf::RenderWindow &window);

  void renderShadow(sf::RenderWindow &window);
  void renderGameOverText(int score, sf::RenderWindow &window);

  void renderPauseText(sf::RenderWindow &window);

private:
  void renderBlock(int px_x, int px_y, TetrominoType::Type t, sf::RenderWindow &window);
  void renderBlockOnField(int x, int y, TetrominoType::Type t, sf::RenderWindow &window);

};

#endif
