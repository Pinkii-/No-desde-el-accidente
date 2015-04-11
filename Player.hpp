#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "utils.hpp"

class Player {
public:

    //Creadores
    Player();
    Player(sf::Vector2f pos, sf::Vector2f speed);

    //Game Functions
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);

    //Getters
    sf::Vector2f getPosition();

    //Setters
    void setSpeed(sf::Vector2f newSpeed);
    void setPosition(sf::Vector2f newPos);
    void setLicked(bool b, sf::Vector2f cPos);

    sf::CircleShape getBox();

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
    bool licked;
    bool tensioning;
    float timeSinceTriggered;
    sf::Vector2f camaleonPos;

    void evoluciona(float fdelta);
};

#endif // PLAYER_HPP
