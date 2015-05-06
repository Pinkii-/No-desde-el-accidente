#include "Obstacle.hpp"
#include "Resources.hpp"

Obstacle::Obstacle(){}

Obstacle::Obstacle(sf::Vector2f pos) {
  radius = 30;
  sprite.setRadius(radius);
  sprite.setTexture(&Resources::obstacle);
  sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
  sprite.setPosition(pos);


  nSprites = 1; // Numero de Sprites
  angle = 0; // Angulo de rotacion
  spriteTimer = 0;
  spriteWidth = sprite.getLocalBounds().width;
  spriteHeight = sprite.getLocalBounds().height;
  timeSinceNextSprite = 100000;
}

void Obstacle::update(float deltaTime) {
  spriteTimer += deltaTime;
  if(spriteTimer >= timeSinceNextSprite){
      ++spriteAnimation;
      spriteAnimation = (int)spriteAnimation % nSprites;
      sprite.setTextureRect(sf::IntRect(spriteAnimation*spriteWidth, 0, spriteWidth, spriteHeight));
  }
}

void Obstacle::draw(sf::RenderWindow &window) {
  window.draw(sprite);
}

float Obstacle::getRadius() {
  return radius;
}

sf::Vector2f Obstacle::getPosition() {
  return sprite.getPosition();
}

void Obstacle::setPosition(sf::Vector2f pos) {
  sprite.setPosition(pos);
}

