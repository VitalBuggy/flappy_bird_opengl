#ifndef WINDOW_CPP
#define WINDOW_CPP

#include "Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Window::Window(unsigned int width, unsigned int height, const std::string &title)
{
    game_window.create(sf::VideoMode(width, height), title);

    game_window.setFramerateLimit(60);
    clock.restart();
}

void Window::draw(const sf::Drawable &drawable)
{
    game_window.draw(drawable);
}

void Window::display()
{
    game_window.display();
}

bool Window::isOpen()
{
    return game_window.isOpen();
}

float Window::getDeltaTime()
{
    return clock.getElapsedTime().asSeconds();
}

void Window::close()
{
    game_window.close();
}

sf::RenderWindow &Window::getWindow()
{
    return game_window;
}

#endif // WINDOW_CPP