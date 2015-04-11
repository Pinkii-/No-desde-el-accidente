#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "utils.hpp"
#include "Resources.hpp"

class Background {
public:
    Background(sf::RenderWindow &window);
    void update(float deltaTime);
    void draw(sf::RenderWindow & window);
private:
    sf::Sprite sprite;

    int qttyAnimations;
    int actualAnimation;
    int width;
    int height;
    float animationWidth;
    float animationHeight;
    float timeBetweenAnimations;
    float timeSinceLastAnimation;
};

#endif // BACKGROUND_HPP
