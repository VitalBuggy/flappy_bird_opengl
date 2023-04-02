#ifndef GAME_CPP
#define GAME_CPP

#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() {
  std::cout << "hit the constructor";
}

void Game::run() {
  // Run game loop
  while (this->window.isOpen()) {
    this->process_events();
    this->update();
    this->draw();
  }
}

void Game::process_events() {
  sf::Event event;
  while (window.pollEvent(event)) {
  if (event.type == sf::Event::Closed)
    this->window.close();
  }
}

void Game::update() {

  
}

void Game::draw() {
  this->window.clear();
  this->window.display();
}

#endif // GAME_CPP
