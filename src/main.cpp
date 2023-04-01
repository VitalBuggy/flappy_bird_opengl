#include <SFML/Graphics.hpp>
#include <iostream>
#include "core/window.h"
#include "game/Bird.h"

int main()
{
  Window window(800, 600, "SFML Bird");
  Bird Flappy_Bird(window.getWindow(), 100.0f, 100.0f, 3.0f, 20.0f);

  while (window.isOpen())
  {
    sf::Event event;

    while (window.getWindow().pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
      {
        Flappy_Bird.jump();
      }
    }

    Flappy_Bird.update(window.getDeltaTime());

    window.getWindow().clear(sf::Color::White);

    window.draw(Flappy_Bird.getDrawable());

    window.display();
  }
  return 0;
}
