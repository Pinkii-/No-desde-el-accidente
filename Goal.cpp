#include "Goal.hpp"
#include "Resources.hpp"

Goal::Goal(){
    qttyAnimations = 1; //set here the qtty
    actualAnimation = 0;
    reached = false;
    timeBetweenAnimations = 0.2;
    timeSinceLastAnimaiton = 0.0;

    sprite.setTexture(Resources::goal);
    animationSize = sprite.getGlobalBounds().width/qttyAnimations;
    sprite.setScale(50/sprite.getLocalBounds().width, 50/sprite.getLocalBounds().height);

}

void Goal::update(float deltatime) {
    timeSinceLastAnimaiton += deltatime;
    if(timeSinceLastAnimaiton >= timeBetweenAnimations){
        actualAnimation = (actualAnimation + 1) % qttyAnimations;
        timeSinceLastAnimaiton = 0.0;
    }
}

void Goal::draw(sf::RenderWindow& window) {
    sprite.setPosition(position);
    window.draw(sprite);
}

sf::Vector2f Goal::getPosition() const {
    return position;
}

float Goal::getSize() const {
    return animationSize;
}

void Goal::setPosition(const sf::Vector2f &value) {
    position = value;
}

void Goal::setPosition(float valueX, float valueY){
    setPosition(sf::Vector2f(valueX, valueY));
}

