#ifndef SCENE_H
#define SCENE_H
#include "Goal.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Chameleon.hpp"

class Scene : public Game {
public:

    Scene(sf::RenderWindow *w, std::string path);

    ~Scene();

    void draw();
    void processEvents();
    bool update(float deltaTime);

    bool getSuccess() const;
private:
    Goal goal;
    Player player;
    Chameleon *currentChameleon;
    std::vector<Chameleon> chameleons;

    // lvl aids
    bool finishLvl; // Said if the level has finish (restart or go to the next lvl, menu, etc);
    bool success; // if you have pass the lvl or not

    void releaseChameleon();
    void activeChameleon(sf::Vector2f pos);
    void lookCollisions();
};

#endif // SCENE_H
