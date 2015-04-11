#include "Resources.hpp"

sf::Texture     Resources::ship;
sf::Texture     Resources::chameleon;
sf::Texture     Resources::tongue;
sf::Texture     Resources::goal;

sf::Font        Resources::font;
sf::SoundBuffer Resources::sound;
sf::Music       Resources::music;

void Resources::load() {
    ship.loadFromFile("res/ship.png");
    chameleon.loadFromFile("res/chameleon.png");
    tongue.loadFromFile("res/tongue.png");
    goal.loadFromFile("res/tongue2.png");
    /*
    font.loadFromFile("resources/font.ttf");
    sound.loadFromFile("resources/sound.wav"); //sound must be a short audio
    music.openFromFile("resources/music.ogg"); //Im not sure if this a good way to do that :/ */
}
