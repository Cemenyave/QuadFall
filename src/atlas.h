#ifndef _ATLAS_IONCE
#define _ATLAS_IONCE


#include <SFML/Graphics/Texture.hpp>

//SFML Texture cannot be instantiated as static variable
//or inside static class instance.
//So, to avoid this, we need Atlas class, which will
//be instantiated on stack

class Atlas {
public:
  Atlas();
  sf::Texture& getTexture();
  const sf::Texture& getBackground() const;

  private:
    sf::Texture atlas;
    sf::Texture background;
};

#endif
