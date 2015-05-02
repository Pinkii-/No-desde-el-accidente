#ifndef CHAMELEON_HPP
#define CHAMELEON_HPP

#include "utils.hpp"
#include "Tongue.hpp"

class Chameleon {
public:
    Chameleon();
    Chameleon(sf::Vector2f pos, int tipoFuerza);
    void update(float deltaTime, sf::Vector2f playerPos);
    void draw(sf::RenderWindow &window);

    void lick();
    void release();
    void eating();

    sf::Vector2f getPosition();
    float getRadius();
    int getType();
private:
    sf::CircleShape sprite;
    Tongue tongue;
    float angle;
    bool licking;
    float radius;
    int tipoFuerza;
};

#endif // CHAMELEON_HPP
