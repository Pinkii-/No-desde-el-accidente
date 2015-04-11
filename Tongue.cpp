#include "Tongue.hpp"
#include "Resources.hpp"

Tongue::Tongue(){
    angle = 0;
    size = 10; //HARDCODED ALERT it will be the width of the tongue
    timeSinceTriggered = 0;
    texture = Resources::tongue;
    dest = sf::Vector2f(600,600);
    sprite.setTexture(Resources::tongue);
}

void Tongue::reset(){
    timeSinceTriggered = 0;
}

sf::Vector2f Tongue::getOrig() const {
    return orig;
}

void Tongue::setOrig(const sf::Vector2f &value) {
    orig = value;
}

sf::Vector2f Tongue::getDest() const {
    return dest;
}

void Tongue::setDest(const sf::Vector2f value) {
    dest = value;
}

void Tongue::update(float deltatime) {
    if(timeSinceTriggered < animationTime) timeSinceTriggered += deltatime;
}

float Tongue::getAngle(sf::Vector2f &orig, sf::Vector2f &des) {
    return std::atan2(des.y - orig.y, des.x - orig.x)*180/(M_PI);
}

float Tongue::getModule(const sf::Vector2f &orig, const sf::Vector2f &des) {
    return std::sqrt(std::pow(std::abs(des.x-orig.x), 2) + std::pow(std::abs(des.y-orig.y), 2));
}

void Tongue::draw(sf::RenderWindow &window) {

    float tongueLength = (getModule(orig,dest)/sprite.getLocalBounds().width);
    float tongueWidth = size/sprite.getLocalBounds().height;
    if(timeSinceTriggered < animationTime) {
        sprite.setScale( tongueLength * timeSinceTriggered/animationTime,
                                                                tongueWidth);
    }
    else sprite.setScale(tongueLength, tongueWidth);

    sprite.setOrigin(0, sprite.getLocalBounds().height/2);
    sprite.setPosition(orig);
    sprite.setRotation(getAngle(orig,dest));
    window.draw(sprite);

}


