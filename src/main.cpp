#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
  sf::RenderWindow window(sf::VideoMode(800, 600), "QuadFall");

  sf::Clock actClock;
  sf::Time gameTurnTime = sf::seconds(1.0f);
  sf::Time timeFromLastTurn = sf::microseconds(0);

  sf::RectangleShape rect(sf::Vector2f(50, 50));
  rect.setFillColor(sf::Color::Green);
  rect.setPosition(375, 0);

  while (window.isOpen()) {
    sf::Event Event;
    while (window.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed)
        window.close();

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rect.move(-50, 0);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rect.move(50, 0);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rect.move(0, 50);
      }
    }

    timeFromLastTurn += actClock.restart();

    if (timeFromLastTurn > gameTurnTime) {
      timeFromLastTurn = sf::microseconds(0);
      if (rect.getSize().y + rect.getPosition().y <= 550) {
        rect.move(0, 50);
      } else {
        rect.setPosition(375, 0);
      }
    }

    window.clear(sf::Color::Black);
    window.draw(rect);
    window.display();
  }

  return 0;
}
