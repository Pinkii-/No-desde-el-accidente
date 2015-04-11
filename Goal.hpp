#ifndef GOAL_HPP
#define GOAL_HPP
#include "utils.hpp"

class Goal {


public:
    //Creadora
    Goal();

    //Game Functions
    void update(float deltatime);
    void draw(sf::RenderWindow &window);

    //Getters
    sf::Vector2f getPosition() const;

    //Setters
    void setPosition(const sf::Vector2f &value);
    void setPosition(float valueX, float valueY);

private:

    bool  reached;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;

    int qttyAnimations;
    int actualAnimation;
    float animationSize;
    float timeBetweenAnimations;
    float timeSinceLastAnimaiton;


};

#endif // GOAL_HPP
