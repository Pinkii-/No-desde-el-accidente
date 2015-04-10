#ifndef CHAMELEON_HPP
#define CHAMELEON_HPP

#include "utils.hpp"
#include "Tongue.hpp"

class Chameleon {
public:
    Chameleon();
    Chameleon(sf::Vector2f pos);
    void update(float deltaTime, sf::Vector2f playerPos);
    void draw(sf::RenderWindow &window);
private:
    sf::Sprite sprite;
    Tongue tongue;
    float angle;
    bool licking;
};

#endif // CHAMELEON_HPP
