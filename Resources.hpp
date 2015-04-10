#ifndef RESOURCES_HPP
#define RESOURCES_HPP
#include "utils.hpp"

class Resources {
public:
    static void load();
    static sf::Texture texture;
    static sf::Font font;
    static sf::SoundBuffer sound;
    static sf::Music music;
};

#endif // RESOURCES_HPP
