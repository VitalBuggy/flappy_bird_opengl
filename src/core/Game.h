#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
  public:
    Game();
    void run();

  private:
    void process_events();
    void update();
    void draw();
    sf::RenderWindow window;
};

#endif // GAME_H
