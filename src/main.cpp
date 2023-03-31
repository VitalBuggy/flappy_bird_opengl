#include <SFML/Graphics.hpp>
#include <iostream>
#include "core/window.h"

int main() {
  Window window(800, 600, "SFML Bird");

  while (window.isOpen()) {
    sf::Event event;

    while (window.getWindow().pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.getWindow().clear();

    window.display();
  }
  return 0;
}
