#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>

class Bird {
 public:
  Bird(sf::RenderWindow &window, float x, float y, float gravity,
       float jump_speed, sf::Texture &texture);

  void update(float dt);
  void jump();

  bool is_alive() const;
  void set_alive(bool alive);

  sf::FloatRect get_bounds() const;
  const sf::Drawable &getDrawable() const;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

 private:
  sf::Sprite bird_sprite;
  sf::RenderWindow &game_window;

  bool alive;
  float y_velocity;
  float gravity;
  float jump_speed;
};

#endif  // BIRD_H