#ifndef GAME_CPP
#define GAME_CPP

#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() {
  this->window = new Window(800, 600, "Flappy Bird");
  this->bird = new Bird(this->window->getWindow(), 100.0f, 100.0f, 3.0f, 20.f);
}

void Game::run() {
  // Run game loop
  while (this->window->isOpen()) {
    this->process_events();
    this->update();
    this->draw();
  }
}

void Game::process_events() {
  sf::Event event;
  while (window->getWindow().pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      this->window->close();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
      this->bird->jump();
    }
  }
}

void Game::update() {
  this->bird->update(this->window->getDeltaTime());
}

void Game::draw() {
  this->window->getWindow().clear(sf::Color::White);
  this->window->draw(this->bird->getDrawable());
  this->window->display();
}

#endif // GAME_CPP
