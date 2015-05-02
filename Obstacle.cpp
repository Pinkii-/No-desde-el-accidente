#include "Obstacle.hpp"
#include "Resources.hpp"

Obstacle::Obstacle(){}

Obstacle::Obstacle(sf::Vector2f pos) {
  sprite.setRadius(30);
  sprite.setTexture(&Resources::obstacle);
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

