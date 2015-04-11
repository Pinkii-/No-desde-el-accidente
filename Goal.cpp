#include "Goal.hpp"

Goal::Goal(){
    reached = false;
    timeBetweenAnimations = 0.2;
    timeSinceLastAnimaiton = 0.0;

    if(!texture.loadFromFile("res/goal.png")) std::cout << "goal texture not loaded" << std::endl;
    sprite.setTexture(texture);
    sprite.setScale(50/sprite.getLocalBounds().width, 50/sprite.getLocalBounds().height);

}

void Goal::update(float deltatime) {
    timeSinceLastAnimaiton += deltatime;
    if(timeSinceLastAnimaiton >= timeBetweenAnimations){
        //++anim
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

void Goal::setPosition(const sf::Vector2f &value) {
    position = value;
}

void Goal::setPosition(float valueX, float valueY){
    setPosition(sf::Vector2f(valueX, valueY));
}

