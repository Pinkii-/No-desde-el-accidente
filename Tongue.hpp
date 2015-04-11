#ifndef TONGUE_HPP
#define TONGUE_HPP
#include "utils.hpp"

class Tongue{

public:
    Tongue();

    //Getters
    sf::Vector2f getOrig() const;
    sf::Vector2f getDest() const;

    //Setters
    void reset();//Basicaly sets time to 0 ;
    void setOrig(const sf::Vector2f &value);
    void setDest(const sf::Vector2f value);

    //Game Functions
    void update(float deltatime);
    void draw(sf::RenderWindow& window);

    //Utility Functions
    float getAngle(sf::Vector2f &orig, sf::Vector2f &des);
    float getModule(const sf::Vector2f &orig, const sf::Vector2f &des);

private:

    //Positions
    sf::Vector2f orig;
    sf::Vector2f dest;

    //Images
    sf::Sprite sprite;
    sf::Texture texture;

    //Variables
    float size;
    float angle;
    float timeSinceTriggered;


};

#endif // TONGUE_HPP
