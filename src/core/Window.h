#ifndef WINDOW_H
#define WINDOW_H

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Window {
public:
    Window(unsigned int width, unsigned int height, const std::string& title);

    void draw(const sf::Drawable& drawable);
    void display();
    bool isOpen();
    float getDeltaTime();
    void close();

    sf::RenderWindow& getWindow();

private:
    sf::RenderWindow game_window;
    sf::Clock clock;
};


#endif // WINDOW_H
