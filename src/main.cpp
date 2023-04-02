#include <SFML/Graphics.hpp>
#include <iostream>

#include "core/AssetsManager.h"
#include "core/Bird.h"
#include "core/Window.h"

int main() {
  Window window(800, 600, "SFML Bird");
  AssetsManager assetsManager;

  assetsManager.loadTexture("bird", "/Users/aleksandrustic/Desktop/Git/flappy_bird_sfml/src/assets/sprites/bluebird-midflap.png");
  sf::Texture& bird_texture = assetsManager.getTexture("bird");
  
  Bird Flappy_Bird(window.getWindow(), 100.0f, 100.0f, 1.0f, 20.0f, bird_texture);
  float jumpTime = 0.0f;

  while (window.isOpen()) {
    sf::Event event;

    while (window.getWindow().pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      else if (event.type == sf::Event::KeyPressed &&
               event.key.code == sf::Keyboard::Space) {
        Flappy_Bird.jump();
        jumpTime = window.getDeltaTime();
      }
    }

    Flappy_Bird.update(window.getDeltaTime() - jumpTime);

    window.getWindow().clear(sf::Color::White);

    if (Flappy_Bird.is_alive()) {
      window.draw(Flappy_Bird.getDrawable());
    } else {
      std::cout << "Game Over!" << std::endl;
      window.close();
    }

    window.display();
  }
  return 0;
}
