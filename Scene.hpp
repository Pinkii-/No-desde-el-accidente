#ifndef SCENE_H
#define SCENE_H
#include "Goal.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Chameleon.hpp"

class Scene : public Game {
public:

    Scene(sf::RenderWindow *w);

    ~Scene();

    void draw();
    void processEvents();
    void update(float deltaTime);

private:
    Goal goal;
    Player player;
    Chameleon *currentChameleon;
    std::vector<Chameleon> chameleons;

    void releaseChameleon();
    void activeChameleon(sf::Vector2f pos);
};

#endif // SCENE_H
