#ifndef SCENE_H
#define SCENE_H
#include "Goal.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Chameleon.hpp"
#include "IngameMenu.hpp"
#include "readlevels.hpp"

class Scene : public Game {
public:

    Scene(sf::RenderWindow *w, Level lvl);

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
    float timeFromDeath;
    bool finishLvl; // Said if the level has finish (restart or go to the next lvl, menu, etc);
    bool success; // if you have pass the lvl or not
    IngameMenu iMenu;
    bool menuIsActive;

    void releaseChameleon();
    void activeChameleon(sf::Vector2f pos);
    void lookCollisions();
};

#endif // SCENE_H
