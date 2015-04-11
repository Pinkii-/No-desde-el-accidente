#include "Background.hpp"

Background::Background(sf::RenderWindow &window) {
    sprite.setTexture(Resources::background);
    width = 4;
    height = 1;
    actualAnimation = 0;
    timeBetweenAnimations = 1;
    timeSinceLastAnimation = 0.0;

    animationWidth = sprite.getGlobalBounds().width/width;
    animationHeight = sprite.getGlobalBounds().height/height;

    if(window.getSize().y/animationHeight < window.getSize().x/animationWidth)
        sprite.scale(window.getSize().y/animationHeight,window.getSize().y/animationHeight);
    else
        sprite.scale(window.getSize().x/animationWidth,window.getSize().x/animationWidth);

    sprite.setOrigin(sf::Vector2f(animationWidth/2, animationHeight/2));
    sprite.setPosition(window.getSize().x/2, window.getSize().y/2.0);

}

void Background::update(float deltaTime) {
    timeSinceLastAnimation += deltaTime;
    if(timeSinceLastAnimation >= timeBetweenAnimations){
        actualAnimation = (actualAnimation + 1)%width;
        timeSinceLastAnimation = 0.0;
    }
}

void Background::draw(sf::RenderWindow &window) {
    sprite.setTextureRect(sf::IntRect((actualAnimation%width)*animationWidth, (actualAnimation/width)*animationHeight, animationWidth, animationHeight));
    window.draw(sprite);
}
