#ifndef BIRD_CPP
#define BIRD_CPP

#include "Bird.h"

Bird::Bird(sf::RenderWindow &window, float x, float y, float gravity, float jump_speed)
    : game_window(window), alive(true), y_velocity(0.f), gravity(gravity), jump_speed(jump_speed)
{
    bird_shape.setSize(sf::Vector2f(50.f, 50.f));
    bird_shape.setPosition(x, y);
    bird_shape.setFillColor(sf::Color::Red);
}

void Bird::update(float dt)
{
    float new_y = bird_shape.getPosition().y + y_velocity * dt + 0.5f * gravity * dt * dt;
    y_velocity += gravity * dt;

    if (new_y < 0.f || new_y + bird_shape.getSize().y > game_window.getSize().y)
    {
        alive = false;
    }

    bird_shape.setPosition(bird_shape.getPosition().x, new_y);
}

void Bird::jump()
{
    y_velocity = -jump_speed;
}

bool Bird::is_alive() const
{
    return alive;
}

void Bird::set_alive(bool alive)
{
    this->alive = alive;
}

sf::FloatRect Bird::get_bounds() const
{
    return bird_shape.getGlobalBounds();
}

void Bird::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(bird_shape, states);
}

const sf::Drawable &Bird::getDrawable() const
{
    return bird_shape;
}

#endif // BIRD_CPP