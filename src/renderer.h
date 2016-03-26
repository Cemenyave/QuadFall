#ifndef _RENDERER_IONCE
#define _RENDERER_IONCE

class Well;
namespace sf {
  class RenderWindow;
  class Drawable;
  class RectangleShape;
};

/**
 * Renderer class holds all view objects (sptes, texts, etc.)
 * and translates game state to actual images on screen
 **/
class Renderer {
  std::vector<sf::RectangleShape> racts;
public:
  void renderWell(const Well &well, sf::RenderWindow &window);
};

#endif
