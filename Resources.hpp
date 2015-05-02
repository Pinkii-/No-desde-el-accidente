#ifndef RESOURCES_HPP
#define RESOURCES_HPP
#include "utils.hpp"

class Resources {
public:
    static void load();
    static sf::Texture ship;
    static sf::Texture chameleon;
    static sf::Texture chameleon2;
    static sf::Texture chameleon3;
    static sf::Texture tongue;
    static sf::Texture goal;
    static sf::Texture background;

    static sf::Texture obstacle;

    static sf::Font font;
    static sf::SoundBuffer buffer;
    static sf::SoundBuffer expbuf;
    static sf::Music music;
};

#endif // RESOURCES_HPP
