#include "Goal.hpp"
#include "Resources.hpp"

Goal::Goal(){
    qttyAnimations = 1; //set here the qtty
    actualAnimation = 0;
    reached = false;
    timeBetweenAnimations = 0.2;
    timeSinceLastAnimaiton = 0.0;

    size = 100;

    sprite.setTexture(Resources::goal);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    animationSize = sprite.getGlobalBounds().width/qttyAnimations;
    sprite.setScale(size/sprite.getLocalBounds().width, size/sprite.getLocalBounds().height);

}

void Goal::update(float deltatime, sf::Vector2f playerPos) {
    timeSinceLastAnimaiton += deltatime;
    if(timeSinceLastAnimaiton >= timeBetweenAnimations){
        actualAnimation = (actualAnimation + 1) % qttyAnimations;
        timeSinceLastAnimaiton = 0.0;
    }
    sprite.setRotation(getAngle(sprite.getPosition(),playerPos)+180);
}

void Goal::draw(sf::RenderWindow& window) {
    sprite.setPosition(position);
    window.draw(sprite);
}

sf::Vector2f Goal::getPosition() const {
    return position;
}

float Goal::getSize() const {
    return size;
}

void Goal::setPosition(const sf::Vector2f &value) {
    position = value;
}

void Goal::setPosition(float valueX, float valueY){
    setPosition(sf::Vector2f(valueX, valueY));
}

