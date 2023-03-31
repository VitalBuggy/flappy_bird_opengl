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
    void close();

    sf::RenderWindow& getWindow();

private:
    sf::RenderWindow game_window;
};


#endif // WINDOW_H