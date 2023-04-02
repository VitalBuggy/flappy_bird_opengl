#ifndef GAME_H
#define GAME_H 

#include <SFML/Graphics.hpp>
#include "../game/Bird.h"
#include "window.h"

class Game {
  public:
    Game();
    void run();

  private:
    void process_events();
    void update();
    void draw();
    Window* window;
    Bird *bird;
};

#endif // GAME_H
