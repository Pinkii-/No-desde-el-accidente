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
    bool isAlive();

    //Setters
    void setSpeed(sf::Vector2f newSpeed);
    void setPosition(sf::Vector2f newPos);
    void setLicked(bool b, sf::Vector2f cPos, int tipofuerza);
    void setAlive(bool b);

    sf::CircleShape getBox();


private:
    //Player properties
    sf::Sound expl;
    sf::Vector2f pos;
    sf::Sprite sprite;
    sf::Vector2f speed;


    float angle;
    float spriteTimer;
    float spriteWidth;
    float spriteHeight;
    float spriteAnimation;
    float timeSinceNextSprite;
  int tipofuerza;
    // Camaleon related things
    bool licked;
    bool tensioning;
    float timeSinceTriggered;
    sf::Vector2f camaleonPos;

    void evoluciona(float fdelta);

    double fuerza(double distancia);
    void evolucionabis(float fdelta);

    // Comido
    bool alive;
};

#endif // PLAYER_HPP
