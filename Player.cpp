#include "Player.hpp"
#include "Resources.hpp"

Player::Player() {}

Player::Player(sf::Vector2f pos, sf::Vector2f speed) :
    pos(pos), speed(speed){
    sprite.setTexture(Resources::ship);
    //angle = AngleHelper::speedToAngle(speed);
}

void Player::update(float deltaTime) {
    evoluciona(deltaTime);
    sprite.setPosition(pos);
}

void Player::draw(sf::RenderWindow *window) {
    sprite.setRotation(angle);
    window->draw(sprite);
}

//Private functions

void Player::evoluciona(float fdelta)
{
  double delta=fdelta;
  point p=vector2point(pos);
  point v=vector2point(speed);
  point c=vector2point(camaleonPos);
  if (not licked) {
    p+=v*delta;
    pos=point2vector(p);
    return;
  }
  if (not tensioning) {
    p+=v*delta;
    pos=point2vector(p);
    if (prodesc(v,p-c)>=0)
      tensioning=true;
    return;
  }
  p-=c;
  double modulov=abs(v);
  double desp=modulov*delta;
  double r=abs(p);
  double alfa=desp/r;
  int signo=prodvec(p,v)>0?1:-1;
  p*=std::polar(1.0,signo*alfa);
  v=p*std::polar(1.0,signo*M_PI/2.0);
  v=(modulov/abs(v))*v;
  p+=c;
  pos=point2vector(p);
  speed=point2vector(v);
}
