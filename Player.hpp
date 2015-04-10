#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "utils.hpp"

class Player {
public:
    Player();
    Player(sf::Vector2f pos, sf::Vector2f speed);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);

    sf::Vector2f getPosition();

private:
    float angle;
    sf::Vector2f pos;
    sf::Sprite sprite;
    sf::Vector2f speed;

    // Camaleon related things
    bool licked;
    bool tensioning;
    sf::Vector2f camaleonPos;

    void evoluciona(float fdelta);
};

#endif // PLAYER_HPP
