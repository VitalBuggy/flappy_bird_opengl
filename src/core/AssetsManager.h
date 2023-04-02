#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>

class AssetsManager
{
public:
    // Texture functions
    void loadTexture(const std::string &name, const std::string &fileName);
    sf::Texture &getTexture(const std::string &name);

    // Font functions
    void loadFont(const std::string &name, const std::string &fileName);
    sf::Font &getFont(const std::string &name);

    // Sound functions
    void loadSound(const std::string &name, const std::string &fileName);
    sf::SoundBuffer &getSound(const std::string &name);

private:
    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, sf::Font> fonts;
    std::unordered_map<std::string, sf::SoundBuffer> sounds;
};

#endif // ASSETS_MANAGER_H
