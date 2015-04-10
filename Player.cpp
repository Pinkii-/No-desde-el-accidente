#include "Player.hpp"
#include "Resources.hpp"

Player::Player() {}

Player::Player(sf::Vector2f pos, sf::Vector2f speed) :
    pos(pos), speed(speed){
    sprite.setTexture(Resources::ship);
    //angle = AngleHelper::speedToAngle(speed);
}

void Player::update(float deltaTime) {
    pos += speed*deltaTime;
    sprite.setPosition(pos);
}

void Player::draw(sf::RenderWindow *window) {
    sprite.setRotation(angle);
    window->draw(sprite);
}
