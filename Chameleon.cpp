#include "Chameleon.hpp"
#include "Resources.hpp"

Chameleon::Chameleon() {}

Chameleon::Chameleon(sf::Vector2f pos) {

    licking = false;
    sprite.setTexture(Resources::chameleon);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    sprite.setPosition(pos);

    tongue.setOrig(pos);


    std::cout << "chamaleon" << std::endl;
}

void Chameleon::update(float deltaTime, sf::Vector2f playerPos) {
    if (licking) {
        tongue.setDest(playerPos);
        tongue.update(deltaTime);
    }
    sprite.setRotation(getAngle(sprite.getPosition(),playerPos));
}

void Chameleon::draw(sf::RenderWindow& window) {
    if (licking) tongue.draw(window);
    //window.draw(sprite);
}

void Chameleon::lick() {
    if (!licking) {
        licking = true;
        tongue.reset();
    }
}

void Chameleon::release() {
    licking = false;
}

sf::Vector2f Chameleon::getPosition() {
    return sprite.getPosition();
}



