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
    void setLicked(bool b, sf::Vector2f cPos);

private:
    //Player properties
    sf::Vector2f pos;
    sf::Sprite sprite;
    sf::Vector2f speed;

    float angle;
    float spriteTimer;
    float spriteWidth;
    float spriteHeight;
    float spriteAnimation;
    float timeSinceNextSprite;

    // Camaleon related things
    float timeSinceTriggered;
    bool licked;
    bool tensioning;
    sf::Vector2f camaleonPos;

    void evoluciona(float fdelta);
};

#endif // PLAYER_HPP
