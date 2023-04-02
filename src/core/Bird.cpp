#ifndef BIRD_CPP
#define BIRD_CPP

#include "Bird.h"

Bird::Bird(sf::RenderWindow &window, float x, float y, float gravity,
           float jump_speed, sf::Texture &texture)
    : game_window(window),
      alive(true),
      y_velocity(0.f),
      gravity(gravity),
      jump_speed(jump_speed) {
  bird_sprite.setTexture(texture);
  bird_sprite.setPosition(x, y);
  bird_sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
  bird_sprite.setScale(1.5f, 1.5f);
}

void Bird::update(float dt) {
  float new_y =
      bird_sprite.getPosition().y + y_velocity * dt + 0.5f * gravity * dt * dt;
  y_velocity += gravity * dt;

  if (new_y < 0.f ||
      new_y + bird_sprite.getGlobalBounds().height > game_window.getSize().y) {
    alive = false;
  }

  bird_sprite.setPosition(bird_sprite.getPosition().x, new_y);
}

void Bird::jump() { y_velocity = -jump_speed; }

bool Bird::is_alive() const { return alive; }

void Bird::set_alive(bool alive) { this->alive = alive; }

sf::FloatRect Bird::get_bounds() const { return bird_sprite.getGlobalBounds(); }

void Bird::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(bird_sprite, states);
}

const sf::Drawable &Bird::getDrawable() const { return bird_sprite; }

#endif  // BIRD_CPP
