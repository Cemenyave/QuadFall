#include "game.h"
#include "defines.h"
#include "keyboardHandler.h"


Game * game = NULL;
void init_game() {
  game = new Game();
}


void terminate_game() {
  if ( game != NULL ) {
    delete game;
  }
  game = NULL;
}


Game::Game()
{
  controller.init();
  window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_CAPTION);
}


void Game::setKeyboardHandler(IKeyboardInputHandler * kbd_handler) {
  kbdHandler = kbd_handler;
}


void Game::run() {
  while (window.isOpen()) {
    endLastScene();
    registerNewScenes();
    update();
    render();
  }
}


void Game::startScene(t_scenePointer scene) {
  sceneStackSuspended.push(scene);
}


void Game::registerNewScenes() {
  while (!sceneStackSuspended.empty()) {
    if (sceneStack.size()) {
      sceneStack.back()->pause();
    }
    sceneStack.push_back(sceneStackSuspended.front());
    sceneStackSuspended.pop();
  }
}


void Game::requestEndScene() {
  endScene = true;
}


void Game::endLastScene() {
  if (!endScene) {
    return;
  }

  if (sceneStack.size()) {
    delete sceneStack.back();
    sceneStack.pop_back();
  }

  if (sceneStack.size()) {
    sceneStack.back()->resume();
  }

  endScene = false;
}


void Game::update() {
  sf::Event e;
  while (window.pollEvent(e)) {
    switch (e.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyPressed:
        if (kbdHandler) {
          KeyModifier mod = 0;
          mod |= e.key.alt ? ALT : 0;
          mod |= e.key.control ? CONTROL : 0;
          mod |= e.key.shift ? SHIFT : 0;
          mod |= e.key.system ? SYSTEM : 0;
          kbdHandler->onKeyPressed(e.key.code, mod);
        }
        break;
      case sf::Event::KeyReleased:
        if (kbdHandler) {
          KeyModifier mod = 0;
          mod |= e.key.alt ? ALT : 0;
          mod |= e.key.control ? CONTROL : 0;
          mod |= e.key.shift ? SHIFT : 0;
          mod |= e.key.system ? SYSTEM : 0;
          kbdHandler->onKeyRelease(e.key.code, mod);
        }
        break;
      default:
        break;
    }
  }

  sf::Time dt = actClock.restart();
  for (t_sceneStack::iterator i = sceneStack.begin(); i != sceneStack.end(); ++i) {
    (*i)->update(dt.asSeconds());
  }
}


void Game::render() {
  window.clear(sf::Color::Black);
  for (t_sceneStack::iterator i = sceneStack.begin(); i != sceneStack.end(); ++i) {
    (*i)->render(window);
  }
  window.display();
}
