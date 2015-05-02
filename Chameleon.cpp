#include "Chameleon.hpp"
#include "Resources.hpp"

Chameleon::Chameleon() {}

Chameleon::Chameleon(sf::Vector2f pos) {

    radius = 30; // Elegir el radio segund algo(?)

    licking = false;
    sprite.setRadius(radius);
    sprite.setTexture(&Resources::chameleon);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    sprite.setPosition(pos);

    tongue.setOrig(pos);
    tongue.setFatherRadius(radius);


    //std::cout << "chamaleon" << std::endl;
}

void Chameleon::update(float deltaTime, sf::Vector2f playerPos) {
    if (licking) {
        tongue.setDest(playerPos);
        tongue.update(deltaTime);
    }
    sprite.setRotation(getAngle(sprite.getPosition(),playerPos)+90);
}

void Chameleon::draw(sf::RenderWindow& window) {
    window.draw(sprite);
    if (licking) tongue.draw(window);
}

void Chameleon::lick() {
    if (!licking) {
        sprite.setTexture(&Resources::chameleon2);
        licking = true;
        tongue.reset();
    }
}

void Chameleon::release() {
    if (licking) {
        sprite.setTexture(&Resources::chameleon);
        licking = false;
    }
}

void Chameleon::eating() {
    sprite.setTexture(&Resources::chameleon3);
}

sf::Vector2f Chameleon::getPosition() {
    return sprite.getPosition();
}

float Chameleon::getRadius() {
    return radius;
}



