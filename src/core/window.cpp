#ifndef WINDOW_CPP
#define WINDOW_CPP

#include "window.h"
#include <SFML/Graphics.hpp>

Window::Window(unsigned int width, unsigned int height, const std::string& title) {
    game_window.create(sf::VideoMode(width, height), title);

    game_window.setFramerateLimit(60);
}

void Window::draw(const sf::Drawable& drawable) {
    game_window.draw(drawable);
}

void Window::display() {
    game_window.display();
}

bool Window::isOpen() {
    return game_window.isOpen();
}

void Window::close() {
    game_window.close();
}

sf::RenderWindow& Window::getWindow() {
    return game_window;
}

#endif // WINDOW_CPP