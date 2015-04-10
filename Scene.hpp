#ifndef SCENE_H
#define SCENE_H
#include "Game.hpp"

class Scene : public Game {
public:
    Scene(int scrwidth, int scrheight, std::string title, int style);
    ~Scene();
    void update(float deltaTime);
    void draw();
    void processEvents();
private:
    //The components of the game
};

#endif // SCENE_H
