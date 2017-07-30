#include <SFML/Graphics.hpp>
#include "renderer.h"
#include "data/tetromino.h"
#include "defines.h"

#include <string>

Renderer::Renderer()
{
  font.loadFromFile(FONT);
}


void Renderer::renderBlock(int px_x, int px_y, TetrominoType::Type t, sf::RenderWindow &window) {
  static sf::Sprite block(atlas.getTexture());
  block.setTextureRect(sf::IntRect(TetrominoType::getSpriteOffset(t), sf::Vector2i(BLOCK_SIZE, BLOCK_SIZE)));
  block.setPosition(px_x, px_y);
  window.draw(block);
}


void Renderer::renderBlockOnField(int x, int y, TetrominoType::Type t, sf::RenderWindow &window) {
  //don't draw two hidden rows
  if (y < 2) {
    return;
  }

  renderBlock(FIELD_X + x * BLOCK_SIZE, FIELD_Y + (y - 2) * BLOCK_SIZE, t, window);
}


void Renderer::renderField(
    const GameField &gameField,
    int widht,
    int height,
    sf::RenderWindow &window
) {
  for (int i = 0; i < widht; ++i) {
    for (int j = 0; j < height; ++j) {
      TetrominoType::Type t = gameField.getUnit(i, j);
      if (t != TetrominoType::NULL_TYPE) {
        renderBlockOnField(i, j, t, window);
      }
    }
  }
}


void Renderer::renderBackground(sf::RenderWindow &window) {
  static sf::Sprite background(atlas.getBackground());
  window.draw(background);
}


void Renderer::renderTetromino(const Tetromino * tetromino, sf::RenderWindow &window) {
  const sf::Vector2i * tetBlocks = tetromino->getPositions();
  for (int i = 0; i < 4; ++i) {
    renderBlockOnField(tetBlocks[i].x, tetBlocks[i].y, tetromino->getType(), window);
  }
}


void Renderer::renderTetrominoPreview(const Tetromino * tetromino, int count, sf::RenderWindow &window) {
  for (int i = 0; i < count; ++i) {
    const sf::Vector2i * tetBlocks = tetromino[i].getPositions();

    int minX = tetBlocks[0].x;
    int maxX = tetBlocks[0].x;
    int minY = tetBlocks[0].y;
    int maxY = tetBlocks[0].y;
    for (int i = 0; i < 4; ++i) {
      if (minX > tetBlocks[i].x) {
        minX = tetBlocks[i].x;
      }
      if (maxX < tetBlocks[i].x) {
        maxX = tetBlocks[i].x;
      }

      if (minY > tetBlocks[i].y) {
        minY = tetBlocks[i].y;
      }
      if (maxY < tetBlocks[i].y) {
        maxY = tetBlocks[i].y;
      }
    }

    int tetWidthPx = (maxX - minX + 1) * BLOCK_SIZE;
    int tetHeightPx = (maxY - minY + 1) * BLOCK_SIZE;

    int oX = PREVIEW_X + (PREVIEW_SIZE - tetWidthPx) / 2;
    int oY = PREVIEW_Y + (PREVIEW_SIZE + PREVIEW_Y_OFFSET) * i + (PREVIEW_SIZE - tetHeightPx) / 2;

    for (int j = 0; j < 4; ++j) {
      renderBlock(oX + tetBlocks[j].x * BLOCK_SIZE, oY + tetBlocks[j].y * BLOCK_SIZE, tetromino[i].getType(), window);
    }
  }
}


void Renderer::renderString(const char * str, int pos_x, int pos_y, TextAlign align, sf::RenderWindow &window) {
  sf::Text t;
  t.setFont(font);
  t.setString(str);
  t.setCharacterSize(GAME_STATES_FONT_SIZE);
  t.setColor(sf::Color::White);
  if (align == ALIGN_LEFT) {
    t.setPosition(pos_x, pos_y);
  } else if (align == ALIGN_RIGHT) {
    t.setPosition(pos_x - t.getLocalBounds().width, pos_y);
  } else if (align == ALIGN_CENTER) {
    t.setPosition(pos_x - t.getLocalBounds().width * 0.5, pos_y);
  }
  window.draw(t);
}


void Renderer::renderScore(int score, sf::RenderWindow &window) {
  renderString(
      (std::string(SCORE_STRING) + std::to_string(score)).c_str(),
      SCORE_POS_X,
      SCORE_POS_Y,
      ALIGN_LEFT,
      window);
}


void Renderer::renderLevel(int level, sf::RenderWindow &window) {
  renderString(
      (std::string(LEVEL_STRING) + std::to_string(level)).c_str(),
      LEVEL_POS_X,
      LEVEL_POS_Y,
      ALIGN_LEFT,
      window);
}


void Renderer::renderHelp(sf::RenderWindow &window) {
  renderString(
      "A - move left",
      10,
      WINDOW_HEIGHT - 175,
      ALIGN_LEFT,
      window);
  renderString(
      "D - move right",
      10,
      WINDOW_HEIGHT - 140,
      ALIGN_LEFT,
      window);
  renderString(
      "Space - rotatr",
      10,
      WINDOW_HEIGHT - 105,
      ALIGN_LEFT,
      window);
  renderString(
      "S - soft drop",
      10,
      WINDOW_HEIGHT - 70,
      ALIGN_LEFT,
      window);
  renderString(
      "Esc - puase",
      10,
      WINDOW_HEIGHT - 35,
      ALIGN_LEFT,
      window);
}


void Renderer::renderShadow(sf::RenderWindow &window) {
  sf::RectangleShape shadow;
  shadow.setFillColor(sf::Color(0, 0, 0, 100));
  shadow.setPosition(0, 0);
  shadow.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));

  window.draw(shadow);
}


void Renderer::renderGameOverText(int score, sf::RenderWindow &window) {
  renderString(
      GAME_OVER_TEXT,
      WINDOW_WIDTH / 2,
      WINDOW_HEIGHT / 2 - 100,
      ALIGN_CENTER,
      window);
  renderString(
      (std::string(GAME_OVER_SCORE_TEXT) + std::to_string(score)).c_str(),
      WINDOW_WIDTH / 2,
      WINDOW_HEIGHT / 2 - 50,
      ALIGN_CENTER,
      window);
  renderString(
      GAME_OVER_RESTART_TEXT,
      WINDOW_WIDTH / 2,
      WINDOW_HEIGHT / 2,
      ALIGN_CENTER,
      window);
}


void Renderer::renderPauseText(sf::RenderWindow &window) {
  renderString(
      "Pause",
      WINDOW_WIDTH / 2,
      WINDOW_HEIGHT / 3,
      ALIGN_CENTER,
      window);
}

