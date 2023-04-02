#ifndef ASSETS_MANAGER_CPP
#define ASSETS_MANAGER_CPP

#include "AssetsManager.h"
#include <iostream>

void AssetsManager::loadTexture(const std::string &name, const std::string &fileName)
{
    sf::Texture texture;
    if (!texture.loadFromFile(fileName))
    {
        // handle error loading file
        std::cerr << "Error occured while loading texture " << name << std::endl;
    }
    textures[name] = texture;
}

sf::Texture &AssetsManager::getTexture(const std::string &name)
{
    return textures.at(name);
}

void AssetsManager::loadFont(const std::string &name, const std::string &fileName)
{
    sf::Font font;
    if (!font.loadFromFile(fileName))
    {
        std::cerr << "Error occured while loading font " << name << std::endl;
    }
    fonts[name] = font;
}

sf::Font &AssetsManager::getFont(const std::string &name)
{
    return fonts.at(name);
}

void AssetsManager::loadSound(const std::string &name, const std::string &fileName)
{
    sf::SoundBuffer soundBuffer;
    if (!soundBuffer.loadFromFile(fileName))
    {
        std::cerr << "Error occured while loading sound " << name << std::endl;
    }
    sounds[name] = soundBuffer;
}

sf::SoundBuffer &AssetsManager::getSound(const std::string &name)
{
    return sounds.at(name);
}

#endif // ASSETS_MANAGER_CPP