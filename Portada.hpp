#ifndef PORTADA_H
#define PORTADA_H

#include "utils.hpp"

class Portada {

private:
    sf::Sprite s;
    sf::Texture t;
//    sf::Button b;
    bool open;

    int qttyAnimations;
    int actualAnimation;
    float animationSize;
    float timeBetweenAnimations;
    float timeSinceLastAnimaiton;

public:
    Portada();
    ~Portada();
    void display(sf::RenderWindow* window);
    void display(sf::RenderWindow* window, std::string pathImage);


};

#endif // PORTADA_H
